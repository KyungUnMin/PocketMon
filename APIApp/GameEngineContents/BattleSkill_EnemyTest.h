#pragma once
#include "BattleSkill_EnemyBase.h"

class BattleSkill_EnemyTest : public BattleSkill_EnemyBase
{
public:
	BattleSkill_EnemyTest();
	~BattleSkill_EnemyTest() override;

	BattleSkill_EnemyTest(const BattleSkill_EnemyTest& _Other) = delete;
	BattleSkill_EnemyTest(BattleSkill_EnemyTest&& _Other) noexcept = delete;
	BattleSkill_EnemyTest& operator=(const BattleSkill_EnemyTest& _Other) = delete;
	BattleSkill_EnemyTest& operator=(const BattleSkill_EnemyTest&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:

};




