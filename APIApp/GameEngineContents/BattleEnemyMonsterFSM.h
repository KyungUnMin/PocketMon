#pragma once
#include "BattleFSMBase.h"

enum class BattleEnemyMonster_StateType
{
	Shadow,
	Idle,
	Lock,

	COUNT,
};

class BattleMonsterEnemy;

class BattleEnemyMonsterFSM : public BattleFSMBase
{
public:
	BattleEnemyMonsterFSM();
	~BattleEnemyMonsterFSM() override;

	BattleEnemyMonsterFSM(const BattleEnemyMonsterFSM& _Other) = delete;
	BattleEnemyMonsterFSM(BattleEnemyMonsterFSM&& _Other) noexcept = delete;
	BattleEnemyMonsterFSM& operator=(const BattleEnemyMonsterFSM& _Other) = delete;
	BattleEnemyMonsterFSM& operator=(const BattleEnemyMonsterFSM&& _Other) noexcept = delete;

	void Init(bool _IsWildMonster = false);

protected:

private:
};

