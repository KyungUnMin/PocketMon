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
		MsgAssert("�÷��̾� ���Ͱ� ������ ���Ŀ� �� UI�� ������ �� �ֽ��ϴ�");
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
	UI->GetPlayerDamage(_Value);
	UI->IsBattleStartCheck(true);
}