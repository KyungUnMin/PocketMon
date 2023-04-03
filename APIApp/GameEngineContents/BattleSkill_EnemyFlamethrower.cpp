#include "BattleSkill_EnemyFlamethrower.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "BattleLevel.h"
#include "SkillActor_Ember.h"
BattleSkill_EnemyFlamethrower::BattleSkill_EnemyFlamethrower()
{
}

BattleSkill_EnemyFlamethrower::~BattleSkill_EnemyFlamethrower()
{
}

void BattleSkill_EnemyFlamethrower::EnterState()
{
	BattleSkill_EnemyBase::EnterState();
	
	BattleMonsterPlayer* Player = GetPlayerMonster();
	PlayerMonster = Player->GetRender();

	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.0f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos + float4({ 16, 16 }), Player->GetPos() + EndPos + float4({ 8, 8 }), 0.15f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.3f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos + float4({ -16, -16 }), Player->GetPos() + EndPos + float4({ -8, -8 }), 0.45f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.6f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos + float4({ 16, 16 }), Player->GetPos() + EndPos + float4({ 8, 8 }), 0.75f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.9f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>()->SetEmber(Player->GetPos() + StartPos + float4({ -16, -16 }), Player->GetPos() + EndPos + float4({ -8, -8 }), 1.0f);
}

void BattleSkill_EnemyFlamethrower::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyFlamethrower::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_EnemyFlamethrower::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyFlamethrower::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_EnemyFlamethrower::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;

	CurState = SkillState::Wait;
	PlayerMonster->On();
}

void BattleSkill_EnemyFlamethrower::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (1.7f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_EnemyFlamethrower::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;
	if (0.12f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
	}
	else if (0.06f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else
	{
		PlayerMonster->SetPosition(float4::Right * 8);
	}
}

void BattleSkill_EnemyFlamethrower::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08f <= FlashingTime)
	{
		PlayerMonster->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		PlayerMonster->Off();
	}
}
