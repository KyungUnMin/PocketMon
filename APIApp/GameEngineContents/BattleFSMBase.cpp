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
		MsgAssert("���� �������� ���°� �����ϴ�");
		return;
	}


}
