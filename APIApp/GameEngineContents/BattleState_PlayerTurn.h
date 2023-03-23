#pragma once
#include "BattleStateBase.h"

class Battle_Select;

class BattleState_PlayerTurn : public BattleStateBase
{
public:
	BattleState_PlayerTurn();
	~BattleState_PlayerTurn() override;

	BattleState_PlayerTurn(const BattleState_PlayerTurn& _Other) = delete;
	BattleState_PlayerTurn(BattleState_PlayerTurn&& _Other) noexcept = delete;
	BattleState_PlayerTurn& operator=(const BattleState_PlayerTurn& _Other) = delete;
	BattleState_PlayerTurn& operator=(const BattleState_PlayerTurn&& _Other) noexcept = delete;

protected:
	void Start() override;
	void EnterState() override;

private:
	Battle_Select* SelectBoard = nullptr;

};

