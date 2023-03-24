#include "BattleState_ThrowMonsterBall.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "Battle_PlayerThrowBall.h"
#include "BattleEnemy.h"

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

	float4 Dest = BattleEnemy::EnemyPtr->GetPos();
	Battle_PlayerThrowBall* MonsterBall = BattleLevel::BattleLevelPtr->CreateActor<Battle_PlayerThrowBall>(UpdateOrder::Battle_Actors);
	MonsterBall->Init(Dest, 1.f, -Dest.x);
	MonsterBall->SetGravityAcc(400.f);
}

void BattleState_ThrowMonsterBall::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
