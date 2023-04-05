#include "BattleState_PlayerHPCheck.h"
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleFSM.h"
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "PokeDataBase.h"
#include "BattleState_EnemyTurn.h"

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

	const std::string& MonsterName = BattlePlayer::PlayerPtr->GetMonster()->GetName();



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

	/*
Nothing,          // 0 �ƹ��͵� �ƴ� (�븻)
Insignificant,    // 1 ȿ���� �̹��ߴ�!
Critical,         // 2 �޼ҿ� �¾Ҵ�!
Amazing,          // 3 ȿ���� �����ߴ�!
Buff,             // 4 �� ��ų�� ������ų�Դϴ�.
PPiszero,         // 5 PP�� 0�Դϴ�. ��Ʋ �Ұ���
Stern,            // 6 ������� ü���� 0�̵Ǿ� ���ϻ��°� �ƽ��ϴ�.
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

