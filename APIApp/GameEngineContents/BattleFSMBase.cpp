#include "BattleFSMBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleStateBase.h"

BattleFSMBase::BattleFSMBase()
{

}

BattleFSMBase::~BattleFSMBase()
{
	for (BattleStateBase* State : AllState)
	{
		if (nullptr == State)
			continue;

		delete State;
	}

	AllState.clear();
}



void BattleFSMBase::SetState(size_t _Index, BattleStateBase* _State)
{
	if (AllState.size() <= _Index)
	{
		MsgAssert("�������ַ��� State�� ������ ������ �Ѿ���ϴ�.\n ResizeStates�Լ��� ȣ�����־�� �մϴ�");
		return;
	 }

	_State->FsmPtr = this;
	AllState[_Index] = _State;
}



void BattleFSMBase::ChangeState(size_t _NextIndex)
{
	if (AllState.size() <= _NextIndex)
	{
		MsgAssert("FSM�� ����� State�� ������ �Ѿ �����Ͽ����ϴ�");
		return;
	}

	BattleStateBase* PrevState = nullptr;
	if (CurIndex < AllState.size())
	{
		PrevState = AllState[CurIndex];
	}

	BattleStateBase* NextState = AllState[_NextIndex];

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

	CurIndex = _NextIndex;
}




void BattleFSMBase::Update(float _DeltaTime)
{
	if (AllState.size() <= CurIndex)
	{
		MsgAssert("���� FSM�� ���¸� ���������� �ʾҽ��ϴ�");
		return;
	}

	AllState[CurIndex]->Update(_DeltaTime);
}
