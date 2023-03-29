#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_BattleWin : public BattleStateBase
{
public:
	BattleState_BattleWin();
	~BattleState_BattleWin() override;

	BattleState_BattleWin(const BattleState_BattleWin& _Other) = delete;
	BattleState_BattleWin(BattleState_BattleWin&& _Other) noexcept = delete;
	BattleState_BattleWin& operator=(const BattleState_BattleWin& _Other) = delete;
	BattleState_BattleWin& operator=(const BattleState_BattleWin&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	float Timer = 0.f;
	const float Duration = 1.f;
	bool IsFadeCreated = false;

	BackTextActor* TextInfo = nullptr;
};

