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

	//GameEngineRandom::MainRandom.RandomInt(1, )
	//PokeSkillBase& SkillDB = MonsterDB->GetMonsterSkillList();


	EnemyMonster->GetFSM()->ChangeState(BattleEnemyMonster_StateType::Skill_Bubble);
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
