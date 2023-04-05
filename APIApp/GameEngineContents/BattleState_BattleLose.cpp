#include "BattleState_BattleLose.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleEnemy.h"


BattleState_BattleLose::BattleState_BattleLose()
{

}

BattleState_BattleLose::~BattleState_BattleLose()
{

}


void BattleState_BattleLose::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("My eyes\nis going to black");

	if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
		return;

	if (true == BattleLevel::BattleLevelPtr->IsBossBattle())
		return;

	BattleEnemy::EnemyPtr->ComeBack();
}

void BattleState_BattleLose::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	if (true == IsLevelChanged)
		return;

	BattleLevel::BattleLevelPtr->ChangeFieldLevel(false);
	IsLevelChanged = true;
}

void BattleState_BattleLose::ExitState()
{
	if (false == TextInfo->IsDeath())
	{
		TextInfo->Death();
		TextInfo = nullptr;
	}

}