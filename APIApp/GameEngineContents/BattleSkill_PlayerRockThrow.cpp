#include "BattleSkill_PlayerRockThrow.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
#include "SkillActor_RockThrow.h"
#include "BattleLevel.h"
BattleSkill_PlayerRockThrow::BattleSkill_PlayerRockThrow()
{
}

BattleSkill_PlayerRockThrow::~BattleSkill_PlayerRockThrow()
{
}

void BattleSkill_PlayerRockThrow::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	EnemyMonster = GetEnemyMonster()->GetRender();

	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetEnemyMonster()->GetPos() + float4({ -24, -12 }), {64, 64}, 0.0f, false);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetEnemyMonster()->GetPos() + float4({ -12, 12 }), {96, 96}, 0.2f, true);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetEnemyMonster()->GetPos() + float4({ 12, -4 }), {64, 64}, 0.5f, false);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetEnemyMonster()->GetPos() + float4({ 24, 0 }), {32, 32}, 0.57f, true);
}

void BattleSkill_PlayerRockThrow::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerRockThrow::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_PlayerRockThrow::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerRockThrow::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}

}

void BattleSkill_PlayerRockThrow::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	CurState = SkillState::Wait;
	EnemyMonster->On();
}

void BattleSkill_PlayerRockThrow::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (0.7f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_PlayerRockThrow::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;

	if (1.25f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
	}
	else if (0.9f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else if (0.8f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Down * 8);
	}
	else if (0.7f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else if (0.6f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Down * 8);
	}
	else if (0.5f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else if (0.4f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Down * 8);
	}
	else if (0.3f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else if (0.2f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Down * 8);
	}
	else if (0.1f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else
	{
		EnemyMonster->SetPosition(float4::Down * 8);
	}
}

void BattleSkill_PlayerRockThrow::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08 <= FlashingTime)
	{
		EnemyMonster->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		EnemyMonster->Off();
	}
}