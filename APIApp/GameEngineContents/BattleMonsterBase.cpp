#include "BattleMonsterBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PokeDataBase.h"
#include "ContentsEnum.h"



BattleMonsterBase::BattleMonsterBase()
{
	
}

BattleMonsterBase::~BattleMonsterBase()
{

}



void BattleMonsterBase::Init(PokeNumber _MonsterType)
{
	switch (_MonsterType)
	{
	case PokeNumber::Bulbasaur:
		SetName("Bulbasaur");
		break;
	case PokeNumber::Ivysaur:
		SetName("Ivysaur");
		break;
	case PokeNumber::Venusaur:
		SetName("Venusaur");
		break;
	case PokeNumber::Charmander:
		SetName("Charmander");
		break;
	case PokeNumber::Charmeleon:
		SetName("Charmeleon");
		break;
	case PokeNumber::Charizard:
		SetName("Charizard");
		break;
	case PokeNumber::Squirtle:
		SetName("Squirtle");
		break;
	case PokeNumber::Wartortle:
		SetName("Wartortle");
		break;
	case PokeNumber::Blastoise:
		SetName("Blastoise");
		break;
	case PokeNumber::Pidgey:
		SetName("Pidgey");
		break;
	case PokeNumber::Rattata:
		SetName("Rattata");
		break;
	case PokeNumber::Spearow:
		SetName("Spearow");
		break;
	case PokeNumber::Geodude:
		SetName("Geodude");
		break;
	case PokeNumber::Onix:
		SetName("Onix");
		break;
	}

	DbPtr = PokeDataBase::PokeCreate(static_cast<int>(_MonsterType) + 1);
}






