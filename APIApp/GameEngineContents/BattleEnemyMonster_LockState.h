#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;

class BattleEnemyMonster_LockState : public BattleStateBase
{
public:
	BattleEnemyMonster_LockState();
	~BattleEnemyMonster_LockState() override;

	BattleEnemyMonster_LockState(const BattleEnemyMonster_LockState& _Other) = delete;
	BattleEnemyMonster_LockState(BattleEnemyMonster_LockState&& _Other) noexcept = delete;
	BattleEnemyMonster_LockState& operator=(const BattleEnemyMonster_LockState& _Other) = delete;
	BattleEnemyMonster_LockState& operator=(const BattleEnemyMonster_LockState&& _Other) noexcept = delete;

	static const float4& GetOriginScale();

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* LockEffect = nullptr;

	float4 DestOffset = float4::Zero;
	static float4 OriginScale;

	float LiveTime = 0.f;
	float Duration = 1.f;
};

