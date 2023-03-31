#pragma once
#include "BattleStateBase.h"

class BattleState_ChangeMonster : public BattleStateBase
{
public:
	BattleState_ChangeMonster();
	~BattleState_ChangeMonster() override;

	BattleState_ChangeMonster(const BattleState_ChangeMonster& _Other) = delete;
	BattleState_ChangeMonster(BattleState_ChangeMonster&& _Other) noexcept = delete;
	BattleState_ChangeMonster& operator=(const BattleState_ChangeMonster& _Other) = delete;
	BattleState_ChangeMonster& operator=(const BattleState_ChangeMonster&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	float Timer = 0.f;
	const float Duration = 3.f;
	class BackTextActor* TextInfo = nullptr;
};

