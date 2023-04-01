#include "BattleSkill_PlayerAirSlash.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_AirSlash.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerAirSlash::BattleSkill_PlayerAirSlash() 
{
}

BattleSkill_PlayerAirSlash::~BattleSkill_PlayerAirSlash() 
{
}

void BattleSkill_PlayerAirSlash::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	AirSlashRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_AirSlash>();
	AirSlashRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_AirSlash>();
	
	AirSlashRender1->SetPos({ 680, 160 });
	AirSlashRender2->SetPos({ 740, 170 });

	AirSlashRender1->Off();
	AirSlashRender2->Off();
}

void BattleSkill_PlayerAirSlash::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.8f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerAirSlash::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerAirSlash::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerAirSlash::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerAirSlash::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.4f <= ForwardTime)
	{
		PlayerMonster->Off();
		IsMove = false;
	}

	if (true == IsMove)
	{
		float MoveSpeed = 150.0f;

		if (0.3f <= ForwardTime && 0.4f >= ForwardTime)
		{
			MoveSpeed = 3500.0f;
		}
		else if (0.1f <= ForwardTime && 0.3f >= ForwardTime)
		{
			MoveSpeed = 0.0f;
		}

		PlayerMonster->SetMove(float4::Up * MoveSpeed * _Deltatime);
	}

	if (0.4f <= ForwardTime)
	{
		PlayerMonster->SetAlpha(0);
	}
	else if (0.375f <= ForwardTime)
	{
		PlayerMonster->SetAlpha(60);
	}
	else if (0.35f <= ForwardTime)
	{
		PlayerMonster->SetAlpha(120);
	}
	else if (0.325f <= ForwardTime)
	{
		PlayerMonster->SetAlpha(180);
	}

	if (1.0f <= ForwardTime)
	{
		PlayerMonster->On();
		PlayerMonster->SetPosition(float4::Zero);
		PlayerMonster->SetAlpha(255);
	}

	if (0.65f <= ForwardTime)
	{
		AirSlashRender2->On();
	}
	
	if (0.5f <= ForwardTime)
	{
		AirSlashRender1->On();
	}

	if (1.2f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerAirSlash::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerAirSlash::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerAirSlash::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	AirSlashRender1->Death();
	AirSlashRender2->Death();

	AirSlashRender1 = nullptr;
	AirSlashRender2 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	IsMove = true;
}
