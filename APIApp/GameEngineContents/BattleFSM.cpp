#include "BattleFSM.h"
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleLevel.h"
#include "BattleState_WildTalk.h"

BattleFSM::BattleFSM()
{

}

BattleFSM::~BattleFSM()
{

}


void BattleFSM::Init()
{
	
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
