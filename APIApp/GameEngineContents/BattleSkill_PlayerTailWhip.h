#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;

class BattleSkill_PlayerTailWhip : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerTailWhip();
	~BattleSkill_PlayerTailWhip();

	// delete Function
	BattleSkill_PlayerTailWhip(const BattleSkill_PlayerTailWhip& _Other) = delete;
	BattleSkill_PlayerTailWhip(BattleSkill_PlayerTailWhip&& _Other) noexcept = delete;
	BattleSkill_PlayerTailWhip& operator=(const BattleSkill_PlayerTailWhip& _Other) = delete;
	BattleSkill_PlayerTailWhip& operator=(BattleSkill_PlayerTailWhip&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	float4 StartPos1 = float4::Zero;
	float4 EndPos1 = float4::Zero;
	float4 StartPos2 = float4::Zero;
	float4 EndPos2 = float4::Zero;
	float4 StartPos3 = float4::Zero;
	float4 EndPos3 = float4::Zero;

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

