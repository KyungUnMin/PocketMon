#pragma once
#include "BattleState_SkillBase.h"

class BattleSkill_EnemyBase : public BattleState_SkillBase
{
public:
	BattleSkill_EnemyBase();
	~BattleSkill_EnemyBase() override;

	BattleSkill_EnemyBase(const BattleSkill_EnemyBase& _Other) = delete;
	BattleSkill_EnemyBase(BattleSkill_EnemyBase&& _Other) noexcept = delete;
	BattleSkill_EnemyBase& operator=(const BattleSkill_EnemyBase& _Other) = delete;
	BattleSkill_EnemyBase& operator=(const BattleSkill_EnemyBase&& _Other) noexcept = delete;

protected:
	bool Update_CheckTime(float _DeltaTime, float _Duration) override;

private:

};

