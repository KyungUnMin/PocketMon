#pragma once
#include "BattleStateBase.h"
#include "BattleMonsterBall_ThrowBase.h"

class GameEngineRender;

class BattleMonsterBall_ThrowToCreate : public BattleMonsterBall_ThrowBase
{
public:
	BattleMonsterBall_ThrowToCreate();
	~BattleMonsterBall_ThrowToCreate() override;

	BattleMonsterBall_ThrowToCreate(const BattleMonsterBall_ThrowToCreate& _Other) = delete;
	BattleMonsterBall_ThrowToCreate(BattleMonsterBall_ThrowToCreate&& _Other) noexcept = delete;
	BattleMonsterBall_ThrowToCreate& operator=(const BattleMonsterBall_ThrowToCreate& _Other) = delete;
	BattleMonsterBall_ThrowToCreate& operator=(const BattleMonsterBall_ThrowToCreate&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitExcute() override;

private:
	GameEngineRender* BallRender = nullptr;

	const float Range = 300.f;
	const float WaitTime = 0.2f;
};

