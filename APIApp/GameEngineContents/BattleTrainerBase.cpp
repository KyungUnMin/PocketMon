#include "BattleTrainerBase.h"
#include <GameEngineBase/GameEngineDebug.h>

const float BattleTrainerBase::MoveDuration = 1.5f;

BattleTrainerBase::BattleTrainerBase()
{

}

BattleTrainerBase::~BattleTrainerBase()
{

}

void BattleTrainerBase::Start()
{

}

void BattleTrainerBase::Update(float _DeltaTime)
{
	BattleStartMove();
}


void BattleTrainerBase::BattleStartMove()
{
	//������ �̹����� ���������� ���߿� Render�� ��������
	float LiveTime = GetLiveTime();
	if (MoveDuration < LiveTime)
		return;

	if (MoveStartPos.IsZero() && MoveEndPos.IsZero())
	{
		MsgAssert("Ʈ���̳ʵ��� �̵� ��ġ�� ���������� �ʾҽ��ϴ�");
		return;
	}

	float Ratio = (LiveTime / MoveDuration);
	float4 NowPos = float4::LerpClamp(MoveStartPos, MoveEndPos, Ratio);
	SetPos(NowPos);
}




