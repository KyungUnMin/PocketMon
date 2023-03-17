#include "BattlePlayer.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

BattlePlayer* BattlePlayer::PlayerPtr = nullptr;

BattlePlayer::BattlePlayer()
{
	PlayerPtr = this;
}

BattlePlayer::~BattlePlayer()
{
	if (this == PlayerPtr)
	{
		PlayerPtr = nullptr;
	}
}

void BattlePlayer::Start()
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float4 GroundRenderScale = float4{ 528.f, 72.f };
	const float Height = (ScreenSize.y - 200.f);


	GameEngineRender* GroundRender = CreateRender("BattlePlayerGround.bmp", RenderOrder::Player);
	GroundRender->SetScale(GroundRenderScale);
	SetMovePositions({ ScreenSize.x + GroundRenderScale.hx(), Height}, { GroundRenderScale.hx(), Height});
}
