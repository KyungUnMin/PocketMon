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

	StartPos2 = EndPos1;

	EndPos2 = StartPos2 + float4::Left * 200;

	StartPos3 = EndPos2;

	EndPos3 = StartPos3 + float4::Right * 100;

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("TailWhip.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerTailWhip::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
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

	Pos1Time += _Deltatime * 6.0f;

	float4 Pos1 = float4::LerpClamp(StartPos1, EndPos1, Pos1Time);
	PlayerMonster->SetPosition(Pos1);

	if (EndPos1.x == PlayerMonster->GetPosition().x)
	{
		Pos2Time += _Deltatime * 3.0f;

		float4 Pos2 = float4::LerpClamp(StartPos2, EndPos2, Pos2Time);
		PlayerMonster->SetPosition(Pos2);
	}

	if (EndPos2.x == PlayerMonster->GetPosition().x)
	{
		Pos3Time += _Deltatime * 6.0f;

		float4 Pos3 = float4::LerpClamp(StartPos3, EndPos3, Pos3Time);
		PlayerMonster->SetPosition(Pos3);
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerTailWhip::Update_BackWard(float _Deltatime)
{
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

void BattleSkill_PlayerTailWhip::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	Pos1Time = 0.0f;
	Pos2Time = 0.0f;
	Pos3Time = 0.0f;
}
