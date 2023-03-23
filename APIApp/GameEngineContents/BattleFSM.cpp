#include "BattleFSM.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleLevel.h"
#include "BattleEnemy.h"
#include "BattleState_WildTalk.h"
#include "BattleState_PlayerTurn.h"

BattleFSM::BattleFSM()
{

}

BattleFSM::~BattleFSM()
{

}


void BattleFSM::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	switch (_NpcType)
	{
	case BattleNpcType::None:
		WildBattleInit(_FieldType);
		break;
	default:
		MsgAssert("��Ʋ FSM���� ���� ���������� ���� ������Ȳ�Դϴ�");
		break;
	}
}

void BattleFSM::WildBattleInit(BattleFieldType _FieldType)
{
	BattleEnemy::EnemyPtr->CreateWildMonster(_FieldType);
	CreateState(BattleStateType::WildTalk);
	CreateState(BattleStateType::PlayerTurn);


	ChangeState(BattleStateType::WildTalk);
}







void BattleFSM::CreateState(BattleStateType _Type)
{
	if (AllState.end() != AllState.find(_Type))
	{
		MsgAssert("�̹� ������� ��ƲState�Դϴ�");
		return;
	}
	
	std::shared_ptr<BattleStateBase> NewState = nullptr;

	switch (_Type)
	{
	case BattleStateType::WildTalk:
		NewState = std::make_shared<BattleState_WildTalk>();
		break;
	case BattleStateType::PlayerTurn:
		NewState = std::make_shared<BattleState_PlayerTurn>();
		break;
	default:
		MsgAssert("���� FSM�� �ش� ��ƲState�� ���������� �ʾҽ��ϴ�");
		return;
	}

	NewState->FsmPtr = this;
	NewState->Start();
	AllState[_Type] = NewState;
}






void BattleFSM::ChangeState(BattleStateType _Type)
{
	std::shared_ptr<BattleStateBase> PrevState = CurState;
	std::shared_ptr<BattleStateBase> NextState = AllState[_Type];

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

	CurState = NextState;
}



void BattleFSM::Update(float _DeltaTime)
{
	if (nullptr == CurState)
	{
		MsgAssert("���� ��Ʋ ���¸� ���������� �ʾҽ��ϴ�");
	}

	CurState->Update(_DeltaTime);
}
