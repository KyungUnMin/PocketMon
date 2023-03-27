#pragma once
#include "BattleStateBase.h"

class GameEngineRender;

class BattleMonsterBall_CatchState : public BattleStateBase
{
public:
	BattleMonsterBall_CatchState();
	~BattleMonsterBall_CatchState() override;

	BattleMonsterBall_CatchState(const BattleMonsterBall_CatchState& _Other) = delete;
	BattleMonsterBall_CatchState(BattleMonsterBall_CatchState&& _Other) noexcept = delete;
	BattleMonsterBall_CatchState& operator=(const BattleMonsterBall_CatchState& _Other) = delete;
	BattleMonsterBall_CatchState& operator=(const BattleMonsterBall_CatchState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* BallRender = nullptr;
};

