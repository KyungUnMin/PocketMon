#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_DragonBreath;

class BattleSkill_PlayerDragonBreath : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerDragonBreath();
	~BattleSkill_PlayerDragonBreath();

	// delete Function
	BattleSkill_PlayerDragonBreath(const BattleSkill_PlayerDragonBreath& _Other) = delete;
	BattleSkill_PlayerDragonBreath(BattleSkill_PlayerDragonBreath&& _Other) noexcept = delete;
	BattleSkill_PlayerDragonBreath& operator=(const BattleSkill_PlayerDragonBreath& _Other) = delete;
	BattleSkill_PlayerDragonBreath& operator=(BattleSkill_PlayerDragonBreath&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;
		
	SkillActor_DragonBreath* BreathRender = nullptr;

	enum class MoveState
	{
		Forward,
		Backward
	};

	MoveState CurState = MoveState::Forward;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
};

