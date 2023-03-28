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
		MsgAssert("FSM에 등록한 State의 범위를 넘어서 접근하였습니다");
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
		MsgAssert("바꾸려는 배틀 State를 만들어준 적이 없습니다");
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
		MsgAssert("설정해주려는 State가 벡터의 범위를 넘어갔습니다.\n ResizeStates함수를 호출해주어야 합니다");
		return;
	}

	_State->FsmPtr = this;
	AllState[_Index] = _State;
}




void BattleFSMBase::Update(float _DeltaTime)
{
	if (AllState.size() <= CurIndex)
	{
		MsgAssert("현재 FSM의 상태를 설정해주지 않았습니다");
		return;
	}

	AllState[CurIndex]->Update(_DeltaTime);
}

void BattleFSMBase::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	MsgAssert("이 함수를 오버라이딩 하지 않았거나 오버로딩 하지 않았습니다");
}


GameEngineActor* BattleFSMBase::GetOwner()
{
	if (nullptr == Owner)
	{
		MsgAssert("FSM의 오너를 설정해준적이 없습니다");
		return nullptr;
	}

	return Owner;
}