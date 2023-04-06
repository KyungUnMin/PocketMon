#include "BattleMonsterBall_OpenState.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "Battle_PlayerBallParticle.h"
#include "BattleLevel.h"
#include "ContentsEnum.h"
#include "BattleDefine.h"

BattleMonsterBall_OpenState::BattleMonsterBall_OpenState()
{

}

BattleMonsterBall_OpenState::~BattleMonsterBall_OpenState()
{

}

void BattleMonsterBall_OpenState::EnterState()
{
	BattleMonsterBallFSM* FsmPtr = dynamic_cast<BattleMonsterBallFSM*>(GetFSM());
	BattleMonsterBall* MonsterBall = FsmPtr->GetMonsterBall();
	GameEngineRender* RenderPtr = MonsterBall->GetRender();
	RenderPtr->ChangeAnimation(BattleMonsterBall::OpenAniName);

	Duration = BattleMonsterEnemy::LockTime;
	BattleEnemy::EnemyPtr->GetMonster()->Lock();

	Battle_PlayerBallParticle* Particle = BattleLevel::BattleLevelPtr->CreateActor<Battle_PlayerBallParticle>(UpdateOrder::Battle_Actors);
	Particle->SetPos(MonsterBall->GetPos());
	GameEngineResources::GetInst().SoundPlay(BattleDefine::SfxName_BallInput);
}

void BattleMonsterBall_OpenState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	GetFSM()->ChangeState(BattleMonsterBall_Movement::ShakeVertical);
}
