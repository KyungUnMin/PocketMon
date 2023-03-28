#include "BattleFSMBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleStateBase.h"

BattleFSMBase::BattleFSMBase(GameEngineActor* _Owner)
	:Owner(_Owner)
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

	CurIndex = _NextIndex;

	if (nullptr != PrevState)
	{
		PrevState->ExitState();
	}

	NextState->EnterState();
}



void BattleFSMBase::InitState(BattleStateBase* _State, size_t _Index)
{
	if (AllState.size() <= _Index)
	{
		MsgAssert("�������ַ��� State�� ������ ������ �Ѿ���ϴ�.\n ResizeStates�Լ��� ȣ�����־�� �մϴ�");
		return;
	}

	_State->FsmPtr = this;
	AllState[_Index] = _State;
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

void BattleFSMBase::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	MsgAssert("�� �Լ��� �������̵� ���� �ʾҰų� �����ε� ���� �ʾҽ��ϴ�");
}


GameEngineActor* BattleFSMBase::GetOwner()
{
	if (nullptr == Owner)
	{
		MsgAssert("FSM�� ���ʸ� ������������ �����ϴ�");
		return nullptr;
	}

	return Owner;
}