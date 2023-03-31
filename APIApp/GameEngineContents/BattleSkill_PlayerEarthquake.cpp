#include "BattleSkill_PlayerEarthquake.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
// #include <��ų ����>

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerEarthquake::BattleSkill_PlayerEarthquake() 
{
}

BattleSkill_PlayerEarthquake::~BattleSkill_PlayerEarthquake() 
{
}

void BattleSkill_PlayerEarthquake::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	// GrowlRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
}

void BattleSkill_PlayerEarthquake::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerEarthquake::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerEarthquake::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerEarthquake::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerEarthquake::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;
}

void BattleSkill_PlayerEarthquake::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	// ��ų ���� ����
	// GrowlRender1->Death();
	// GrowlRender1 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
}
