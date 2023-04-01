#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;

class BattleSkill_PlayerQuickAttack : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerQuickAttack();
	~BattleSkill_PlayerQuickAttack();

	// delete Function
	BattleSkill_PlayerQuickAttack(const BattleSkill_PlayerQuickAttack& _Other) = delete;
	BattleSkill_PlayerQuickAttack(BattleSkill_PlayerQuickAttack&& _Other) noexcept = delete;
	BattleSkill_PlayerQuickAttack& operator=(const BattleSkill_PlayerQuickAttack& _Other) = delete;
	BattleSkill_PlayerQuickAttack& operator=(BattleSkill_PlayerQuickAttack&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

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
