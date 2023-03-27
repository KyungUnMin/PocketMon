#include "BattleMonsterBall_ThrowToCatch.h"
#include "BattleEnemy.h"
#include "BattleMonsterBallFSM.h"

BattleMonsterBall_ThrowToCatch::BattleMonsterBall_ThrowToCatch()
{

}

BattleMonsterBall_ThrowToCatch::~BattleMonsterBall_ThrowToCatch()
{

}

void BattleMonsterBall_ThrowToCatch::EnterState()
{
	float4 StartPos = float4::Zero;
	float4 DestPos = BattleEnemy::EnemyPtr->GetPos();

	SetGravity(-350.f, 500.f);
	SetDuration(1.0f);
	SetMovePos(StartPos, DestPos);

	BattleMonsterBall_ThrowBase::EnterState();
}

void BattleMonsterBall_ThrowToCatch::Update(float _DeltaTime)
{
	BattleMonsterBall_ThrowBase::Update(_DeltaTime);
}

void BattleMonsterBall_ThrowToCatch::ExitExcute()
{
	GetFSM()->ChangeState(BattleMonsterBall_Movement::Opened);
}
