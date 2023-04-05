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

	case PokeNumber::Bulbasaur:
		return SpecialPokeEnum::CatchBulbasaur;

	case PokeNumber::Charmander:
		return SpecialPokeEnum::CatchCharmander;

	case PokeNumber::Squirtle:
		return SpecialPokeEnum::CatchSquirtle;

	case PokeNumber::Geodude:
		return SpecialPokeEnum::CatchGeodude;

	case PokeNumber::Pikachu:
		return SpecialPokeEnum::CatchPikachu;

	default:
	{
		MsgAssert("�߻������� ������ ���� ���ϸ��Դϴ�");
		break;
	}
	}

	return SpecialPokeEnum::CatchPikachu;
}
