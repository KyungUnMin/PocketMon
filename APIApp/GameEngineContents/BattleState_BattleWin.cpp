#include "BattleState_BattleWin.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "LevelUpStatUI_2.h"

#include "Battle_HpUIHandlerBase.h"
#include "FriendlyHPBackground.h"
#include "Battle_PlayerHpUIHandler.h"
#include "BattleEnemy.h"
#include "BattlePlayer.h"

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

	PokeDataBase* PlayerMonDB = BattlePlayer::PlayerPtr->GetMonsterDB();
	int PrevExp = PlayerMonDB->GetMonsterExperience();
	HpUI->SetPrevExp(PrevExp);	//GetCurExp

	bool IsLevelUp = PokeDataBase::PokeExperienceGain(*PlayerMonDB, *BattleEnemy::EnemyPtr->GetMonsterDB());
	
	/*if (true == dynamic_cast<Battle_PlayerHpUIHandler*>(HpUI)->IsLevelUp())
	{
		Duration = LevelUpDuration;
	}
	else
	{
		Duration = NormalDuration;
	}*/

	if (true == IsLevelUp)
	{
		Duration = LevelUpDuration;
	}
	else
	{
		Duration = NormalDuration;
	}
}

void BattleState_BattleWin::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;
	
	if (true == IsLevelChanged)
		return;

	
	BattleLevel::BattleLevelPtr->ChangeFieldLevel(true);
	IsLevelChanged = true;
}

void BattleState_BattleWin::ExitState()
{
	Timer = 0.f;
}
