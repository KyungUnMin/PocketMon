#include "BattleSkill_PlayerThunderbolt.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Thunderbolt.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerThunderbolt::BattleSkill_PlayerThunderbolt() 
{
}

BattleSkill_PlayerThunderbolt::~BattleSkill_PlayerThunderbolt() 
{
}

void BattleSkill_PlayerThunderbolt::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	// GrowlRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
}

void BattleSkill_PlayerThunderbolt::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerThunderbolt::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerThunderbolt::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerThunderbolt::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerThunderbolt::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerThunderbolt::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerThunderbolt::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerThunderbolt::ExitState()
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
	float FlashingTime = 0.f;
}
