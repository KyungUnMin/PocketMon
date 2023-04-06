#include "BattleState_EnemyTurn.h"
#include <GameEngineBase/GameEngineRandom.h>
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyMonsterFSM.h"
#include "BattlePlayer.h"
#include "PokeBattleSystem.h"
#include "BattleMonsterPlayer.h"

BattleScript BattleState_EnemyTurn::BattleResultType = BattleScript::Nothing;
PokeSkill BattleState_EnemyTurn::UseSkill = PokeSkill::Unknown;

BattleState_EnemyTurn::BattleState_EnemyTurn()
{

}

BattleState_EnemyTurn::~BattleState_EnemyTurn()
{

}

void BattleState_EnemyTurn::EnterState()
{
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();

	EnemyDB = EnemyMonster->GetDB();
	int MaxCount = EnemyDB->GetMonsterSkillCount();
	SelectedSkill = GameEngineRandom::MainRandom.RandomInt(1, MaxCount);

	PokeSkillBase& SkillDB = EnemyDB->GetMonsterSkillList(SelectedSkill);

	UseSkill = SkillDB.GetSkill();
	if (PokeSkill::Unknown == UseSkill)
	{
		MsgAssert("적 몬스터가 알 수 없는 스킬을 사용했습니다");
		return;
	}

	TextInfoUI->BattleSetText(MakeEnemyText(EnemyMonster, UseSkill));
	
	//실제 게임용입니다.
	EnemyMonster->GetFSM()->ChangeState(ConvertSkill(UseSkill));

	//스킬 확인용입니다
	//EnemyMonster->GetFSM()->ChangeState(BattleEnemyMonster_StateType::Skill_WaterGun);
}

const std::string BattleState_EnemyTurn::MakeEnemyText(BattleMonsterEnemy* _EnemyMonster, PokeSkill _SkillType)
{
	std::string ReturnStr = "";


	if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
	{
		ReturnStr = "Foe Wild " + _EnemyMonster->GetName() + " used\n";
	}
	else
	{
		ReturnStr = "Foe " + _EnemyMonster->GetName() + " used\n";
	}

	ReturnStr += ConvertSkillNames[static_cast<size_t>(_SkillType)].data();

	ReturnStr += " to acttack";

	return ReturnStr;
}



void BattleState_EnemyTurn::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;

	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	PokeDataBase* PlayerDB = PlayerMonster->GetDB();

	BattleResultType = PokeBattleSystem::Battle(*EnemyDB, SelectedSkill, *PlayerDB);
	SelectedSkill = -1;

	int Damage = PokeBattleSystem::GetDamage();
	PlayerMonster->DamageOnIU(Damage);
}
