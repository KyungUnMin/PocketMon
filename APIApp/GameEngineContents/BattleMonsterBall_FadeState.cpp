#include "BattleMonsterBall_FadeState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBall.h"
#include "BattleMonsterBallFSM.h"

BattleMonsterBall_FadeState::BattleMonsterBall_FadeState()
{

}

BattleMonsterBall_FadeState::~BattleMonsterBall_FadeState()
{

}

void BattleMonsterBall_FadeState::EnterState()
{
	MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::IdleAniName, true);
}

void BattleMonsterBall_FadeState::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (Duration < LiveTime)
	{
		MonsterBall->Death();
		return;
	}

	float Ratio = (LiveTime / Duration);
	float NowAlpha = 255.f - (255.f * Ratio);
	if (NowAlpha < 0.f)
	{
		NowAlpha = 0.f;
	}

	BallRender->SetAlpha(static_cast<int>(NowAlpha));
}
