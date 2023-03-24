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
	for (size_t i = 0; i < AllState.size(); ++i)
	{
		if (nullptr == AllState[i])
			continue;

		delete AllState[i];
		AllState[i] = nullptr;
	}
}


void BattleFSM::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	AllState.resize(static_cast<size_t>(BattleStateType::COUNT), nullptr);
	for (size_t i = 0; i < AllState.size(); ++i)
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

	NewState->FsmPtr = this;
	AllState[static_cast<size_t>(_Type)] = NewState;
}






void BattleFSM::ChangeState(BattleStateType _NextStateType)
{
	BattleStateBase* PrevState = nullptr;
	if (BattleStateType::COUNT != CurStateType)
	{
		PrevState = AllState[static_cast<size_t>(CurStateType)];
	}

	BattleStateBase* NextState = AllState[static_cast<size_t>(_NextStateType)];

	if (nullptr == NextState)
	{
		MsgAssert("�ٲٷ��� ��Ʋ State�� ������� ���� �����ϴ�");
		return;
	}

	if (nullptr != PrevState)
	{
		PrevState->ExitState();
	}

	NextState->EnterState();

	CurStateType = _NextStateType;
}



void BattleFSM::Update(float _DeltaTime)
{
	if (BattleStateType::COUNT == CurStateType)
	{
		MsgAssert("���� ��Ʋ ���¸� ���������� �ʾҽ��ϴ�");
	}

	AllState[static_cast<size_t>(CurStateType)]->Update(_DeltaTime);
}


