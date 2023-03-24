#include "BattleState_ThrowMonsterBall.h"
#include "BackTextActor.h"
#include "BattleLevel.h"

BattleState_ThrowMonsterBall::BattleState_ThrowMonsterBall()
{

}

BattleState_ThrowMonsterBall::~BattleState_ThrowMonsterBall()
{

}

void BattleState_ThrowMonsterBall::EnterState()
{
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	//TextInfoUI->BattleSetText("")
}

void BattleState_ThrowMonsterBall::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
