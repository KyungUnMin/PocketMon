#include "Battle_MonsterAppearEffect.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnum.h"

const float Battle_MonsterAppearEffect::FadeDuration = 0.15f;

Battle_MonsterAppearEffect::Battle_MonsterAppearEffect()
{

}

Battle_MonsterAppearEffect::~Battle_MonsterAppearEffect()
{

}



void Battle_MonsterAppearEffect::Start()
{
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	SetPos(ScreenSize.half());

	WhiteFade = CreateRender("BattleAppearEffect.bmp", BattleRenderOrder::Effect0);
	WhiteFade->SetScaleToImage();
}

void Battle_MonsterAppearEffect::Update(float _DeltaTime)
{
	if (FadeState::FadeIn == CurState)
	{
		if (false == Update_Fade(0.f, 255.f))
			return;

		CurState = FadeState::FadeOut;
		FadeTime = GetLiveTime();
	}
	else if (FadeState::FadeOut == CurState)
	{
		if (false == Update_Fade(255.f, 0.f))
			return;

		Death();
	}
}

bool Battle_MonsterAppearEffect::Update_Fade(float _StartAlpha, float _DestAlpha)
{
	float NowTime = GetLiveTime() - FadeTime;
	float Ratio = (NowTime / FadeDuration);

	float4 StartAlpha = float4::Right * _StartAlpha;
	float4 DestAlpha = float4::Right * _DestAlpha;

	float4 NowAlpha = float4::LerpClamp(StartAlpha, DestAlpha, Ratio);
	WhiteFade->SetAlpha(NowAlpha.ix());

	return (1.f < Ratio);
}
