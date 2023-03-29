#include "BattleState_BattleWin.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"

BattleState_BattleWin::BattleState_BattleWin()
{

}

BattleState_BattleWin::~BattleState_BattleWin()
{

}

void BattleState_BattleWin::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("We Win");
}

void BattleState_BattleWin::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
		return;
	
	if (true == IsFadeCreated)
		return;

	IsFadeCreated = true;
	BattleFadeCtrl* Fade = BattleLevel::BattleLevelPtr->CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	Fade->SetDuration(1.f);
	Fade->Init(BattleFadeCtrl::FadeType::BlackOut, []
	{
		BattleLevel::BattleLevelPtr->ChangeFieldLevel();
	});
}

void BattleState_BattleWin::ExitState()
{
	Timer = 0.f;
	IsFadeCreated = false;
}
