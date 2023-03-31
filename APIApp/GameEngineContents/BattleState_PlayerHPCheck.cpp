#include "BattleState_PlayerHPCheck.h"
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleFSM.h"
#include "BattlePlayer.h"
#include "PokeDataBase.h"


BattleState_PlayerHPCheck::BattleState_PlayerHPCheck()
{

}

BattleState_PlayerHPCheck::~BattleState_PlayerHPCheck()
{

}


void BattleState_PlayerHPCheck::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("My Pocketmon was Damaged");

	PokeDataBase* MonsterDB = BattlePlayer::PlayerPtr ->GetMonsterDB();
	int EnemyHP = MonsterDB->GetMonsterCurrentHP();

	if (0 < EnemyHP)
	{
		NextState = static_cast<int>(BattleStateType::PlayerTurn);
	}
	else
	{
		NextState = static_cast<int>(BattleStateType::StageLose);
	}

}

void BattleState_PlayerHPCheck::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < NextStateTime)
		return;

	GetFSM()->ChangeState(NextState);
}


void BattleState_PlayerHPCheck::ExitState()
{
	Timer = 0.f;
	TextInfo->Death();
	NextState = -1;
}
