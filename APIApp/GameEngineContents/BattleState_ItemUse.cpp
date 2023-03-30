#include "BattleState_ItemUse.h"
#include "BattleFadeCtrl.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BackTextActor.h"


BattleState_ItemUse::BattleState_ItemUse()
{
}

BattleState_ItemUse::~BattleState_ItemUse()
{

}

void BattleState_ItemUse::EnterState()
{
	IsAction = false;

	BattleFadeCtrl* Fade = BattleLevel::BattleLevelPtr->CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	Fade->Init(BattleFadeCtrl::FadeType::BlackIn, [&]
	{
		IsAction = true;
	});

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("Delecious");
}

void BattleState_ItemUse::Update(float _DeltaTime)
{
	if (false == IsAction)
		return;

	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	GetFSM()->ChangeState(BattleStateType::EnemyTurn);
}

void BattleState_ItemUse::ExitState()
{
	IsAction = false;
	Timer = 0.f;

	TextInfo->Death();
}
