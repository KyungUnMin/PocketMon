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
	const float4 MoveStartPos = float4{ 0.f, 0.f };

	SetMovePositions(ScreenSize, { 0.f, ScreenSize.y });

	const float4 GroundRenderScale = float4{ 200.f, 200.f };
	GameEngineRender* GroundRender = CreateRender("BattlePlayerGround.bmp", RenderOrder::Player);
	GroundRender->SetScale(GroundRenderScale);


}
