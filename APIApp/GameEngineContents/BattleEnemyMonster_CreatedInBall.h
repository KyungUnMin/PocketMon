#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;

class BattleEnemyMonster_CreatedInBall : public BattleStateBase
{
public:
	BattleEnemyMonster_CreatedInBall();
	~BattleEnemyMonster_CreatedInBall() override;

	BattleEnemyMonster_CreatedInBall(const BattleEnemyMonster_CreatedInBall& _Other) = delete;
	BattleEnemyMonster_CreatedInBall(BattleEnemyMonster_CreatedInBall&& _Other) noexcept = delete;
	BattleEnemyMonster_CreatedInBall& operator=(const BattleEnemyMonster_CreatedInBall& _Other) = delete;
	BattleEnemyMonster_CreatedInBall& operator=(const BattleEnemyMonster_CreatedInBall&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* EffectRender = nullptr;
	GameEngineRender* BallRender = nullptr;
	const float4 BallScale = float4{ 64.f, 64.f };

	float4 OriginScale = float4::Zero;
	float Timer = 0.f;
	const float Duration = 0.5f;

	void CreateRenders();
};

