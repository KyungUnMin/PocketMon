#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_EnemyTurn : public BattleStateBase
{
public:
	BattleState_EnemyTurn();
	~BattleState_EnemyTurn() override;

	BattleState_EnemyTurn(const BattleState_EnemyTurn& _Other) = delete;
	BattleState_EnemyTurn(BattleState_EnemyTurn&& _Other) noexcept = delete;
	BattleState_EnemyTurn& operator=(const BattleState_EnemyTurn& _Other) = delete;
	BattleState_EnemyTurn& operator=(const BattleState_EnemyTurn&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void ExitState() override;

private:
	BackTextActor* TextInfoUI = nullptr;
};

