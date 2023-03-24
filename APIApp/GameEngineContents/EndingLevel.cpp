#include "EndingLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>
#include "BackgroundUI.h"
#include "EndingPokeballBackground.h"
#include "EndingPokemonRender.h"
#include "EndingFade.h"
#include "EndingTextActor.h"


EndingPokeballBackground::PokeColor EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Green;
std::string EndingLevel::PokemonRenderImageName = "EndingPokemon002.bmp";
bool EndingLevel::LastEffect = false;

EndingLevel::EndingLevel()
{
}

EndingLevel::~EndingLevel()
{
}

void EndingLevel::Loading()
{
	float4 WindowSize = GameEngineWindow::GetScreenSize();
	float4 WindowSizeHalf = WindowSize.half();

	CreateActor<BackgroundUI>();
	PokeBackActor = CreateActor<EndingPokeballBackground>();
	PokeBackActor->SetPos(WindowSizeHalf);
	PokeBackActor->SetAnimSpeed(5.0f);
	PokeBackActor->Off();

	PokemonRender = CreateActor<EndingPokemonRender>();
	PokemonRender->SetPos(WindowSizeHalf);
	PokemonRender->SetAnimSpeed(2.5f);
	PokemonRender->Off();

	Fade = CreateActor<EndingFade>();
	Fade->SetPos(WindowSizeHalf);
	Fade->SetSpeed(2.0f);
	Fade->Off();

	LastLogo = CreateActor<EndingTextActor>();
	LastLogo->SetPos(WindowSizeHalf);
	LastLogo->Off();
}

void EndingLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	if (true == LastEffect)
	{
		Fade->SetProgress(1.0f);
		Fade->On();
		LastLogo->On();
		return;
	}

	PokemonRender->On();
	PokemonRender->PlayAnim(PokemonRenderImageName);

	Fade->SetProgress(0.0f);

	LevelEvent.AddEvent(1.8f, std::bind([](EndingLevel* _This) {
		_This->PokeBackActor->On();
		_This->PokeBackActor->PlayPokeballAnim(PokeballColor);
		}, this),
		false);

	LevelEvent.AddEvent(3.5f, std::bind([](EndingLevel* _This) {
		_This->Fade->On();
		}, this),
		false);

	LevelEvent.AddEvent(4.0f,
		std::bind([]()
		{
			GameEngineCore::GetInst()->ChangeLevel("FieldmapLevel");
		}),
		false);
}

void EndingLevel::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
	PokeBackActor->Off();
	PokemonRender->Off();
	Fade->Off();
}
