#pragma once
#include "BattleStateBase.h"

class Battle_Select;
class BattleCommendActor;
class BackTextActor;
class BattleSkillBase;
enum class PokeSkill;

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
	void EnterState() override;
	void ExitState() override;

private:
	Battle_Select* SelectBoard = nullptr;
	BattleCommendActor* BattleCommand = nullptr;
	BackTextActor* TextInfo = nullptr;

	void BindSelectBoard();
	void BindBattleCommand(size_t _SlotIndex);

	void BattleCmdOpen();
};

