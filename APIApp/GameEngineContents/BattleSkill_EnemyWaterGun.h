#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;
class SkillActor_WaterGun;

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
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_WaterGun* WaterGunRender = nullptr;

	SkillActor_WaterGun* WaterRender1 = nullptr;
	SkillActor_WaterGun* WaterRender2 = nullptr;
	SkillActor_WaterGun* WaterRender3 = nullptr;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};