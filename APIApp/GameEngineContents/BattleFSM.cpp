#include "BattleFSM.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleLevel.h"
#include "BattleEnemy.h"
#include "BattleState_WildTalk.h"
#include "BattleState_PlayerTurn.h"
#include "BattleState_EnemyTurn.h"
#include "BattleState_ThrowMonsterBall.h"

BattleFSM::BattleFSM()
{

}

BattleFSM::~BattleFSM()
{
	
}


void BattleFSM::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	ResizeStates(BattleStateType::COUNT);
	size_t Size = static_cast<size_t>(BattleStateType::COUNT);
	for (size_t i = 0; i < Size; ++i)
	{
		CreateState(static_cast<BattleStateType>(i));
	}

	switch (_NpcType)
	{
	case BattleNpcType::None:
		BattleEnemy::EnemyPtr->CreateWildMonster(_FieldType);
		ChangeState(BattleStateType::WildTalk);
		break;
	default:
		MsgAssert("��Ʋ FSM���� ���� ���������� ���� ������Ȳ�Դϴ�");
		break;
	}
}






void BattleFSM::CreateState(BattleStateType _Type)
{
	BattleStateBase* NewState = nullptr;

	switch (_Type)
	{
	case BattleStateType::WildTalk:
		NewState = new BattleState_WildTalk;
		break;
	case BattleStateType::PlayerTurn:
		NewState = new BattleState_PlayerTurn;
		break;
	case BattleStateType::EnemyTurn:
		NewState = new BattleState_EnemyTurn;
		break;
	case BattleStateType::ThrowMonsterBall:
		NewState = new BattleState_ThrowMonsterBall;
		break;
	default:
		MsgAssert("���� FSM�� �ش� ��ƲState�� ���������� �ʾҽ��ϴ�");
		return;
	}

	SetState(static_cast<size_t>(_Type), NewState);
}


