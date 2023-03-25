#include "BattleEnemy_MoveState.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "BattleEnemy.h"
#include "BattleEnemyFSM.h"


BattleEnemy_MoveState::BattleEnemy_MoveState()
{

}

BattleEnemy_MoveState::~BattleEnemy_MoveState()
{
	
}

void BattleEnemy_MoveState::EnterState()
{
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	Duration = BattleEnemy::MoveDuration;

	const float Height = 250.f;
	const float DestOffset = 256.f;

	StartPos = float4::Down * Height;
	DestPos = float4{ ScreenSize.x - DestOffset, Height };

	Enemy = BattleEnemy::EnemyPtr;
}

void BattleEnemy_MoveState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
	{
		GetFSM()->ChangeState(BattleEnemy_StateType::Idle);
		return;
	}

	float Ratio = Timer / Duration;
	float4 NextPos = float4::LerpClamp(StartPos, DestPos, Ratio);
	Enemy->SetPos(NextPos);
}
