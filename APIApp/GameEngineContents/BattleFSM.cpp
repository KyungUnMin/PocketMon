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
		MsgAssert("이미 만들어진 배틀State입니다");
		return;
	}
	
	std::shared_ptr<BattleStateBase> NewState = nullptr;

	switch (_Type)
	{
	case BattleStateType::WildTalk:
		NewState = std::make_shared<BattleState_WildTalk>();
		break;
	default:
		MsgAssert("아직 FSM과 해당 배틀State를 연결해주지 않았습니다");
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
		MsgAssert("바꾸려는 배틀 State는 만들어준 적이 없습니다");
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
		MsgAssert("현재 배틀 상태를 설정해주지 않았습니다");
	}

	CurState->Update(_DeltaTime);
}
