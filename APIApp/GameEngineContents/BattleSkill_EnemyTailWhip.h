#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;

// Ό³Έν :
class BattleSkill_EnemyTailWhip : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyTailWhip();
	~BattleSkill_EnemyTailWhip();

	// delete Function
	BattleSkill_EnemyTailWhip(const BattleSkill_EnemyTailWhip& _Other) = delete;
	BattleSkill_EnemyTailWhip(BattleSkill_EnemyTailWhip&& _Other) noexcept = delete;
	BattleSkill_EnemyTailWhip& operator=(const BattleSkill_EnemyTailWhip& _Other) = delete;
	BattleSkill_EnemyTailWhip& operator=(BattleSkill_EnemyTailWhip&& _Other) noexcept = delete;

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

	float Pos1Time = 0.0f;
	float Pos2Time = 0.0f;
	float Pos3Time = 0.0f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
};

