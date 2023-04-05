#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_EnemyHPCheck : public BattleStateBase
{
public:
	BattleState_EnemyHPCheck();
	~BattleState_EnemyHPCheck() override;

	BattleState_EnemyHPCheck(const BattleState_EnemyHPCheck& _Other) = delete;
	BattleState_EnemyHPCheck(BattleState_EnemyHPCheck&& _Other) noexcept = delete;
	BattleState_EnemyHPCheck& operator=(const BattleState_EnemyHPCheck& _Other) = delete;
	BattleState_EnemyHPCheck& operator=(const BattleState_EnemyHPCheck&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	float Timer = 0.f;
	const float NextStateTime = 1.f;

	BackTextActor* TextInfo = nullptr;
	int NextState = -1;

	void SelectText();
};

