#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;

class BattleEnemyMonster_UnlockState : public BattleStateBase
{
public:
	BattleEnemyMonster_UnlockState();
	~BattleEnemyMonster_UnlockState() override;

	BattleEnemyMonster_UnlockState(const BattleEnemyMonster_UnlockState& _Other) = delete;
	BattleEnemyMonster_UnlockState(BattleEnemyMonster_UnlockState&& _Other) noexcept = delete;
	BattleEnemyMonster_UnlockState& operator=(const BattleEnemyMonster_UnlockState& _Other) = delete;
	BattleEnemyMonster_UnlockState& operator=(const BattleEnemyMonster_UnlockState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	float4 OriginScale = float4::Zero;
	float4 StartOffset = float4::Zero;

	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* EffectRender = nullptr;

	float Timer = 0.f;
	const float Duration = 0.5f;
};

