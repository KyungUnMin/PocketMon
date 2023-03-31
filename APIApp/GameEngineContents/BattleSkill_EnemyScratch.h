#pragma once
#include "BattleSkill_EnemyBase.h"
// Ό³Έν :
class BattleSkill_EnemyScratch : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyScratch();
	~BattleSkill_EnemyScratch();

	// delete Function
	BattleSkill_EnemyScratch(const BattleSkill_EnemyScratch& _Other) = delete;
	BattleSkill_EnemyScratch(BattleSkill_EnemyScratch&& _Other) noexcept = delete;
	BattleSkill_EnemyScratch& operator=(const BattleSkill_EnemyScratch& _Other) = delete;
	BattleSkill_EnemyScratch& operator=(BattleSkill_EnemyScratch&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 1.0f;
	float Timer = 0;
	enum class MoveState
	{
		Forward,
		Backward
	};

};

