#pragma once
#include "BattleMonsterBase.h"

class BattleMonsterPlayer : public BattleMonsterBase
{
public:
	BattleMonsterPlayer();
	virtual ~BattleMonsterPlayer() = 0;

	BattleMonsterPlayer(const BattleMonsterPlayer& _Other) = delete;
	BattleMonsterPlayer(BattleMonsterPlayer&& _Other) noexcept = delete;
	BattleMonsterPlayer& operator=(const BattleMonsterPlayer& _Other) = delete;
	BattleMonsterPlayer& operator=(const BattleMonsterPlayer&& _Other) noexcept = delete;

protected:

private:

};

