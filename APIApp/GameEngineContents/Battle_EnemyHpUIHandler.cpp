#include "Battle_EnemyHpUIHandler.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "EnemyHPBackground.h"

Battle_EnemyHpUIHandler::Battle_EnemyHpUIHandler()
{

}

Battle_EnemyHpUIHandler::~Battle_EnemyHpUIHandler()
{

}



void Battle_EnemyHpUIHandler::Start()
{
	BattleMonsterEnemy* Monster = BattleEnemy::EnemyPtr->GetMonster();
	if (nullptr == Monster)
	{
		MsgAssert("플레이어 몬스터가 생성된 이후에 이 UI를 생성할 수 있습니다");
		return;
	}

	SetOwner(Monster);

	UI = GetLevel()->CreateActor<EnemyHPBackground>(UpdateOrder::Battle_Actors);
	//UI->IsBattleStartCheck(true);
	SetUI(UI);

	SetMovePoints(StartOffset, DestOffset);
	SetOffset(Offset);
}

void Battle_EnemyHpUIHandler::OnDamage(int _Value)
{
	UI->GetPlayerDamage(static_cast<float>(_Value));
	UI->IsBattleStartCheck(true);
}