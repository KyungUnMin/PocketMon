#include "BattleSkill_PlayerThunder.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Thunder.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerThunder::BattleSkill_PlayerThunder() 
{
}

BattleSkill_PlayerThunder::~BattleSkill_PlayerThunder() 
{
}

void BattleSkill_PlayerThunder::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	// GrowlRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
}

void BattleSkill_PlayerThunder::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerThunder::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerThunder::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerThunder::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerThunder::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;
}

void BattleSkill_PlayerThunder::ExitState()
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
}
