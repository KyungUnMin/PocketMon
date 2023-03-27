#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattleMonsterBall;

class BattleMonsterBall_VerticalShake : public BattleStateBase
{
public:
	BattleMonsterBall_VerticalShake();
	~BattleMonsterBall_VerticalShake() override;

	BattleMonsterBall_VerticalShake(const BattleMonsterBall_VerticalShake& _Other) = delete;
	BattleMonsterBall_VerticalShake(BattleMonsterBall_VerticalShake&& _Other) noexcept = delete;
	BattleMonsterBall_VerticalShake& operator=(const BattleMonsterBall_VerticalShake& _Other) = delete;
	BattleMonsterBall_VerticalShake& operator=(const BattleMonsterBall_VerticalShake&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	BattleMonsterBall* MonsterBall = nullptr;

	float Range = 150.f;
	float4 TopPos = float4::Zero;
	float4 BotPos = float4::Zero;

	size_t MoveCnt = 0;
	const float Duration = 0.2f;
	float Timer = 0.f;
	const float NextPer = 0.6f;
};

