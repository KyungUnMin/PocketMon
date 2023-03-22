#include "HpBackGroundMove.h"
#include <GameEngineBase/GameEngineDebug.h>

const float HpBackGroundMove::MoveDuration = 1.5f;

HpBackGroundMove::HpBackGroundMove()
{

}

HpBackGroundMove::~HpBackGroundMove()
{

}

void HpBackGroundMove::Start()
{

}

void HpBackGroundMove::Update(float _DeltaTime)
{
	HpBackGroundMoving();
}


void HpBackGroundMove::HpBackGroundMoving()
{
	float LiveTime = GetLiveTime();
	if (MoveDuration < LiveTime)
		return;

	float Ratio = (LiveTime / MoveDuration);
	float4 NowPos = float4::LerpClamp(MoveStartPos, MoveEndPos, Ratio);
	SetPos(NowPos);
}




