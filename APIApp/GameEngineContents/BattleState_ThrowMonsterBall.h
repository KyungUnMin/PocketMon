#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_ThrowMonsterBall : public BattleStateBase
{
public:
	BattleState_ThrowMonsterBall();
	~BattleState_ThrowMonsterBall() override;

	BattleState_ThrowMonsterBall(const BattleState_ThrowMonsterBall& _Other) = delete;
	BattleState_ThrowMonsterBall(BattleState_ThrowMonsterBall&& _Other) noexcept = delete;
	BattleState_ThrowMonsterBall& operator=(const BattleState_ThrowMonsterBall& _Other) = delete;
	BattleState_ThrowMonsterBall& operator=(const BattleState_ThrowMonsterBall&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	//void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BackTextActor* TextInfoUI = nullptr;
};

