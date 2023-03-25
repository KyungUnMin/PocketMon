#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattleEnemy;

class BattleEnemy_MoveState : public BattleStateBase
{
public:
	BattleEnemy_MoveState();
	~BattleEnemy_MoveState() override;

	BattleEnemy_MoveState(const BattleEnemy_MoveState& _Other) = delete;
	BattleEnemy_MoveState(BattleEnemy_MoveState&& _Other) noexcept = delete;
	BattleEnemy_MoveState& operator=(const BattleEnemy_MoveState& _Other) = delete;
	BattleEnemy_MoveState& operator=(const BattleEnemy_MoveState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	float Timer = 0.f;
	float Duration = 0.f;
	float4 StartPos = float4::Zero;
	float4 DestPos = float4::Zero;

	BattleEnemy* Enemy = nullptr;
};

