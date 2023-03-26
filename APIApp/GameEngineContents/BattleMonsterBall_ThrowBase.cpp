#include "BattleMonsterBall_ThrowBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall.h"
//#include "BattleEnemy.h"

BattleMonsterBall_ThrowBase::BattleMonsterBall_ThrowBase()
{

}

BattleMonsterBall_ThrowBase::~BattleMonsterBall_ThrowBase()
{

}

void BattleMonsterBall_ThrowBase::EnterState()
{
	FsmPtr = dynamic_cast<BattleMonsterBallFSM*>(GetFSM());
	MonsterBall = FsmPtr->GetMonsterBall();
	GameEngineRender* BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::ThrowAniName);

	LiveTime = 0.f;
	NowGravity = StartGravity;
}

void BattleMonsterBall_ThrowBase::Update(float _DeltaTime)
{
	if (StartPos.IsZero() && DestPos.IsZero())
	{
		MsgAssert("[��Ʋ] ���ͺ��� �̵��� ���õ� �ʱ⼼���� ������ �ʾҽ��ϴ�");
		return;
	}

	LiveTime += _DeltaTime;
	if (Duration < LiveTime)
	{
		ExitExcute();
		MonsterBall->Death();
		return;
	}

	float Ratio = LiveTime / Duration;
	float4 NextPos = MonsterBall->GetPos();
	NextPos.x = float4::Lerp(StartPos, DestPos, Ratio).x;

	NowGravity += GravityAcc * _DeltaTime;
	NextPos.y += NowGravity * _DeltaTime;
	MonsterBall->SetPos(NextPos);
}

