#include "BattleState_CatchWhildMonster.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "PocketMonCore.h"

BattleState_CatchWhildMonster::BattleState_CatchWhildMonster()
{

}

BattleState_CatchWhildMonster::~BattleState_CatchWhildMonster()
{

}

void BattleState_CatchWhildMonster::EnterState()
{
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfoUI->BattleSetText("I got you");
}


void BattleState_CatchWhildMonster::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (LiveTime < FadeTime)
		return;

	if (nullptr != FadeCtrl)
		return;

	FadeCtrl = BattleLevel::BattleLevelPtr->CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	FadeCtrl->Init(BattleFadeCtrl::FadeType::WhiteOut, []
	{
		PocketMonCore::GetInst().ChangeLevel("FieldmapLevel");
	});

	FadeCtrl->SetDuration(1.5f);
}

void BattleState_CatchWhildMonster::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
