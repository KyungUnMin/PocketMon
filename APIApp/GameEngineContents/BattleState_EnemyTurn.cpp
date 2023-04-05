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

	PokeDataBase* MonsterDB = EnemyMonster->GetDB();
	int MaxCount = MonsterDB->GetMonsterSkillCount();
	int SelectedSkill = GameEngineRandom::MainRandom.RandomInt(1, MaxCount);

	PokeSkillBase& SkillDB = MonsterDB->GetMonsterSkillList(SelectedSkill);

	PokeSkill SkillType = SkillDB.GetSkill();
	if (PokeSkill::Unknown == SkillType)
	{
		MsgAssert("적 몬스터가 알 수 없는 스킬을 사용했습니다");
		return;
	}

	TextInfoUI->BattleSetText(MakeEnemyText(SkillType));
	
	//실제 게임용입니다.
	EnemyMonster->GetFSM()->ChangeState(ConvertSkill(SkillType));

	//스킬 확인용입니다
	//EnemyMonster->GetFSM()->ChangeState(BattleEnemyMonster_StateType::Skill_WaterGun);
}

const std::string BattleState_EnemyTurn::MakeEnemyText(PokeSkill _SkillType)
{
	std::string ReturnStr = "";
	if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
	{
		ReturnStr = "The wild Pokemon\nused ";
	}
	else
	{
		ReturnStr = "The Enemy Pokemon\nused ";
	}

	ReturnStr += ConvertSkillNames[static_cast<size_t>(_SkillType)].data();

	ReturnStr += " to acttack";

	return ReturnStr;
}



void BattleState_EnemyTurn::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;

	//임시코드
	PokeDataBase* EnemyDB =  BattleEnemy::EnemyPtr->GetMonsterDB();
	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	PokeDataBase* PlayerDB = PlayerMonster->GetDB();
	PokeBattleSystem::Battle(*EnemyDB, 1, *PlayerDB);
	int Damage = PokeBattleSystem::GetDamage();
	PlayerMonster->DamageOnIU(Damage);
}
