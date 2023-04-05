#include "BattleState_EnemyHPCheck.h"
#include "BattleEnemy.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "PokeDataBase.h"
#include "BattleFSM.h"
#include "BattleState_PlayerTurn.h"

#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"

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

	const std::string& PlayerMonName = BattlePlayer::PlayerPtr->GetMonster()->GetName();
	const std::string& EnemyMonName = BattleEnemy::EnemyPtr->GetMonster()->GetName();
	const std::string_view& PlayerUseSkillName = BattleState_PlayerTurn::GetUsedSkillName();

	
	/*
Nothing,          // 0 �ƹ��͵� �ƴ� (�븻)
Insignificant,    // 1 ȿ���� �̹��ߴ�!
Critical,         // 2 �޼ҿ� �¾Ҵ�!
Amazing,          // 3 ȿ���� �����ߴ�!
Buff,             // 4 �� ��ų�� ������ų�Դϴ�.
PPiszero,         // 5 PP�� 0�Դϴ�. ��Ʋ �Ұ���
Stern,            // 6 ������� ü���� 0�̵Ǿ� ���ϻ��°� �ƽ��ϴ�.
*/

	switch (BattleResult)
	{
	case BattleScript::Nothing:
		TextValue = "Nothing!";
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
		MsgAssert("��Ʋ ����� ���ü� ���� ���Դϴ�");
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

