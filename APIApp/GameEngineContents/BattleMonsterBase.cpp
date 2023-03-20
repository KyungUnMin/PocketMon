#include "BattleMonsterBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PokeDataBase.h"
#include "BattleMonster_Bulbasaur.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

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
		MsgAssert("아직 해당 몬스터에 대한 클래스와 연결시켜주지 않았습니다");
		return nullptr;
	}

	MonsterPtr->Init(_IsPlayerMonster);
	MonsterPtr->SetTeam(_IsPlayerMonster);
	MonsterPtr->DbPtr = PokeDataBase::PokeCreate(static_cast<int>(_MonType) + 1);
	return MonsterPtr;
}

BattleMonsterBase::BattleMonsterBase()
{

}

BattleMonsterBase::~BattleMonsterBase()
{

}

void BattleMonsterBase::Update(float _DeltaTime)
{
	BattleTrainerBase* Target = nullptr;
	if (true == IsPlayerMonter)
	{
		Target = BattlePlayer::PlayerPtr;
	}
	else
	{
		Target = BattleEnemy::NpcPtr;
	}

	if (nullptr == Target)
	{
		MsgAssert("몬스터의 움직임 기준이 될 타켓이 존재하지 않습니다");
		return;
	}

	SetPos(Target->GetPos() + Offset);
}
