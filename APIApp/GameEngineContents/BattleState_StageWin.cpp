#include "BattleState_StageWin.h"
#include "BattleEnemy.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleMonsterEnemy.h"
#include "BattleFSM.h"

BattleState_StageWin::BattleState_StageWin()
{

}

BattleState_StageWin::~BattleState_StageWin()
{

}

void BattleState_StageWin::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText(MakeText());

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	EnemyMonster->KillMonster();
}

std::string BattleState_StageWin::MakeText()
{
	std::string ReturnStr = "Foe ";

	if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
	{
		ReturnStr += "wild ";
	}

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	ReturnStr += EnemyMonster->GetName();

	ReturnStr += "\nfainted!";

	return ReturnStr;
}


void BattleState_StageWin::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	if (false == BattleEnemy::EnemyPtr->IsValidNextMonster())
	{
		if (true == BattleLevel::BattleLevelPtr->IsBossBattle())
		{
			GetFSM()->ChangeState(BattleStateType::GymBattleWin);
		}
		else
		{
			GetFSM()->ChangeState(BattleStateType::BattleWin);
		}
		return;
	}
	else
	{
		GetFSM()->ChangeState(BattleStateType::NextStage);
		return;
	}
}

void BattleState_StageWin::ExitState()
{
	TextInfo->Death();


	//BattleEnemy::EnemyPtr->CreateMonster();
}

