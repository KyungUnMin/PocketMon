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
	TextInfoUI->BattleSetText("Enemy Attacking...");

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();

	PokeDataBase* MonsterDB = EnemyMonster->GetDB();
	int MaxCount = MonsterDB->GetMonsterSkillCount();
	int SelectedSkill = GameEngineRandom::MainRandom.RandomInt(1, MaxCount);

	PokeSkillBase& SkillDB = MonsterDB->GetMonsterSkillList(SelectedSkill);
	
	//스킬 확인용
	EnemyMonster->GetFSM()->ChangeState(BattleEnemyMonster_StateType::Skill_Thunder);

	//실제 게임용, 적 몬스터 랜덤 공격
	//EnemyMonster->GetFSM()->ChangeState(ConvertSkill(SkillDB.GetSkill()));
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
