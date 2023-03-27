#include "BattleMonsterBall_CatchState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBall.h"
#include "BattleMonsterBallFSM.h"
#include "BattleLevel.h"

BattleMonsterBall_CatchState::BattleMonsterBall_CatchState()
{

}

BattleMonsterBall_CatchState::~BattleMonsterBall_CatchState()
{

}

void BattleMonsterBall_CatchState::EnterState()
{
	BattleMonsterBall* MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::CatchAniName);
}

void BattleMonsterBall_CatchState::Update(float _DeltaTime)
{
	if (false == BallRender->IsAnimationEnd())
		return;

	BattleLevel::BattleLevelPtr->LockWildPocketMon();
	GetFSM()->ChangeState(BattleMonsterBall_Movement::Fade);
}
