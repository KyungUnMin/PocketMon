#pragma once
#include "BattleStateBase.h"

class BattleMonsterBall;

class BattleMonsterBall_OpenState : public BattleStateBase
{
public:
	BattleMonsterBall_OpenState();
	~BattleMonsterBall_OpenState() override;

	BattleMonsterBall_OpenState(const BattleMonsterBall_OpenState& _Other) = delete;
	BattleMonsterBall_OpenState(BattleMonsterBall_OpenState&& _Other) noexcept = delete;
	BattleMonsterBall_OpenState& operator=(const BattleMonsterBall_OpenState& _Other) = delete;
	BattleMonsterBall_OpenState& operator=(const BattleMonsterBall_OpenState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	float Timer = 0.f;
	float Duration = 0.f;
};

