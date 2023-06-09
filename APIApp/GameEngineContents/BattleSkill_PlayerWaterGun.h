#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_WaterGun;

class BattleSkill_PlayerWaterGun : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerWaterGun();
	~BattleSkill_PlayerWaterGun();

	// delete Function
	BattleSkill_PlayerWaterGun(const BattleSkill_PlayerWaterGun& _Other) = delete;
	BattleSkill_PlayerWaterGun(BattleSkill_PlayerWaterGun&& _Other) noexcept = delete;
	BattleSkill_PlayerWaterGun& operator=(const BattleSkill_PlayerWaterGun& _Other) = delete;
	BattleSkill_PlayerWaterGun& operator=(BattleSkill_PlayerWaterGun&& _Other) noexcept = delete;

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