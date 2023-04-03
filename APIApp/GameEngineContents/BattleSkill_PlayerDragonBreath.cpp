#include "BattleSkill_PlayerDragonBreath.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
#include "BattleLevel.h"
#include "SkillActor_DragonBreath.h"

BattleSkill_PlayerDragonBreath::BattleSkill_PlayerDragonBreath()
{
}

BattleSkill_PlayerDragonBreath::~BattleSkill_PlayerDragonBreath()
{
}

void BattleSkill_PlayerDragonBreath::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	BattleMonsterEnemy* Enemy = GetEnemyMonster();
	EnemyMonster = Enemy->GetRender();

	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos, Enemy->GetPos() + EndPos, 0.0f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos + float4({ 16, 16 }), Enemy->GetPos() + EndPos + float4({ 8, 8 }), 0.15f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos, Enemy->GetPos() + EndPos, 0.3f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos + float4({ -16, -16 }), Enemy->GetPos() + EndPos + float4({ -8, -8 }), 0.45f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos, Enemy->GetPos() + EndPos, 0.6f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos + float4({ 16, 16 }), Enemy->GetPos() + EndPos + float4({ 8, 8 }), 0.75f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos, Enemy->GetPos() + EndPos, 0.9f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Enemy->GetPos() + StartPos + float4({ -16, -16 }), Enemy->GetPos() + EndPos + float4({ -8, -8 }), 1.0f);
}

void BattleSkill_PlayerDragonBreath::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerDragonBreath::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_PlayerDragonBreath::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerDragonBreath::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_PlayerDragonBreath::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;

	CurState = SkillState::Wait;
	EnemyMonster->On();
}

void BattleSkill_PlayerDragonBreath::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (1.7f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_PlayerDragonBreath::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;
	if (0.12f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
	}
	else if (0.06f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else
	{
		EnemyMonster->SetPosition(float4::Right * 8);
	}
}

void BattleSkill_PlayerDragonBreath::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08f <= FlashingTime)
	{
		EnemyMonster->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		EnemyMonster->Off();
	}
}
