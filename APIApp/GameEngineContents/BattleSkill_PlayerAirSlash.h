#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_AirSlash;

class BattleSkill_PlayerAirSlash : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerAirSlash();
	~BattleSkill_PlayerAirSlash();

	// delete Function
	BattleSkill_PlayerAirSlash(const BattleSkill_PlayerAirSlash& _Other) = delete;
	BattleSkill_PlayerAirSlash(BattleSkill_PlayerAirSlash&& _Other) noexcept = delete;
	BattleSkill_PlayerAirSlash& operator=(const BattleSkill_PlayerAirSlash& _Other) = delete;
	BattleSkill_PlayerAirSlash& operator=(BattleSkill_PlayerAirSlash&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;
		
	SkillActor_AirSlash* AirSlashRender = nullptr;

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
