#include "BattleMonsterBall_VerticalShake.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall.h"
#include "BattleDefine.h"

BattleMonsterBall_VerticalShake::BattleMonsterBall_VerticalShake()
{

}

BattleMonsterBall_VerticalShake::~BattleMonsterBall_VerticalShake()
{

}

void BattleMonsterBall_VerticalShake::EnterState()
{
	MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	GameEngineRender* BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::IdleAniName);

	TopPos = MonsterBall->GetPos();
	BotPos = TopPos + float4::Down * Range;
}

void BattleMonsterBall_VerticalShake::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
	{
		Timer -= Duration;
		++MoveCnt;
		Range *= NextPer;
		TopPos = BotPos + float4::Up * Range;
		GameEngineResources::GetInst().SoundPlay(BattleDefine::SfxName_BallMoveVertical);
	}

	if (5 <= MoveCnt)
	{
		GetFSM()->ChangeState(BattleMonsterBall_Movement::ShakeHorizon);
		return;
	}

	//위로 올라가는 경우
	float4 StartPos = BotPos;
	float4 DestPos = TopPos;

	//아래로 내려가는 경우
	if (0 == (MoveCnt % 2))
	{
		StartPos = TopPos;
		DestPos = BotPos;
	}

	float Ratio = Timer / Duration;
	float4 NowPos = float4::LerpClamp(StartPos, DestPos, Ratio);
	MonsterBall->SetPos(NowPos);
}
