#include "BattleMonsterBall_UnlockState.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleLevel.h"
#include "BattleDefine.h"

float4 BattleMonsterBall_UnlockState::MonsterBallPos = float4::Zero;

BattleMonsterBall_UnlockState::BattleMonsterBall_UnlockState()
{

}

BattleMonsterBall_UnlockState::~BattleMonsterBall_UnlockState()
{

}

void BattleMonsterBall_UnlockState::EnterState()
{
	MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	GameEngineRender* BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::OpenAniName, true);
	MonsterBallPos = MonsterBall->GetPos();

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	EnemyMonster->UnLock();

	GameEngineResources::GetInst().SoundPlay(BattleDefine::SfxName_BallInput);
	BattleLevel::BattleLevelPtr->UnlockWildPocketMon();
}

void BattleMonsterBall_UnlockState::Update(float _DeltaTime)
{
	if (nullptr == MonsterBall)
		return;

	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	MonsterBall->Death();
	MonsterBall = nullptr;
}
