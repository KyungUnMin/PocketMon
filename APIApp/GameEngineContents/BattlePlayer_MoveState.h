#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattlePlayer;

class BattlePlayer_MoveState : public BattleStateBase
{
public:
	BattlePlayer_MoveState();
	~BattlePlayer_MoveState() override;

	BattlePlayer_MoveState(const BattlePlayer_MoveState& _Other) = delete;
	BattlePlayer_MoveState(BattlePlayer_MoveState&& _Other) noexcept = delete;
	BattlePlayer_MoveState& operator=(const BattlePlayer_MoveState& _Other) = delete;
	BattlePlayer_MoveState& operator=(const BattlePlayer_MoveState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	float Timer = 0.f;
	float Duration = 0.f;
	float4 StartPos = float4::Zero;
	float4 DestPos = float4::Zero;

	BattlePlayer* Player = nullptr;

	void CreatePlayerRender();
};

