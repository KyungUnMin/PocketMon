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
	static const std::string_view BallFallAniName;
	static const std::string_view BallOpenAniName;

	enum class State
	{
		JumpBall,
		FallBall,
		OpenBall,
		CreateMonster,
	};

	State CurState = State::JumpBall;

	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* EffectRender = nullptr;
	GameEngineRender* BallRender = nullptr;
	const float4 BallScale = float4{ 64.f, 64.f };

	float4 OriginScale = float4::Zero;
	const float4 MoveOffset = float4{ 0.f, -150.f };

	void CreateRenders();
	void Update_JumpBall(float _DeltaTime);
	void Update_FallBall(float _DeltaTime);
	void Update_OpenBall(float _DeltaTime);
	void Update_CreateMonster(float _DeltaTime);
};

