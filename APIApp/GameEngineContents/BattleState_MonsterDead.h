#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;

class BattleState_MonsterDead : public BattleStateBase
{
public:
	BattleState_MonsterDead();
	~BattleState_MonsterDead() override;

	BattleState_MonsterDead(const BattleState_MonsterDead& _Other) = delete;
	BattleState_MonsterDead(BattleState_MonsterDead&& _Other) noexcept = delete;
	BattleState_MonsterDead& operator=(const BattleState_MonsterDead& _Other) = delete;
	BattleState_MonsterDead& operator=(const BattleState_MonsterDead&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* MonsterRender = nullptr;
	const float4 MoveOffset = float4{ 0.f, 50.f };

	float Timer = 0.f;
	const float Duration = 0.5f;
};

