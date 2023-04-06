#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_InValidBattle : public BattleStateBase
{
public:
	BattleState_InValidBattle();
	~BattleState_InValidBattle() override;

	BattleState_InValidBattle(const BattleState_InValidBattle& _Other) = delete;
	BattleState_InValidBattle(BattleState_InValidBattle&& _Other) noexcept = delete;
	BattleState_InValidBattle& operator=(const BattleState_InValidBattle& _Other) = delete;
	BattleState_InValidBattle& operator=(const BattleState_InValidBattle&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BackTextActor* TextInfoUI = nullptr;
	float Timer = 0.f;
	const float Duration = 2.f;
};

