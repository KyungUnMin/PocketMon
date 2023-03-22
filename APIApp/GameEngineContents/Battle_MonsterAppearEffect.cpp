#include "Battle_MonsterAppearEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnum.h"

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

	WhiteFade = CreateRender("BattleAppearEffect.bmp", RenderOrder::Battle_Effect);
	WhiteFade->SetScaleToImage();
	WhiteFade->Off();
}

void Battle_MonsterAppearEffect::Action()
{
	IsActive = true;
	ActiveTime = GetLiveTime();
	CurState = FadeState::FadeIn;
	WhiteFade->On();
}


void Battle_MonsterAppearEffect::Update(float _DeltaTime)
{
	if (false == IsActive)
		return;

	if (FadeState::FadeIn == CurState)
	{
		if (false == Update_Fade(0.f, 255.f))
			return;

		CurState = FadeState::FadeOut;
		ActiveTime = GetLiveTime();
	}
	else if (FadeState::FadeOut == CurState)
	{
		if (false == Update_Fade(255.f, 0.f))
			return;

		IsActive = false;
		WhiteFade->Off();
	}
}


bool Battle_MonsterAppearEffect::Update_Fade(float _StartAlpha, float _DestAlpha)
{
	float NowTime = GetLiveTime() - ActiveTime;
	float Ratio = (NowTime / Duration);

	float4 StartAlpha = float4::Right * _StartAlpha;
	float4 DestAlpha = float4::Right * _DestAlpha;

	float4 NowAlpha = float4::LerpClamp(StartAlpha, DestAlpha, Ratio);
	WhiteFade->SetAlpha(NowAlpha.ix());

	return (1.f < Ratio);
}
