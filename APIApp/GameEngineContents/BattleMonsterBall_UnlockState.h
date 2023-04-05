#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattleMonsterBall;

class BattleMonsterBall_UnlockState : public BattleStateBase
{
public:
	BattleMonsterBall_UnlockState();
	~BattleMonsterBall_UnlockState() override;

	BattleMonsterBall_UnlockState(const BattleMonsterBall_UnlockState& _Other) = delete;
	BattleMonsterBall_UnlockState(BattleMonsterBall_UnlockState&& _Other) noexcept = delete;
	BattleMonsterBall_UnlockState& operator=(const BattleMonsterBall_UnlockState& _Other) = delete;
	BattleMonsterBall_UnlockState& operator=(const BattleMonsterBall_UnlockState&& _Other) noexcept = delete;

	static const float4& GetBallPos()
	{
		return MonsterBallPos;
	}

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	BattleMonsterBall* MonsterBall = nullptr;
	float Timer = 0.f;
	const float Duration = 0.5f;

	static float4 MonsterBallPos;
};

