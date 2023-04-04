#include "BattleEnemyMonster_UnlockState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemyMonster_LockState.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyMonsterFSM.h"

BattleEnemyMonster_UnlockState::BattleEnemyMonster_UnlockState()
{

}

BattleEnemyMonster_UnlockState::~BattleEnemyMonster_UnlockState()
{

}

void BattleEnemyMonster_UnlockState::EnterState()
{
	OriginScale = BattleEnemyMonster_LockState::GetOriginScale();

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();

	MonsterRender = EnemyMonster->GetRender();
	EffectRender = EnemyMonster->GetEffectRender();

	MonsterRender->On();
	EffectRender->On();

	StartOffset = MonsterRender->GetPosition();
}

void BattleEnemyMonster_UnlockState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;

	float Ratio = (Timer / Duration);

	float4 Offset = float4::LerpClamp(StartOffset, float4::Zero, Ratio);
	float4 Scale = float4::LerpClamp(float4::Zero, OriginScale, Ratio);

	MonsterRender->SetPosition(Offset);
	EffectRender->SetPosition(Offset);
	MonsterRender->SetScale(Scale);
	EffectRender->SetScale(Scale);

	if (Ratio <= 1.f)
		return;

	GetFSM()->ChangeState(BattleEnemyMonster_StateType::Idle);
}

void BattleEnemyMonster_UnlockState::ExitState()
{
	Timer = 0.f;
	EffectRender->Off();
}
