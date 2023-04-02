#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;
class SkillActor_VineWhip;

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
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_VineWhip* VineRender1 = nullptr;
	SkillActor_VineWhip* VineRender2 = nullptr;

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