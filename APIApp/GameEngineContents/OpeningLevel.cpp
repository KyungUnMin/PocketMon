#include "OpeningLevel.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTimeEvent.h>

#include "BlackBox.h"
#include "EffectBlackBox.h"
#include "Opening_Text.h"
#include "Logo_Charizard.h"
#include "Logo_Charizard_White.h"

OpeningLevel* OpeningLevel::OpeningLevelPtr = nullptr;

OpeningLevel::OpeningLevel() 
{
}

OpeningLevel::~OpeningLevel() 
{
}

void OpeningLevel::Loading()
{
	OpeningLevelPtr = this;

	float4 Winsize_h = GameEngineWindow::GetScreenSize().half();

	CreateActor<BlackBox>();

	EffectBox1 = CreateActor<EffectBlackBox>();
	EffectBox2 = CreateActor<EffectBlackBox>();
	EffectBox3 = CreateActor<EffectBlackBox>();
	EffectBox4 = CreateActor<EffectBlackBox>();
	EffectBox5 = CreateActor<EffectBlackBox>();
	EffectBox6 = CreateActor<EffectBlackBox>();

	EffectBox2->SetPos(Winsize_h + float4::Down * Winsize_h.y * 2 + float4::Down * 200);
	EffectBox3->SetPos(Winsize_h + float4::Down * 25);
	EffectBox4->SetPos(Winsize_h + float4::Down * Winsize_h.y * 2 + float4::Down * 175);
	EffectBox5->SetPos(Winsize_h + float4::Down * 50);
	EffectBox6->SetPos(Winsize_h + float4::Down * Winsize_h.y * 2 + float4::Down * 150);
	
	OpeningText = CreateActor<Opening_Text>();
	Zardlogo = CreateActor<Logo_Charizard>();
	Zardlogo_White = CreateActor<Logo_Charizard_White>();

	EffectBox1->Off();
	EffectBox2->Off();
	EffectBox3->Off();
	EffectBox4->Off();
	EffectBox5->Off();
	EffectBox6->Off();

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
			_This->EffectBox1->On();
			_This->EffectBox2->On();
			_This->EffectBox3->On();
			_This->EffectBox4->On();
			_This->EffectBox5->On();
			_This->EffectBox6->On();

			_This->EffectBox1->MoveStart();
			_This->EffectBox2->MoveStart_Down();
			_This->EffectBox3->MoveStart_Alpha();
			_This->EffectBox4->MoveStart_Down_Alpha();
			_This->EffectBox5->MoveStart_Alpha2();
			_This->EffectBox6->MoveStart_Down_Alpha2();

			_This->Zardlogo_White->On();
		}, this), false);

	LevelEvent.AddEvent(5.0f, std::bind([](OpeningLevel* _This)
		{
			_This->Zardlogo->On();
			_This->Zardlogo->GrayAnimationStart();
		}, this), false);

	LevelEvent.AddEvent(7.5f, std::bind([](OpeningLevel* _This)
		{
			_This->Zardlogo_White->BlinkStart();
		}, this), false);

	LevelEvent.AddEvent(8.0f, std::bind([](OpeningLevel* _This)
		{
			_This->Zardlogo_White->BlinkStart();
		}, this), false);

	LevelEvent.AddEvent(8.5f, std::bind([](OpeningLevel* _This)
		{
			_This->Zardlogo_White->OriginBlinkStart();
		}, this), false);
}

void OpeningLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}
