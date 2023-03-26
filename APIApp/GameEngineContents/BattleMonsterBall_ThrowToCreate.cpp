#include "BattleMonsterBall_ThrowToCreate.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "BattlePlayer.h"
#include "BattleMonsterBall.h"


BattleMonsterBall_ThrowToCreate::BattleMonsterBall_ThrowToCreate()
{

}

BattleMonsterBall_ThrowToCreate::~BattleMonsterBall_ThrowToCreate()
{

}

void BattleMonsterBall_ThrowToCreate::EnterState()
{
	BattleMonsterBall_ThrowBase::EnterState();
	BattleMonsterBall* MonsterBall = GetMonsterBall();
	BallRender = MonsterBall->GetRender();

	float4 DestPos = BattlePlayer::PlayerPtr->GetPos();
	float4 StartPos = DestPos + float4::Left * Range;

	SetMovePos(StartPos, DestPos);
}

void BattleMonsterBall_ThrowToCreate::Update(float _DeltaTime)
{
	if (GetLiveTime() < WaitTime)
	{
		BallRender->Off();
	}
	else
	{
		BallRender->On();
	}

	BattleMonsterBall_ThrowBase::Update(_DeltaTime);
}

void BattleMonsterBall_ThrowToCreate::ExitExcute()
{
	BattlePlayer::PlayerPtr->CreateMontser();
}
