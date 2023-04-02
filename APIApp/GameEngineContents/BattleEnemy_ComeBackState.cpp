#include "BattleEnemy_ComeBackState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemy.h"
#include "BattleEnemyFSM.h"

BattleEnemy_ComeBackState::BattleEnemy_ComeBackState()
{

}

BattleEnemy_ComeBackState::~BattleEnemy_ComeBackState()
{

}

void BattleEnemy_ComeBackState::EnterState()
{
	EnemyRender = BattleEnemy::EnemyPtr->GetTrainerRender();
	PrevOffset = EnemyRender->GetPosition();
	DestOffset = PrevOffset * float4::Down;
}

void BattleEnemy_ComeBackState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	
	float Ratio = (Timer / Duration);
	float4 NowOffset = float4::LerpClamp(PrevOffset, DestOffset, Ratio);
	EnemyRender->SetPosition(NowOffset);

	if (Ratio <= 1.f)
		return;

	GetFSM()->ChangeState(BattleEnemy_StateType::Idle);
}

void BattleEnemy_ComeBackState::ExitState()
{
	Timer = 0.f;
}
