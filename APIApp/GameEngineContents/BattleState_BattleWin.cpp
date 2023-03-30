#include "BattleState_BattleWin.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "LevelUpStatUI_2.h"

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
	ResultUI = BattleLevel::BattleLevelPtr->CreateActor<LevelUpStatUI_2>(UpdateOrder::Battle_Actors);
	ResultUI->SetPos(float4{ 450.f, 70.f });
}

void BattleState_BattleWin::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;
	
	if (0 == Step)
	{
		TextInfo->BattleSetText("");
		/*UI1 = BattleLevel::BattleLevelPtr->CreateActor<LevelUpStatUI>(UpdateOrder::Battle_Actors);
		UI1->SetPos(float4{})*/
	}
	else if (1 == Step)
	{
		TextInfo->BattleSetText("");

		/*if (nullptr != UI1)
		{
			UI1->Death();
		}

		UI2 = BattleLevel::BattleLevelPtr->CreateActor<LevelUpStatUI_2>(UpdateOrder::Battle_Actors);*/
	}
	else if (2 == Step)
	{
		BattleFadeCtrl* Fade = BattleLevel::BattleLevelPtr->CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
		Fade->SetDuration(1.f);
		Fade->Init(BattleFadeCtrl::FadeType::BlackOut, []
		{
			BattleLevel::BattleLevelPtr->ChangeFieldLevel();
		});

		/*if (nullptr != UI2)
		{
			UI2->Death();
		}*/
	}

	++Step;
	Timer -= Duration;
}

void BattleState_BattleWin::ExitState()
{
	Timer = 0.f;
	Step = 0;
}
