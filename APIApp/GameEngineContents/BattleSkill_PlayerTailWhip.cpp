#include "BattleSkill_PlayerTailWhip.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerTailWhip::BattleSkill_PlayerTailWhip() 
{
}

BattleSkill_PlayerTailWhip::~BattleSkill_PlayerTailWhip() 
{
}

void BattleSkill_PlayerTailWhip::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	StartPos1 = PlayerMonster->GetPosition();
	EndPos1 = StartPos1 + float4::Right * 100;

	StartPos2 = PlayerMonster->GetPosition();
	EndPos2 = StartPos2 + float4::Left * 200;

	StartPos3 = PlayerMonster->GetPosition();
	EndPos3 = StartPos3 + float4::Right * 100;
}

void BattleSkill_PlayerTailWhip::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerTailWhip::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerTailWhip::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerTailWhip::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	float4 Pos1 = float4::LerpClamp(StartPos1, EndPos1, ForwardTime);
	PlayerMonster->SetPosition(Pos1);

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerTailWhip::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;
}

void BattleSkill_PlayerTailWhip::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
}
