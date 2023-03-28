#include "BattleState_EnemyHPCheck.h"
#include "BattleEnemy.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "PokeDataBase.h"
#include "BattleFSM.h"

BattleState_EnemyHPCheck::BattleState_EnemyHPCheck()
{

}

BattleState_EnemyHPCheck::~BattleState_EnemyHPCheck()
{

}

void BattleState_EnemyHPCheck::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("My Attack was Good");

	PokeDataBase* MonsterDB = BattleEnemy::EnemyPtr->GetMonsterDB();
	int EnemyHP = MonsterDB->GetMonsterCurrentHP();

	if (0 < EnemyHP)
	{
		NextState = static_cast<int>(BattleStateType::EnemyTurn);
	}
	else
	{
		NextState = static_cast<int>(BattleStateType::StageWin);
	}
	
}

void BattleState_EnemyHPCheck::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < NextStateTime)
		return;

	GetFSM()->ChangeState(NextState);
}

void BattleState_EnemyHPCheck::ExitState()
{
	Timer = 0.f;
	TextInfo->Death();
	NextState = -1;
}
