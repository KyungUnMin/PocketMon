#pragma once
#include "BattleStateBase.h"
#include <functional>

class Battle_Select;
class BattleCommendActor;
class BackTextActor;
class BattleSkillBase;
enum class PokeSkill;
enum class BattlePlayerMonster_StateType;

class BattleState_PlayerTurn : public BattleStateBase
{
public:
	BattleState_PlayerTurn();
	~BattleState_PlayerTurn() override;

	BattleState_PlayerTurn(const BattleState_PlayerTurn& _Other) = delete;
	BattleState_PlayerTurn(BattleState_PlayerTurn&& _Other) noexcept = delete;
	BattleState_PlayerTurn& operator=(const BattleState_PlayerTurn& _Other) = delete;
	BattleState_PlayerTurn& operator=(const BattleState_PlayerTurn&& _Other) noexcept = delete;

	inline void SetCallBack(const std::function<void()>& _CallBack)
	{
		DamageCalcFunc = _CallBack;
	}

protected:
	void EnterState() override;
	void ExitState() override;

private:
	Battle_Select* SelectBoard = nullptr;
	BattleCommendActor* BattleCommand = nullptr;
	BackTextActor* TextInfo = nullptr;
	std::function<void()> DamageCalcFunc = nullptr;

	void BindSelectBoard();
	void BindBattleCommand(int _SlotIndex);

	void BattleCmdOpen();

	BattlePlayerMonster_StateType ConvertSkill(PokeSkill _SkillType);
};

