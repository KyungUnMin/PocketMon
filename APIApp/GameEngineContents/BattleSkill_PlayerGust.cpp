#include "BattleSkill_PlayerGust.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Gust.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerGust::BattleSkill_PlayerGust() 
{
}

BattleSkill_PlayerGust::~BattleSkill_PlayerGust() 
{
}

void BattleSkill_PlayerGust::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	// GrowlRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
}

void BattleSkill_PlayerGust::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerGust::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerGust::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerGust::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerGust::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;
}

void BattleSkill_PlayerGust::ExitState()
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
