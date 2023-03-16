#include "BattleNPC.h"

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
}
