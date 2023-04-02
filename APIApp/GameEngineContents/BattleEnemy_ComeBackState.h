#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "BattleStateBase.h"

class GameEngineRender;

class BattleEnemy_ComeBackState : public BattleStateBase
{
public:
	BattleEnemy_ComeBackState();
	~BattleEnemy_ComeBackState() override;

	BattleEnemy_ComeBackState(const BattleEnemy_ComeBackState& _Other) = delete;
	BattleEnemy_ComeBackState(BattleEnemy_ComeBackState&& _Other) noexcept = delete;
	BattleEnemy_ComeBackState& operator=(const BattleEnemy_ComeBackState& _Other) = delete;
	BattleEnemy_ComeBackState& operator=(const BattleEnemy_ComeBackState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* EnemyRender = nullptr;
	float4 PrevOffset = float4::Zero;
	float4 DestOffset = float4::Zero;
	float Timer = 0.f;
	const float Duration = 0.25f;
};

