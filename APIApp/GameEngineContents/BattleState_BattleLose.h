#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_BattleLose : public BattleStateBase
{
public:
	BattleState_BattleLose();
	~BattleState_BattleLose() override;

	BattleState_BattleLose(const BattleState_BattleLose& _Other) = delete;
	BattleState_BattleLose(BattleState_BattleLose&& _Other) noexcept = delete;
	BattleState_BattleLose& operator=(const BattleState_BattleLose& _Other) = delete;
	BattleState_BattleLose& operator=(const BattleState_BattleLose&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BackTextActor* TextInfo = nullptr;
	bool IsLevelChanged = false;
	float Timer = 0.f;
	float Duration = 1.0f;

	void MakeText();
};

