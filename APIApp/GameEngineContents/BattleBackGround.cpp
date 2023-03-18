#include "BattleBackGround.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleLevel.h"

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
}

void BattleBackGround::CreateField(BattleFieldType _BattleType)
{
	std::string BackRenderPath = "";

	switch (_BattleType)
	{
	case BattleFieldType::Indoor:
		BackRenderPath = "BattleIndoorField.bmp";
		break;
	case BattleFieldType::Grass:
		BackRenderPath = "BattleGrassField.bmp";
		break;
	case BattleFieldType::Stone:
		BackRenderPath = "BattleStoneField.bmp";
		break;
	}

	GameEngineRender* BackRender = CreateRender(BackRenderPath, RenderOrder::BackGround);

	BackRender->SetScale(ScreenSize);
	BackRender->SetPosition(ScreenSize.half());
}

void BattleBackGround::CreateFadeEffect()
{
	FadeUp = CreateRender("BattleFadeUp.bmp", RenderOrder::Fade);
	FadeUp->SetScale(ScreenSize);
	FadeDown = CreateRender("BattleFadeDown.bmp", RenderOrder::Fade);
	FadeDown->SetScale(ScreenSize);
}

void BattleBackGround::CreateEnterEffect(BattleFieldType _BattleType)
{
	size_t EffectCount = 5;
	EnterEffect.resize(EffectCount, nullptr);
	EffectSpeed = (ScreenSize.x * EffectCount);

	std::string EffectPath = "";
	switch (_BattleType)
	{
	case BattleFieldType::Indoor:
		EffectPath = "BattleIndoorIntro.bmp";
		break;
	case BattleFieldType::Grass:
		EffectPath = "BattleGrassIntro.bmp";
		break;
	case BattleFieldType::Stone:
		EffectPath = "BattleStoneIntro.bmp";
		break;
	}

	for (size_t i = 0; i < EnterEffect.size(); ++i)
	{
		EnterEffect[i] = CreateRender(EffectPath, RenderOrder::Particle);
		EnterEffect[i]->SetScaleToImage();
		EnterEffect[i]->SetPosition({ ScreenSize.x * i, ScreenSize.hy()});
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
