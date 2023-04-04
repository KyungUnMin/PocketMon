#pragma once
#include "BattleStateBase.h"

class GameEngineRender;
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

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	BattleMonsterBall* MonsterBall = nullptr;
	GameEngineRender* BallRender = nullptr;
};

