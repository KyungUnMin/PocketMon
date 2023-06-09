#pragma once
#include "BattleStateBase.h"
#include <functional>
#include "PokeBattleSystem.h"

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

	static BattleScript GetBattleResult()
	{
		return BattleResultType;
	}

	static const std::string_view& GetUsedSkillName()
	{
		return ConvertSkillNames[static_cast<size_t>(UseSkill)];
	}

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	static const std::string_view ConvertSkillNames[static_cast<size_t>(PokeSkill::Unknown)];
	static BattleScript BattleResultType;
	static PokeSkill UseSkill;
	

	Battle_Select* SelectBoard = nullptr;
	BattleCommendActor* BattleCommand = nullptr;
	BackTextActor* TextInfo = nullptr;
	std::function<void()> DamageCalcFunc = nullptr;
	bool WasRun = false;

	void BindSelectBoard();
	void BindBattleCommand(int _SlotIndex);

	void BattleCmdOpen();

	BattlePlayerMonster_StateType ConvertSkill(PokeSkill _SkillType);

	void CreateHpUI();
	void SelectRunAway();
};

