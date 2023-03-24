#include "BattleFSMBase.h"
#include <GameEngineBase/GameEngineDebug.h>

BattleFSMBase::BattleFSMBase()
{

}

BattleFSMBase::~BattleFSMBase()
{

}

void BattleFSMBase::ChangeState(BattleFSM_StateBase* _NextState)
{

}

void BattleFSMBase::Update(float _DeltaTime)
{
	if (nullptr == CurState)
	{
		MsgAssert("현재 실행중인 상태가 없습니다");
		return;
	}


}
