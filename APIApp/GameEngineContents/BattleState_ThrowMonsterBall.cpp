#include "BattleState_ThrowMonsterBall.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyMonsterFSM.h"

BattleState_ThrowMonsterBall::BattleState_ThrowMonsterBall()
{

}

BattleState_ThrowMonsterBall::~BattleState_ThrowMonsterBall()
{

}

void BattleState_ThrowMonsterBall::EnterState()
{
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfoUI->BattleSetText("You are mine");

	BattleEnemy* Enemy = BattleEnemy::EnemyPtr;
	float4 Dest = Enemy->GetPos();
	

	BattleEnemyMonsterFSM* EnemyMonsterFSM = Enemy->GetMonster()->GetFSM();
	//EnemyMonsterFSM->ChangeState(BattleEnemyMonster_StateType::)
}

void BattleState_ThrowMonsterBall::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
