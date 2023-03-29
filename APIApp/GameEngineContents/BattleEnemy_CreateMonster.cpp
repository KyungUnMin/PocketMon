#include "BattleEnemy_CreateMonster.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemy.h"
#include "BattleEnemyFSM.h"

BattleEnemy_CreateMonster::BattleEnemy_CreateMonster()
{

}

BattleEnemy_CreateMonster::~BattleEnemy_CreateMonster()
{

}

void BattleEnemy_CreateMonster::EnterState()
{
	EnemyRender = BattleEnemy::EnemyPtr->GetTrainerRender();
	OriginOffset = EnemyRender->GetPosition();
}

void BattleEnemy_CreateMonster::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
	{
		GetFSM()->ChangeState(BattleEnemy_StateType::Idle);
		return;
	}

	float Ratio = (Timer / Duration);
	float4 DestOffset = OriginOffset + (float4::Right * MoveOffset);
	float4 NowOffset = float4::LerpClamp(OriginOffset, DestOffset, Ratio);
	EnemyRender->SetPosition(NowOffset);
}
