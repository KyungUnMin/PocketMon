#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_PlayerHPCheck : public BattleStateBase
{
public:
	BattleState_PlayerHPCheck();
	~BattleState_PlayerHPCheck() override;

	BattleState_PlayerHPCheck(const BattleState_PlayerHPCheck& _Other) = delete;
	BattleState_PlayerHPCheck(BattleState_PlayerHPCheck&& _Other) noexcept = delete;
	BattleState_PlayerHPCheck& operator=(const BattleState_PlayerHPCheck& _Other) = delete;
	BattleState_PlayerHPCheck& operator=(const BattleState_PlayerHPCheck&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	float Timer = 0.f;
	const float NextStateTime = 2.5f;

	BackTextActor* TextInfo = nullptr;
	int NextState = -1;

	void SelectText();
};

