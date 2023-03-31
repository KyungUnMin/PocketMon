#include "BattleSkill_PlayerLeer.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Leer.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerLeer::BattleSkill_PlayerLeer() 
{
}

BattleSkill_PlayerLeer::~BattleSkill_PlayerLeer() 
{
}

void BattleSkill_PlayerLeer::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	LeerRender = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Leer>();
	LeerRender->SetPos({ 380, 320 });

	LeerRender->Off();
}

void BattleSkill_PlayerLeer::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerLeer::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerLeer::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerLeer::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	LeerRender->On();
	
	if (0.2f <= ForwardTime)
	{
		PlayerMonster->SetScale({ 256, 256 });
	}
	else if (0.15f <= ForwardTime)
	{
		PlayerMonster->SetScale({ 280, 280 });
	}
	else if (0.1f <= ForwardTime)
	{
		PlayerMonster->SetScale({ 270, 270 });
	}
	else if (0.05f <= ForwardTime)
	{
		PlayerMonster->SetScale({ 260, 260 });
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerLeer::Update_BackWard(float _Deltatime)
{
	LeerRender->Off();

	BackwardTime += _Deltatime;

	if (0.4f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else if (0.2f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Right * 5);
	}
}

void BattleSkill_PlayerLeer::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	LeerRender->Death();
	LeerRender = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
}

