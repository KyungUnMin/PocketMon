#include "BattleState_StageWin.h"
#include "BattleEnemy.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleMonsterEnemy.h"

BattleState_StageWin::BattleState_StageWin()
{

}

BattleState_StageWin::~BattleState_StageWin()
{

}

void BattleState_StageWin::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("We Kill That");

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	EnemyMonster->KillMonster();
}

void BattleState_StageWin::Update(float _DeltaTime)
{

}

void BattleState_StageWin::ExitState()
{
	TextInfo->Death();


	//BattleEnemy::EnemyPtr->CreateMonster();
}
