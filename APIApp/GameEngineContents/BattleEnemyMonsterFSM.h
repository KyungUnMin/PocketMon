#pragma once
#include "BattleFSMBase.h"

enum class BattleEnemyMonster_StateType
{
	Test,

	Shadow,
	Idle,
	Lock,
	Dead,
	CreatedInBall,

	Skill_Tackle,
	Skill_Growl,
	Skill_Scratch,
	COUNT,
};

class BattleMonsterEnemy;

class BattleEnemyMonsterFSM : public BattleFSMBase
{
public:
	BattleEnemyMonsterFSM(class GameEngineActor* _Owner);
	~BattleEnemyMonsterFSM() override;

	BattleEnemyMonsterFSM(const BattleEnemyMonsterFSM& _Other) = delete;
	BattleEnemyMonsterFSM(BattleEnemyMonsterFSM&& _Other) noexcept = delete;
	BattleEnemyMonsterFSM& operator=(const BattleEnemyMonsterFSM& _Other) = delete;
	BattleEnemyMonsterFSM& operator=(const BattleEnemyMonsterFSM&& _Other) noexcept = delete;

	void Init(bool _IsWildMonster = false);

protected:

private:
};

