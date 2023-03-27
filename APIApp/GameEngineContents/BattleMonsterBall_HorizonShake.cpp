#include "BattleMonsterBall_HorizonShake.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBall.h"
#include "BattleMonsterBallFSM.h"

BattleMonsterBall_HorizonShake::BattleMonsterBall_HorizonShake()
{

}

BattleMonsterBall_HorizonShake::~BattleMonsterBall_HorizonShake()
{

}

void BattleMonsterBall_HorizonShake::EnterState()
{
	BattleMonsterBall* MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::RollAniName);
}

void BattleMonsterBall_HorizonShake::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (Duration < LiveTime)
	{
		GetFSM()->ChangeState(BattleMonsterBall_Movement::Catch);
		return;
	}

	int NowFrame = BallRender->GetFrame();
	switch (NowFrame)
	{
	case 0:
		BallRender->SetPosition(float4::Left * Range);
		break;
	case 1:
		BallRender->SetPosition(float4::Zero);
		break;
	case 2:
		BallRender->SetPosition(float4::Right * Range);
		break;
	default:
		MsgAssert("예상하지 못한 프레임입니다");
		break;
	}
	
}
