#include "BattleBackGround.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleLevel.h"
#include "BackTextActor.h"

BattleBackGround::BattleBackGround()
{

}

BattleBackGround::~BattleBackGround()
{

}

void BattleBackGround::Init(BattleFieldType _BattleType)
{
	ScreenSize = GameEngineWindow::GetScreenSize();

	CreateField(_BattleType);
	CreateFadeEffect();
	CreateEnterEffect(_BattleType);

	//GetLevel()->CreateActor<BackTextActor>();
}

void BattleBackGround::CreateField(BattleFieldType _BattleType)
{
	std::string BackRenderPath = "";

	switch (_BattleType)
	{
	case BattleFieldType::Indoor:
		BackRenderPath = "BattleIndoorField.bmp";
		break;
	case BattleFieldType::Forest0:
	case BattleFieldType::Forest1:
		BackRenderPath = "BattleForestField.bmp";
		break;
	case BattleFieldType::Gym:
		BackRenderPath = "BattleGymField.bmp";
		break;
	}

	GameEngineRender* BackRender = CreateRender(BackRenderPath, BattleRenderOrder::BackGround);

	BackRender->SetScale(ScreenSize);
	BackRender->SetPosition(ScreenSize.half());
}

void BattleBackGround::CreateFadeEffect()
{
	FadeUp = CreateRender("BattleFadeUp.bmp", BattleRenderOrder::Fade);
	FadeUp->SetScale(ScreenSize);
	FadeDown = CreateRender("BattleFadeDown.bmp", BattleRenderOrder::Fade);
	FadeDown->SetScale(ScreenSize);
}

void BattleBackGround::CreateEnterEffect(BattleFieldType _BattleType)
{
	size_t EffectCount = 10;
	EnterEffect.resize(EffectCount, nullptr);
	EffectSpeed = (ScreenSize.x * EffectCount);

	std::string EffectPath = "";
	switch (_BattleType)
	{
	case BattleFieldType::Indoor:
		EffectPath = "BattleIndoorIntro.bmp";
		break;
	case BattleFieldType::Forest0:
		EffectPath = "BattleForestIntro.bmp";
		break;
	case BattleFieldType::Gym:
		EffectPath = "BattleGymIntro.bmp";
		break;
	}

	const float Height = ScreenSize.hy() - 100.f;
	const float OffsetY = 20.f;
	for (size_t i = 0; i < EnterEffect.size(); ++i)
	{
		EnterEffect[i] = CreateRender(EffectPath, BattleRenderOrder::Particle0);
		EnterEffect[i]->SetScaleToImage();

		float4 Offset = { ScreenSize.x * i, Height + (OffsetY * i) };
		EnterEffect[i]->SetPosition(Offset);
	}

}


void BattleBackGround::Update(float _DeltaTime)
{
	FadeMove();
	EffectMove(_DeltaTime);
}



void BattleBackGround::FadeMove()
{
	float LiveTime = GetLiveTime();
	if (FadeDuration < LiveTime)
	{
		if ((nullptr == FadeUp) && (nullptr == FadeDown))
			return;

		FadeUp->Death();
		FadeUp = nullptr;

		FadeDown->Death();
		FadeDown = nullptr;
		return;
	}

	float Ratio = (LiveTime / FadeDuration);
	float4 StartPos = ScreenSize.half();

	float4 FadeUpOffset = float4::LerpClamp(StartPos, { StartPos.x, 0.f }, Ratio);
	FadeUp->SetPosition(FadeUpOffset);

	float4 FadeDownOffset = float4::LerpClamp(StartPos, { StartPos.x, ScreenSize.y }, Ratio);
	FadeDown->SetPosition(FadeDownOffset);
}

void BattleBackGround::EffectMove(float _DeltaTime)
{
	float LiveTime = GetLiveTime();
	if (EffectDuration < LiveTime)
	{
		if (true == EnterEffect.empty())
			return;

		for (GameEngineRender* Effect : EnterEffect)
		{
			Effect->Death();
		}

		EnterEffect.clear();
		return;
	}

	for (GameEngineRender* Effect : EnterEffect)
	{
		Effect->SetMove(float4::Left * EffectSpeed * _DeltaTime);
	}

}
