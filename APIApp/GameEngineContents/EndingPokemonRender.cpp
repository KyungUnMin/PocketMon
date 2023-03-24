#include "EndingPokemonRender.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

EndingPokemonRender::EndingPokemonRender()
{
}

EndingPokemonRender::~EndingPokemonRender()
{
}

void EndingPokemonRender::PlayAnim(const std::string_view& _ImageName)
{
	PokemonRender->SetImage(_ImageName);
	Progress = 0.0f;
	PokemonRender->SetAlpha(0);
	PokemonRender->SetFrame(0);
	Alpha = 255;
}

void EndingPokemonRender::Start()
{
	PokemonRender = CreateRender("EndingPokemon001.bmp", RenderOrder::EndingFront);
	PokemonRender->SetScale(float4(420, 420));
	PokemonRender->EffectCameraOff();
	PokemonRender->SetAlpha(0);
	PokemonRender->SetFrame(0);
}

void EndingPokemonRender::Update(float _DeltaTime)
{
	Progress += _DeltaTime * Speed;

	if (255 == Alpha)
	{
		PokemonRender->SetAlpha(static_cast<int>(GameEngineMath::Lerp(0, 1, Progress) * 255));
	}
	else
	{
		PokemonRender->SetAlpha(Alpha);
	}

	if (4.0f <= Progress)
	{
		PokemonRender->SetFrame(1);
	}
}
