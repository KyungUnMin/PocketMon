#include "BattleState_BattleWin.h"
#include <GameEngineBase/GameEngineRandom.h>
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "LevelUpStatUI_2.h"

#include "Battle_HpUIHandlerBase.h"
#include "FriendlyHPBackground.h"
#include "Battle_PlayerHpUIHandler.h"
#include "BattleEnemy.h"
#include "BattlePlayer.h"

std::vector<std::string_view> BattleState_BattleWin::Texts =
{
	"What?",
	"Unbelievable!",
	"I picked the wrong POK@MON!"
};

BattleState_BattleWin::BattleState_BattleWin()
{

}

BattleState_BattleWin::~BattleState_BattleWin()
{

}

void BattleState_BattleWin::EnterState()
{
	BattleLevel* Level = BattleLevel::BattleLevelPtr;
	
	TextInfo = Level->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	
	if (true == Level->IsWildBattle())
	{
		TextInfo->BattleSetText("Defeated the wild Pok@mon");
	}
	else if (BattleNpcType::Rival == Level->GetNpcType())
	{
		TextInfo->BattleSetText(Texts[2]);
	}
	else
	{
		int RandValue = GameEngineRandom::MainRandom.RandomInt(0, static_cast<int>(Texts.size() - 1));
		TextInfo->BattleSetText(Texts[RandValue]);
	}
	
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

	if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
		return;

	if (true == BattleLevel::BattleLevelPtr->IsBossBattle())
		return;

	BattleEnemy::EnemyPtr->ComeBack();
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
