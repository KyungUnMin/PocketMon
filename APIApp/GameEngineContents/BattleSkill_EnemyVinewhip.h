#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;

class BattleSkill_EnemyVinewhip : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyVinewhip();
	~BattleSkill_EnemyVinewhip();

	// delete Function
	BattleSkill_EnemyVinewhip(const BattleSkill_EnemyVinewhip& _Other) = delete;
	BattleSkill_EnemyVinewhip(BattleSkill_EnemyVinewhip&& _Other) noexcept = delete;
	BattleSkill_EnemyVinewhip& operator=(const BattleSkill_EnemyVinewhip& _Other) = delete;
	BattleSkill_EnemyVinewhip& operator=(BattleSkill_EnemyVinewhip&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:

};

