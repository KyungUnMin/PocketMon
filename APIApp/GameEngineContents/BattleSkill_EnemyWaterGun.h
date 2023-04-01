#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;

class BattleSkill_EnemyWaterGun : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyWaterGun();
	~BattleSkill_EnemyWaterGun();

	// delete Function
	BattleSkill_EnemyWaterGun(const BattleSkill_EnemyWaterGun& _Other) = delete;
	BattleSkill_EnemyWaterGun(BattleSkill_EnemyWaterGun&& _Other) noexcept = delete;
	BattleSkill_EnemyWaterGun& operator=(const BattleSkill_EnemyWaterGun& _Other) = delete;
	BattleSkill_EnemyWaterGun& operator=(BattleSkill_EnemyWaterGun&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:

};

