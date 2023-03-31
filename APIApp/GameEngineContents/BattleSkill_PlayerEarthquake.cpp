#include "BattleSkill_PlayerEarthquake.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"

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

	//FriendlyHPBackground::FriendlyPtr->

	InitCameraPos = BattleLevel::BattleLevelPtr->GetCameraPos();
}

void BattleSkill_PlayerEarthquake::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
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
	case BattleSkill_PlayerEarthquake::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerEarthquake::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.7f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos);
	}
	else if (0.6f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.5f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.4f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.3f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.2f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.1f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerEarthquake::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerEarthquake::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerEarthquake::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}

