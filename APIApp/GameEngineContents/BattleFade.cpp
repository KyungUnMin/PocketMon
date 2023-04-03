#include "BattleFade.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "FieldmapLevel.h"

BattleFade* BattleFade::FieldmapBattleFade = nullptr;

BattleFade::BattleFade()
{
}

BattleFade::~BattleFade()
{
}

void BattleFade::PlayBattleFade(int _Count, float _Speed, std::function<void()> _EndEvent)
{
	IsLastFadePlay = false;

	LoopCount = _Count;
	CurCount = 0;

	FadeUpRender->SetPosition(FadeUpStartPos);
	FadeDownRender->SetPosition(FadeDownStartPos);

	Speed = _Speed;
	ProgressTime = 0.0f;
	State = FadeState::In;
	EndEvent = _EndEvent;
	FadeUpRender->Off();
	FadeDownRender->Off();
	FadeRender->On();
	On();
}

void BattleFade::Start()
{
	float4 WindowSize = GameEngineWindow::GetScreenSize();
	float4 WindowSizeHalf = WindowSize.half();

	FadeRender = CreateRender("Background.BMP", RenderOrder::Fade);
	FadeRender->SetScale(WindowSize);
	FadeRender->SetPosition(WindowSizeHalf);
	FadeRender->EffectCameraOff();

	FadeUpStartPos = float4(WindowSizeHalf.x, -WindowSizeHalf.y);
	FadeUpEndPos = float4(WindowSizeHalf.x, 0.0f);

	FadeUpRender = CreateRender("Background.BMP", RenderOrder::Fade);
	FadeUpRender->SetScale(WindowSize);
	FadeUpRender->EffectCameraOff();
	FadeUpRender->SetPosition(FadeUpStartPos);

	FadeDownStartPos = float4(WindowSizeHalf.x, WindowSize.y + WindowSizeHalf.y);
	FadeDownEndPos = float4(WindowSizeHalf.x, WindowSize.y);

	FadeDownRender = CreateRender("Background.BMP", RenderOrder::Fade);
	FadeDownRender->SetScale(WindowSize);
	FadeDownRender->EffectCameraOff();
	FadeDownRender->SetPosition(FadeDownStartPos);

	if (nullptr != FieldmapBattleFade)
	{
		MsgAssert("필드맵 배틀 페이드를 중복 생성했습니다");
		Death();
		return;
	}

	FieldmapBattleFade = this;
	Off();
}

void BattleFade::Update(float _DeltaTime)
{
	if (false == IsLastFadePlay && CurCount >= LoopCount)
	{
		ProgressTime = 0.0f;
		IsLastFadePlay = true;
		FadeUpRender->On();
		FadeDownRender->On();
		FadeRender->Off();
	}

	if (true == IsLastFadePlay)
	{
		ProgressTime += _DeltaTime * 2.0f;

		FadeUpRender->SetPosition(float4::Lerp(FadeUpStartPos, FadeUpEndPos, ProgressTime));
		FadeDownRender->SetPosition(float4::Lerp(FadeDownStartPos, FadeDownEndPos, ProgressTime));

		if (1.0f <= ProgressTime)
		{
			if (nullptr != EndEvent)
			{
				EndEvent();
			}

			FieldmapLevel::AddLevelStartFunc(std::bind([](BattleFade* _this)
				{
					_this->Off();
				}, this));
		}
	}
	else
	{
		ProgressTime += _DeltaTime * Speed;

		if (1.0f <= ProgressTime)
		{
			ProgressTime -= 1.0f;

			switch (State)
			{
			case BattleFade::FadeState::In:
				State = FadeState::Out;
				break;
			case BattleFade::FadeState::Out:
				++CurCount;
				State = FadeState::In;
				break;
			default:
				MsgAssert("잘못된 BattleFade State 입니다.");
				break;
			}
		}

		switch (State)
		{
		case BattleFade::FadeState::In:
			FadeRender->SetAlpha(static_cast<int>(GameEngineMath::Lerp(0.0f, 255.0f, ProgressTime)));
			break;
		case BattleFade::FadeState::Out:
			FadeRender->SetAlpha(static_cast<int>(GameEngineMath::Lerp(255.0f, 0.0f, ProgressTime)));
			break;
		default:
			MsgAssert("잘못된 BattleFade State 입니다.");
			break;
		}
	}	
}