#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_UnlockWildMonster : public BattleStateBase
{
public:
	BattleState_UnlockWildMonster();
	~BattleState_UnlockWildMonster() override;

	BattleState_UnlockWildMonster(const BattleState_UnlockWildMonster& _Other) = delete;
	BattleState_UnlockWildMonster(BattleState_UnlockWildMonster&& _Other) noexcept = delete;
	BattleState_UnlockWildMonster& operator=(const BattleState_UnlockWildMonster& _Other) = delete;
	BattleState_UnlockWildMonster& operator=(const BattleState_UnlockWildMonster&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	float Timer = 0.f;
	const float Duration = 3.f;
	BackTextActor* TextInfo = nullptr;

};

