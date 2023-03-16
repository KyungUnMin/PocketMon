#include "BattlePlayer.h"

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
	SetMovePositions({ 100.f, 100.f }, { 500.f, 100.f });
}
