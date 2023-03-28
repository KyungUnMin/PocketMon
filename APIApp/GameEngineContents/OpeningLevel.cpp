#include "OpeningLevel.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTimeEvent.h>

#include "BlackBox.h"
#include "EffectBlackBox.h"
#include "Opening_Text.h"
#include "Logo_Charizard.h"
#include "Logo_Charizard_White.h"

OpeningLevel::OpeningLevel() 
{
}

OpeningLevel::~OpeningLevel() 
{
}

void OpeningLevel::Loading()
{
	float4 Winsize_h = GameEngineWindow::GetScreenSize().half();

	CreateActor<BlackBox>();

	EffectBox = CreateActor<EffectBlackBox>();
	EffectBox2 = CreateActor<EffectBlackBox>();
	EffectBox2->SetPos(Winsize_h + float4::Down * Winsize_h.y * 2 + float4::Down * 200);

	OpeningText = CreateActor<Opening_Text>();
	Zardlogo = CreateActor<Logo_Charizard>();
	Zardlogo_White = CreateActor<Logo_Charizard_White>();

	EffectBox->Off();
	EffectBox2->Off();
	Zardlogo->Off();
	Zardlogo_White->Off();
}
void OpeningLevel::Update(float _DeltaTime)
{
	LevelEvent.Update(_DeltaTime);
}

void OpeningLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	LevelEvent.AddEvent(2.f, std::bind([](OpeningLevel* _This)
		{
			_This->OpeningText->AlphaStart();
		}, this), false);

	LevelEvent.AddEvent(3.f, std::bind([](OpeningLevel* _This)
		{
			//_This->EffectBox->On();
			_This->EffectBox2->On();
			//_This->EffectBox->MoveStart();
			_This->EffectBox2->MoveStart_Down();
			_This->Zardlogo_White->On();
		}, this), false);
}

void OpeningLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}
