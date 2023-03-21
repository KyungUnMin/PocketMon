#pragma once
#include "BattleMonsterBase.h"

class GameEngineRender;

class BattleMonster_Bulbasaur : public BattleMonsterBase
{
public:
	BattleMonster_Bulbasaur();
	~BattleMonster_Bulbasaur() override;

	BattleMonster_Bulbasaur(const BattleMonster_Bulbasaur& _Other) = delete;
	BattleMonster_Bulbasaur(BattleMonster_Bulbasaur&& _Other) noexcept = delete;
	BattleMonster_Bulbasaur& operator=(const BattleMonster_Bulbasaur& _Other) = delete;
	BattleMonster_Bulbasaur& operator=(const BattleMonster_Bulbasaur&& _Other) noexcept = delete;

protected:

private:
	
};

