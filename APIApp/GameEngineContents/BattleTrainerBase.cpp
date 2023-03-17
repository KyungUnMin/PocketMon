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
	//지금은 이미지를 움직이지만 나중엔 Render를 움직이자
	float LiveTime = GetLiveTime();
	if (MoveDuration < LiveTime)
		return;

	if (MoveStartPos.IsZero() && MoveEndPos.IsZero())
	{
		MsgAssert("트레이너들의 이동 위치를 설정해주지 않았습니다");
		return;
	}

	float Ratio = (LiveTime / MoveDuration);
	float4 NowPos = float4::LerpClamp(MoveStartPos, MoveEndPos, Ratio);
	SetPos(NowPos);
}




