#include "BattleSkill_EnemyDragonBreath.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "BattleLevel.h"
#include "SkillActor_DragonBreath.h"
BattleSkill_EnemyDragonBreath::BattleSkill_EnemyDragonBreath()
{
}

BattleSkill_EnemyDragonBreath::~BattleSkill_EnemyDragonBreath()
{
}

void BattleSkill_EnemyDragonBreath::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	BattleMonsterPlayer* Player = GetPlayerMonster();
	PlayerMonster = Player->GetRender();

	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.0f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos + float4({ 16, 16 }), Player->GetPos() + EndPos + float4({ 8, 8 }), 0.15f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.3f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos + float4({ -16, -16 }), Player->GetPos() + EndPos + float4({ -8, -8 }), 0.45f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.6f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos + float4({ 16, 16 }), Player->GetPos() + EndPos + float4({ 8, 8 }), 0.75f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos, Player->GetPos() + EndPos, 0.9f);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_DragonBreath>()->SetDragonBreath(Player->GetPos() + StartPos + float4({ -16, -16 }), Player->GetPos() + EndPos + float4({ -8, -8 }), 1.0f);
}

void BattleSkill_EnemyDragonBreath::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyDragonBreath::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_EnemyDragonBreath::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyDragonBreath::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_EnemyDragonBreath::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;

	CurState = SkillState::Wait;
	PlayerMonster->On();
}

void BattleSkill_EnemyDragonBreath::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (1.7f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_EnemyDragonBreath::Update_BackWard(float _DeltaTime)
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

void BattleSkill_EnemyDragonBreath::Update_Flashing(float _DeltaTime)
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
