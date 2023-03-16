#include "BattleNPC.h"
#include <GameEngineCore/GameEngineRender.h>
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
	SetMovePositions({ 500.f, 300.f }, { 100.f, 300.f });

	const float4 GroundRenderScale = float4{ 200.f, 200.f };
	GameEngineRender* GroundRender = CreateRender("BattleNPCGround.bmp", RenderOrder::Player);
	GroundRender->SetScale(GroundRenderScale);
}
