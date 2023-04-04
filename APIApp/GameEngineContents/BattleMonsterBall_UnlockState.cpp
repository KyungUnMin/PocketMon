#include "BattleMonsterBall_UnlockState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleLevel.h"

BattleMonsterBall_UnlockState::BattleMonsterBall_UnlockState()
{

}

BattleMonsterBall_UnlockState::~BattleMonsterBall_UnlockState()
{

}

void BattleMonsterBall_UnlockState::EnterState()
{
	MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::OpenAniName, true);

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	EnemyMonster->UnLock();

	BattleLevel::BattleLevelPtr->UnlockWildPocketMon();
}

void BattleMonsterBall_UnlockState::Update(float _DeltaTime)
{
	if (nullptr == MonsterBall)
		return;
	
	if (false == BallRender->IsAnimationEnd())
		return;

	MonsterBall->Death();
	MonsterBall = nullptr;
}
