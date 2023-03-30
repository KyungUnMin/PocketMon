#include "BattleState_BattleWin.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "LevelUpStatUI_2.h"

#include "Battle_HpUIHandlerBase.h"
#include "FriendlyHPBackground.h"

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

	//LevelUpStatUI_2* ResultUI = BattleLevel::BattleLevelPtr->CreateActor<LevelUpStatUI_2>(UpdateOrder::Battle_Actors);
	//ResultUI->SetPos(float4{ 450.f, 70.f });

	Battle_HpUIHandlerBase* HpUI = BattlePlayer::PlayerPtr->GetMonster()->GetHpUI();
	HpUI->ExpCheck();
}

void BattleState_BattleWin::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;
	
	if (nullptr != Fade)
		return;

	Fade = BattleLevel::BattleLevelPtr->CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	Fade->SetDuration(1.f);
	Fade->Init(BattleFadeCtrl::FadeType::BlackOut, []
	{
		BattleLevel::BattleLevelPtr->ChangeFieldLevel();
	});

}

void BattleState_BattleWin::ExitState()
{
	Timer = 0.f;
}
