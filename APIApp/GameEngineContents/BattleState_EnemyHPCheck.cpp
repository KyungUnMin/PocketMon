#include "BattleState_EnemyHPCheck.h"
#include "BattleEnemy.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "PokeDataBase.h"
#include "BattleFSM.h"
#include "BattleState_PlayerTurn.h"

BattleState_EnemyHPCheck::BattleState_EnemyHPCheck()
{

}

BattleState_EnemyHPCheck::~BattleState_EnemyHPCheck()
{

}

void BattleState_EnemyHPCheck::EnterState()
{
	SelectText();

	PokeDataBase* MonsterDB = BattleEnemy::EnemyPtr->GetMonsterDB();
	int EnemyHP = MonsterDB->GetMonsterCurrentHP();

	if (0 < EnemyHP)
	{
		NextState = static_cast<int>(BattleStateType::EnemyTurn);
	}
	else
	{
		NextState = static_cast<int>(BattleStateType::StageWin);
	}
	
}


void BattleState_EnemyHPCheck::SelectText()
{
	BattleScript BattleResult = BattleState_PlayerTurn::GetBattleResult();
	std::string TextValue = "";

	switch (BattleResult)
	{
	case BattleScript::Nothing:
		TextValue = "Nothing!";
		break;
	case BattleScript::Insignificant:
		TextValue = "Insignificant!";
		break;
	case BattleScript::Critical:
		TextValue = "Critical!";
		break;
	case BattleScript::Amazing:
		TextValue = "Amazing!";
		break;
	case BattleScript::Buff:
		TextValue = "Buff!";
		break;
	case BattleScript::PPiszero:
		TextValue = "PPiszero!";
		break;
	case BattleScript::Stern:
		TextValue = "Stern!";
		break;
	default:
	{
		MsgAssert("배틀 결과로 나올수 없는 값입니다");
	}
		return;
	}

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText(TextValue);
}


void BattleState_EnemyHPCheck::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < NextStateTime)
		return;

	GetFSM()->ChangeState(NextState);
}

void BattleState_EnemyHPCheck::ExitState()
{
	Timer = 0.f;
	TextInfo->Death();
	NextState = -1;
}

