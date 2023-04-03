#include "BattleState_CatchWhildMonster.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "PocketMonCore.h"
#include "BattleEnemy.h"
#include "Player.h"
#include "PokeDataBase.h"

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
	PokeNumber MonsterNum = EnemyDB->GetPokeNumber_enum();

	int Level = EnemyDB->GetMonsterLevel_int();
	SpecialPokeEnum ConvertEnum = PokeNumToSpecialConvertor(MonsterNum);
	PokeDataBase CatchedMonster = PokeDataBase::SpecialPokeCreate(ConvertEnum, Level);
	CatchedMonster.SetMonsterCurrentHP(EnemyDB->GetMonsterCurrentHP());

	TrainerPokemon* PlayerMonsters = Player::MainPlayer->GetPlayerPokemon();
	//PlayerMonsters->AddPokemon(*EnemyDB);
	PlayerMonsters->AddPokemon(CatchedMonster);



	/*
	SpecialPokeEnum a;*/
	

	BattleLevel::BattleLevelPtr->ChangeFieldLevel(true);
}

void BattleState_CatchWhildMonster::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}



SpecialPokeEnum BattleState_CatchWhildMonster::PokeNumToSpecialConvertor(PokeNumber _Index)
{
	switch (_Index)
	{
	case PokeNumber::Pidgey:
		return SpecialPokeEnum::CatchPidgey;

	case PokeNumber::Rattata:
		return SpecialPokeEnum::CatchRattata;

	case PokeNumber::Spearow:
		return SpecialPokeEnum::CatchSpearow;

	case PokeNumber::Pikachu:
		return SpecialPokeEnum::CatchPikachu;

	case PokeNumber::Geodude:
	{
		MsgAssert("아직 꼬마돌에 대한 처리는 하지 않았습니다");
		break;
	}
	default:
	{
		MsgAssert("야생에서는 잡을수 없는 포켓몬입니다");
		break;
	}
	}

	return SpecialPokeEnum::CatchPikachu;
}
