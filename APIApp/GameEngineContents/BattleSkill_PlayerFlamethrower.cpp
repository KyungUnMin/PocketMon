#include "BattleSkill_PlayerFlamethrower.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
#include "BattleLevel.h"
#include "SkillActor_Ember.h"
BattleSkill_PlayerFlamethrower::BattleSkill_PlayerFlamethrower() 
{
}

BattleSkill_PlayerFlamethrower::~BattleSkill_PlayerFlamethrower() 
{
}

void BattleSkill_PlayerFlamethrower::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	BattleMonsterEnemy* Enemy = GetEnemyMonster();
	EnemyMonster = Enemy->GetRender();

	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos , Enemy->GetPos() + EndPos, 0.0f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos + float4({16, 16}), Enemy->GetPos() + EndPos + float4({ 8, 8 }), 0.15f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos , Enemy->GetPos() + EndPos, 0.3f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos + float4({-16, -16}), Enemy->GetPos() + EndPos + float4({ -8, -8 }), 0.45f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos , Enemy->GetPos() + EndPos, 0.6f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos + float4({16, 16}), Enemy->GetPos() + EndPos + float4({ 8, 8 }), 0.75f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos, Enemy->GetPos() + EndPos, 0.9f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Enemy->GetPos() + StartPos + float4({-16, -16}), Enemy->GetPos() + EndPos + float4({ -8, -8 }), 1.0f);
	GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("Flamethrower.wav");
	SFX.LoopCount(1);
	SFX.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerFlamethrower::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerFlamethrower::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_PlayerFlamethrower::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerFlamethrower::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_PlayerFlamethrower::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;

	CurState = SkillState::Wait;
	EnemyMonster->On();
}

void BattleSkill_PlayerFlamethrower::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (1.7f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_PlayerFlamethrower::Update_BackWard(float _DeltaTime)
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

void BattleSkill_PlayerFlamethrower::Update_Flashing(float _DeltaTime)
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
