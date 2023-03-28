#include "LevelChangeFade.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnum.h"
#include "PocketMonCore.h"

LevelChangeFade* LevelChangeFade::MainLevelFade = nullptr;

LevelChangeFade::LevelChangeFade() 
{
}

LevelChangeFade::~LevelChangeFade() 
{
}

void LevelChangeFade::LevelChangeFadeOut(GameEngineLevel* _Level)
{
	NextLevelName = _Level->GetName();
	StateValue = FadeState::FadeOut;
	this->On();
	FadeRender->SetAlpha(0);
	Timer = 0;
}

void LevelChangeFade::LevelChangeFadeOut(const std::string_view& _LevelName)
{
	NextLevelName = _LevelName;
	StateValue = FadeState::FadeOut;
	this->On();
	FadeRender->SetAlpha(0);
	Timer = 0;
}

void LevelChangeFade::Start()
{
	FadeRender = CreateRender("MoveMapFade1.bmp", RenderOrder::Fade);
	FadeRender->EffectCameraOff();
	FadeRender->SetScaleToImage();
	FadeRender->SetPosition(FadeRender->GetScale().half());
}

void LevelChangeFade::Update(float _DeltaTime)
{
	if (StateValue == FadeState::FadeIn)
	{
		Timer -= FadeSpeed * _DeltaTime;
		FadeRender->SetAlpha(static_cast<int>(std::lerp(0, 255, Timer)));

		if (Timer < 0)
		{
			FadeRender->SetAlpha(0);
			this->Off();
		}
	}
	else if (StateValue == FadeState::FadeOut)
	{
		Timer += FadeSpeed * _DeltaTime;
		FadeRender->SetAlpha(static_cast<int>(std::lerp(0, 255, Timer)));

		if (Timer > 1)
		{
			FadeRender->SetAlpha(255);
			PocketMonCore::GetInst().ChangeLevel(NextLevelName);
		}
	}
}

void LevelChangeFade::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	this->On();
	FadeRender->SetAlpha(255);
	Timer = 1;
	StateValue = FadeState::FadeIn;
	MainLevelFade = this;
}

