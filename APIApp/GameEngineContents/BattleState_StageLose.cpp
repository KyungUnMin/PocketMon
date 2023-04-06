#include "BattleState_StageLose.h"
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleMonsterPlayer.h"
#include "BattlePlayer.h"
#include "Player.h"
#include "TrainerPokemon.h"
#include "BattleFadeCtrl.h"
#include "BattleFSM.h"
#include "PocketMonCore.h"


BattleState_StageLose::BattleState_StageLose()
{

}

BattleState_StageLose::~BattleState_StageLose()
{

}

void BattleState_StageLose::EnterState()
{
	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	PlayerMonster->KillMonster();

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	
	TrainerPokemon* Monsters = Player::MainPlayer->GetPlayerPokemon();
	IsAliveMonster = Monsters->HasNextPokemon();

	if (true == IsAliveMonster)
	{
		TextInfo->BattleSetText("Change PocketMon?");
	}
	else
	{
		TextInfo->BattleSetText("There`s no Pokemon\nto fight with_");
	}
}

void BattleState_StageLose::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	if (true == IsAliveMonster)
	{
		GetFSM()->ChangeState(BattleStateType::PlayerMonsterChange);
	}
	else
	{
		GetFSM()->ChangeState(BattleStateType::BattleLose);
	}
}

void BattleState_StageLose::ExitState()
{
	TextInfo->Death();
	TextInfo = nullptr;
	Timer = 0.f;
	IsAliveMonster = false;
}
