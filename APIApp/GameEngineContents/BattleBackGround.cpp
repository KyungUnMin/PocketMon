#include "BattleBackGround.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

BattleBackGround::BattleBackGround()
{

}

BattleBackGround::~BattleBackGround()
{

}

void BattleBackGround::Start()
{
	ScreenSize = GameEngineWindow::GetScreenSize();
	
	GameEngineRender* BackRender = CreateRender("BattleBackGround.bmp", RenderOrder::BackGround);
	BackRender->SetScale(ScreenSize);
	BackRender->SetPosition(ScreenSize.half());

	FadeUp = CreateRender("BattleFadeUp.bmp", RenderOrder::Fade);
	FadeUp->SetScale(ScreenSize);
	FadeDown = CreateRender("BattleFadeDown.bmp", RenderOrder::Fade);
	FadeDown->SetScale(ScreenSize);
}

void BattleBackGround::Update(float _DeltaTime)
{
	FadeMove();


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
