#pragma once
#include "BattleStateBase.h"
#include <vector>
#include <string_view>
#include "PokeSkillBase.h"
#include "PokeBattleSystem.h"

class BackTextActor;
enum class BattleEnemyMonster_StateType;
enum class PokeSkill;

class BattleState_EnemyTurn : public BattleStateBase
{
public:
	BattleState_EnemyTurn();
	~BattleState_EnemyTurn() override;

	BattleState_EnemyTurn(const BattleState_EnemyTurn& _Other) = delete;
	BattleState_EnemyTurn(BattleState_EnemyTurn&& _Other) noexcept = delete;
	BattleState_EnemyTurn& operator=(const BattleState_EnemyTurn& _Other) = delete;
	BattleState_EnemyTurn& operator=(const BattleState_EnemyTurn&& _Other) noexcept = delete;

	static BattleScript GetBattleResult()
	{
		return BattleResultType;
	}

protected:
	void EnterState() override;
	void ExitState() override;

private:
	static const std::string_view ConvertSkillNames[static_cast<size_t>(PokeSkill::Unknown)];
	static BattleScript BattleResultType;
	

	BackTextActor* TextInfoUI = nullptr;
	PokeDataBase* EnemyDB = nullptr;
	int SelectedSkill = -1;

	BattleEnemyMonster_StateType ConvertSkill(PokeSkill _SkillType);
	const std::string  MakeEnemyText(PokeSkill _SkillType);
};

