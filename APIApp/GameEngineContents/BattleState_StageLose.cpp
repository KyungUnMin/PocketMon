#include "BattleState_StageLose.h"
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleMonsterPlayer.h"
#include "BattlePlayer.h"

BattleState_StageLose::BattleState_StageLose()
{

}

BattleState_StageLose::~BattleState_StageLose()
{

}

void BattleState_StageLose::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("Change PocketMon");

	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	PlayerMonster->KillMonster();
}

void BattleState_StageLose::Update(float _DeltaTime)
{
}

void BattleState_StageLose::ExitState()
{
	TextInfo->Death();


}
