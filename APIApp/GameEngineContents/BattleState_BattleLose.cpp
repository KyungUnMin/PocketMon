#include "BattleState_BattleLose.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"

BattleState_BattleLose::BattleState_BattleLose()
{

}

BattleState_BattleLose::~BattleState_BattleLose()
{

}


void BattleState_BattleLose::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("My eyes is going to black");
}

void BattleState_BattleLose::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	if (nullptr != Fade)
		return;

	Fade = BattleLevel::BattleLevelPtr->CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	Fade->Init(BattleFadeCtrl::FadeType::BlackOut, []
	{
		BattleLevel::BattleLevelPtr->ChangeFieldLevel();
	});
}

void BattleState_BattleLose::ExitState()
{
	if (false == TextInfo->IsDeath())
	{
		TextInfo->Death();
		TextInfo = nullptr;
	}

	if (false == Fade->IsDeath())
	{
		Fade->Death();
		Fade = nullptr;
	}

}