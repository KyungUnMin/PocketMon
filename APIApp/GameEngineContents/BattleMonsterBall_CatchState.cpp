#include "BattleMonsterBall_CatchState.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattleMonsterBall.h"
#include "BattleMonsterBallFSM.h"
#include "BattleLevel.h"
#include "BgmPlayer.h"
#include "BattleDefine.h"

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

	GameEngineResources::GetInst().SoundPlay(BattleDefine::SfxName_WildCatchCorrect);
	BgmPlayer::PauseOn();
}

void BattleMonsterBall_CatchState::Update(float _DeltaTime)
{
	if (false == BallRender->IsAnimationEnd())
		return;

	BattleLevel::BattleLevelPtr->LockWildPocketMon();
	GetFSM()->ChangeState(BattleMonsterBall_Movement::Fade);
}

void BattleMonsterBall_CatchState::ExitState()
{
	BgmPlayer::PauseOff();
}
