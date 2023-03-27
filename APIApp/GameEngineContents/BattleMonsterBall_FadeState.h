#pragma once
#include "BattleStateBase.h"

class BattleMonsterBall_FadeState : public BattleStateBase
{
public:
	BattleMonsterBall_FadeState();
	~BattleMonsterBall_FadeState() override;

	BattleMonsterBall_FadeState(const BattleMonsterBall_FadeState& _Other) = delete;
	BattleMonsterBall_FadeState(BattleMonsterBall_FadeState&& _Other) noexcept = delete;
	BattleMonsterBall_FadeState& operator=(const BattleMonsterBall_FadeState& _Other) = delete;
	BattleMonsterBall_FadeState& operator=(const BattleMonsterBall_FadeState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	class GameEngineRender* BallRender = nullptr;
	class BattleMonsterBall* MonsterBall = nullptr;

	const float Duration = 1.f;
	float LiveTime = 0.f;

};

