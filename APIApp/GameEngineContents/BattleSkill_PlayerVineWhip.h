#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_VineWhip;

class BattleSkill_PlayerVineWhip : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerVineWhip();
	~BattleSkill_PlayerVineWhip();

	// delete Function
	BattleSkill_PlayerVineWhip(const BattleSkill_PlayerVineWhip& _Other) = delete;
	BattleSkill_PlayerVineWhip(BattleSkill_PlayerVineWhip&& _Other) noexcept = delete;
	BattleSkill_PlayerVineWhip& operator=(const BattleSkill_PlayerVineWhip& _Other) = delete;
	BattleSkill_PlayerVineWhip& operator=(BattleSkill_PlayerVineWhip&& _Other) noexcept = delete;

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