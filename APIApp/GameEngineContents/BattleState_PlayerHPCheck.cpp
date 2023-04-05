#include "BattleState_PlayerHPCheck.h"
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleFSM.h"
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "PokeDataBase.h"
#include "BattleState_EnemyTurn.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"

BattleState_PlayerHPCheck::BattleState_PlayerHPCheck()
{

}

BattleState_PlayerHPCheck::~BattleState_PlayerHPCheck()
{

}


void BattleState_PlayerHPCheck::EnterState()
{
	SelectText();
	PokeDataBase* MonsterDB = BattlePlayer::PlayerPtr ->GetMonsterDB();
	int PlayerHP = MonsterDB->GetMonsterCurrentHP();

	if (0 < PlayerHP)
	{
		NextState = static_cast<int>(BattleStateType::PlayerTurn);
	}
	else
	{
		NextState = static_cast<int>(BattleStateType::StageLose);
	}

}


void BattleState_PlayerHPCheck::SelectText()
{
	BattleScript BattleResult = BattleState_EnemyTurn::GetBattleResult();
	std::string TextValue = "";

	const std::string& PlayerMonName = BattlePlayer::PlayerPtr->GetMonster()->GetName();
	const std::string& EnemyMonName = BattleEnemy::EnemyPtr->GetMonster()->GetName();
	//const std::string_view& PlayerUseSkillName = BattleState_PlayerTurn::GetUsedSkillName();


	/*switch (BattleResult)
	{
	case BattleScript::Nothing:
		TextValue = MonsterName + "used\n@@@";
		break;
	case BattleScript::Insignificant:
		TextValue = "It`s not very effective_";
		break;
	case BattleScript::Critical:
		TextValue = "A critical hit!";
		break;
	case BattleScript::Amazing:
		TextValue = "It`s super effective!";
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
	}*/

	/*
Nothing,          // 0 아무것도 아님 (노말)
Insignificant,    // 1 효과는 미미했다!
Critical,         // 2 급소에 맞았다!
Amazing,          // 3 효과는 굉장했다!
Buff,             // 4 이 스킬은 버프스킬입니다.
PPiszero,         // 5 PP가 0입니다. 배틀 불가능
Stern,            // 6 수비수의 체력이 0이되어 스턴상태가 됐습니다.
*/

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText(TextValue);
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

