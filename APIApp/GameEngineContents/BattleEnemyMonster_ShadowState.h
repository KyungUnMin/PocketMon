#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattleMonsterEnemy;

class BattleEnemyMonster_ShadowState : public BattleStateBase
{
public:
	BattleEnemyMonster_ShadowState();
	~BattleEnemyMonster_ShadowState() override;

	BattleEnemyMonster_ShadowState(const BattleEnemyMonster_ShadowState& _Other) = delete;
	BattleEnemyMonster_ShadowState(BattleEnemyMonster_ShadowState&& _Other) noexcept = delete;
	BattleEnemyMonster_ShadowState& operator=(const BattleEnemyMonster_ShadowState& _Other) = delete;
	BattleEnemyMonster_ShadowState& operator=(const BattleEnemyMonster_ShadowState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	class BattleEnemy* Enemy = nullptr;
	class BattleMonsterEnemy* Monster = nullptr;
	class GameEngineRender* ShadowRender = nullptr;
	const float4 MoveOffset = float4{ 0.f, -80.f };
	float4 StartAlpha = float4{ 100.f, 0.f };

	float LiveTime = 0.f;
	float MoveTime = 0.f;
	const float ShadowDuration = 0.2f;
};

