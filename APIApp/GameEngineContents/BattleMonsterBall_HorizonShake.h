#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattleMonsterBall_HorizonShake : public BattleStateBase
{
public:
	BattleMonsterBall_HorizonShake();
	~BattleMonsterBall_HorizonShake() override;

	BattleMonsterBall_HorizonShake(const BattleMonsterBall_HorizonShake& _Other) = delete;
	BattleMonsterBall_HorizonShake(BattleMonsterBall_HorizonShake&& _Other) noexcept = delete;
	BattleMonsterBall_HorizonShake& operator=(const BattleMonsterBall_HorizonShake& _Other) = delete;
	BattleMonsterBall_HorizonShake& operator=(const BattleMonsterBall_HorizonShake&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;

private:
	class GameEngineRender* BallRender = nullptr;
	const float Range = 20.f;

	float LiveTime = 0.f;
	const float Duration = 3.f;
};

