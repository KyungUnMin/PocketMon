#include "BattleMonsterBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PokeDataBase.h"
#include "BattleMonster_Bulbasaur.h"

BattleMonsterBase* BattleMonsterBase::CreateMonster(GameEngineLevel* _Level, PokeNumber _MonType, bool _IsPlayerMonster)
{
	BattleMonsterBase* MonsterPtr = nullptr;

	switch (_MonType)
	{
	case PokeNumber::Bulbasaur:
		MonsterPtr = _Level->CreateActor<BattleMonster_Bulbasaur>();
		break;
	case PokeNumber::Ivysaur:
		break;
	case PokeNumber::Venusaur:
		break;
	case PokeNumber::Charmander:
		break;
	case PokeNumber::Charmeleon:
		break;
	case PokeNumber::Charizard:
		break;
	case PokeNumber::Squirtle:
		break;
	case PokeNumber::Wartortle:
		break;
	case PokeNumber::Blastoise:
		break;
	case PokeNumber::Pidgey:
		break;
	case PokeNumber::Rattata:
		break;
	case PokeNumber::Spearow:
		break;
	case PokeNumber::Geodude:
		break;
	case PokeNumber::Onix:
		break;
	}

	if (nullptr == MonsterPtr)
	{
		MsgAssert("���� �ش� ���Ϳ� ���� Ŭ������ ����������� �ʾҽ��ϴ�");
		return nullptr;
	}

	MonsterPtr->Init(_IsPlayerMonster);
	MonsterPtr->DbPtr = PokeDataBase::PokeCreate(static_cast<int>(_MonType) + 1);
	return MonsterPtr;
}

BattleMonsterBase::BattleMonsterBase()
{

}

BattleMonsterBase::~BattleMonsterBase()
{

}
