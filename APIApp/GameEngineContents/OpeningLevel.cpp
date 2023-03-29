#include "OpeningLevel.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTimeEvent.h>

#include "BlackBox.h"
#include "EffectBlackBox.h"

#include "Opening_Text.h"

#include "Logo_Charizard.h"
#include "Logo_Charizard_White.h"
#include "Logo_Back1.h"
#include "Logo_Back2.h"
#include "Logo_Back3.h"
#include "Logo_Pokemon.h"
#include "Logo_Pokemon_White.h"
#include "Logo_Fireredversion.h"
#include "Logo_Fireredversion_White.h"
#include "Logo_PressStart.h"
#include "Logo_Backeffect.h"

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


	BlackBack = CreateActor<Logo_Back3>();
	RedBack = CreateActor<Logo_Back1>();
	GreenBack = CreateActor<Logo_Back2>();

	PokemonTitle = CreateActor<Logo_Pokemon>();
	PokemonTitle_White = CreateActor<Logo_Pokemon_White>();

	FireV = CreateActor<Logo_Fireredversion>();
	FireV_White = CreateActor<Logo_Fireredversion_White>();

	PressStart = CreateActor<Logo_PressStart>();
	Burnning = CreateActor<Logo_Backeffect>();

	EffectBox1->Off();
	EffectBox2->Off();
	EffectBox3->Off();
	EffectBox4->Off();
	EffectBox5->Off();
	EffectBox6->Off();

	Zardlogo->Off();
	Zardlogo_White->Off();
	RedBack->Off();
	GreenBack->Off();
	BlackBack->Off();
	PokemonTitle_White->Off();
	FireV_White->Off();
	PressStart->Off();
	Burnning->Off();
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
			_This->BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("Title.mp3");
			_This->BGMPlayer.Volume(0.3f);
			_This->BGMPlayer.LoopCount(10);

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
			_This->GreenBack->On();
			_This->GreenBack->LerpStart();
		}, this), false);

	LevelEvent.AddEvent(8.0f, std::bind([](OpeningLevel* _This)
		{
			_This->Zardlogo_White->BlinkStart();
			_This->RedBack->On();
			_This->RedBack->LerpStart();
			_This->BlackBack->On();
		}, this), false);

	LevelEvent.AddEvent(8.5f, std::bind([](OpeningLevel* _This)
		{
			_This->Zardlogo_White->OriginBlinkStart();
			
			_This->PokemonTitle_White->On();
			_This->PokemonTitle_White->BlinkStart();
			
			_This->FireV_White->On();
			_This->FireV_White->BlinkStart();

			_This->PressStart->On();
			_This->PressStart->BlinkStart();

			_This->Burnning->On();
		}, this), false);
}

void OpeningLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	BGMPlayer.Stop();
}
