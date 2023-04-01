#include "BattleSkill_PlayerDragonBreath.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_DragonBrath.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerDragonBreath::BattleSkill_PlayerDragonBreath() 
{
}

BattleSkill_PlayerDragonBreath::~BattleSkill_PlayerDragonBreath() 
{
}

void BattleSkill_PlayerDragonBreath::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	// GrowlRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
}

void BattleSkill_PlayerDragonBreath::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerDragonBreath::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerDragonBreath::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerDragonBreath::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerDragonBreath::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerDragonBreath::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;

	if (0.28f <= BackwardTime)
	{
		CurState = MoveState::Flashing;
	}
	else if (0.12f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else
	{
		EnemyMonster->SetPosition(float4::Right * 8);
	}
}

void BattleSkill_PlayerDragonBreath::Update_Flashing(float _Deltatime)
{
	FlashingTime += _Deltatime;

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

void BattleSkill_PlayerDragonBreath::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	// 스킬 액터 데스
	// GrowlRender1->Death();
	// GrowlRender1 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}
