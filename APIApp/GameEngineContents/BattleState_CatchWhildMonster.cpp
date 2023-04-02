#include "BattleState_CatchWhildMonster.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "PocketMonCore.h"
#include "BattleEnemy.h"
#include "Player.h"

BattleState_CatchWhildMonster::BattleState_CatchWhildMonster()
{

}

BattleState_CatchWhildMonster::~BattleState_CatchWhildMonster()
{

}

void BattleState_CatchWhildMonster::EnterState()
{
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfoUI->BattleSetText("I got you");
}


void BattleState_CatchWhildMonster::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (LiveTime < FadeTime)
		return;

	if (true == IsPushed)
		return;

	IsPushed = true;
	PokeDataBase* EnemyDB = BattleEnemy::EnemyPtr->GetMonsterDB();
	TrainerPokemon* PlayerMonsters = Player::MainPlayer->GetPlayerPokemon();
	PlayerMonsters->AddPokemon(*EnemyDB);
	BattleLevel::BattleLevelPtr->ChangeFieldLevel(true);
}

void BattleState_CatchWhildMonster::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
