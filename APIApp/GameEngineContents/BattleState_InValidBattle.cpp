#include "BattleState_InValidBattle.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFSM.h"


BattleState_InValidBattle::BattleState_InValidBattle()
{

}

BattleState_InValidBattle::~BattleState_InValidBattle()
{

}

void BattleState_InValidBattle::EnterState()
{
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfoUI->BattleSetText("There`s no Pokemon\nto fight with_");
}

void BattleState_InValidBattle::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	GetFSM()->ChangeState(BattleStateType::BattleLose);
}

void BattleState_InValidBattle::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
