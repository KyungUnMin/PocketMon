#include "BattleEnemyMonster_LockState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyMonsterFSM.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattleLevel.h"

float4 BattleEnemyMonster_LockState::OriginScale = float4::Zero;

const float4& BattleEnemyMonster_LockState::GetOriginScale()
{
	return OriginScale;
}

BattleEnemyMonster_LockState::BattleEnemyMonster_LockState()
{

}

BattleEnemyMonster_LockState::~BattleEnemyMonster_LockState()
{

}

void BattleEnemyMonster_LockState::EnterState()
{
	BattleMonsterEnemy* Monster = BattleEnemy::EnemyPtr->GetMonster();
	MonsterRender = Monster->GetRender();
	OriginScale = MonsterRender->GetScale();
	
	LockEffect = Monster->GetEffectRender();
	LockEffect->On();
	LockEffect->SetScale(OriginScale);
	LockEffect->SetAlpha(100);

	DestOffset = float4::Up * LockEffect->GetScale().y * 0.25f;
	Duration = BattleMonsterEnemy::LockTime;

	BattleLevel::BattleLevelPtr->CreateActor<Battle_MonsterAppearEffect>(UpdateOrder::Battle_Actors);
}

void BattleEnemyMonster_LockState::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (Duration < LiveTime)
	{
		GetFSM()->ChangeState(BattleEnemyMonster_StateType::Idle);
		return;
	}

	float Ratio = (LiveTime / Duration);

	float4 Offset = float4::LerpClamp(float4::Zero, DestOffset, Ratio);
	float4 Scale = float4::LerpClamp(OriginScale, float4::Zero, Ratio);

	MonsterRender->SetPosition(Offset);
	LockEffect->SetPosition(Offset);
	MonsterRender->SetScale(Scale);
	LockEffect->SetScale(Scale);
}

void BattleEnemyMonster_LockState::ExitState()
{
	LiveTime = 0.f;
	MonsterRender->Off();
	LockEffect->Off();
}
