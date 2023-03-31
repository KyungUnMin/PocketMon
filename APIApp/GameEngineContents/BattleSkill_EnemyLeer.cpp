#include "BattleSkill_EnemyLeer.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Leer.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyLeer::BattleSkill_EnemyLeer() 
{
}

BattleSkill_EnemyLeer::~BattleSkill_EnemyLeer() 
{
}

void BattleSkill_EnemyLeer::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	LeerRender = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Leer>();
	LeerRender->SetPos({ 540, 150 });
	LeerRender->Off();
}

void BattleSkill_EnemyLeer::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyLeer::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyLeer::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyLeer::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyLeer::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	LeerRender->On();

	if (0.2f <= ForwardTime)
	{
		EnemyMonster->SetScale({ 256, 256 });
	}
	else if (0.15f <= ForwardTime)
	{
		EnemyMonster->SetScale({ 280, 280 });
	}
	else if (0.1f <= ForwardTime)
	{
		EnemyMonster->SetScale({ 270, 270 });
	}
	else if (0.05f <= ForwardTime)
	{
		EnemyMonster->SetScale({ 260, 260 });
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyLeer::Update_BackWard(float _Deltatime)
{
	LeerRender->Off();

	BackwardTime += _Deltatime;

	if (0.4f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else if (0.2f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Left * 10);
	}
}

void BattleSkill_EnemyLeer::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	LeerRender->Death();
	LeerRender = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
}

