#include "BattleNPC.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnum.h"

BattleNPC* BattleNPC::NpcPtr = nullptr;

BattleNPC::BattleNPC()
{
	NpcPtr = this;
}

BattleNPC::~BattleNPC()
{
	if (this == NpcPtr)
	{
		NpcPtr = nullptr;
	}
}

void BattleNPC::Start()
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float4 GroundRenderScale = float4{ 517.f, 163.f };
	const float Height = 300.f;

	GameEngineRender* GroundRender = CreateRender("BattleNPCGround.bmp", RenderOrder::Player);
	GroundRender->SetScale(GroundRenderScale);

	SetMovePositions({ -GroundRenderScale.hx(), Height }, { ScreenSize.x - GroundRenderScale.hx(), Height });
}
