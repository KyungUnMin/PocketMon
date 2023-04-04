#pragma once
#include "BattleSkill_PlayerBase.h"
#include <GameEngineBase/GameEngineTimeEvent.h>

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
	GameEngineRender* EffectRender = nullptr;
	GameEngineTimeEvent TimeEvent;
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

	bool IsMove = true;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};
