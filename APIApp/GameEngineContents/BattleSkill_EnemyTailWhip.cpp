#include "BattleSkill_EnemyTailWhip.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyTailWhip::BattleSkill_EnemyTailWhip() 
{
}

BattleSkill_EnemyTailWhip::~BattleSkill_EnemyTailWhip() 
{
}

void BattleSkill_EnemyTailWhip::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	StartPos1 = EnemyMonster->GetPosition();

	EndPos1 = StartPos1 + float4::Right * 80;

	StartPos2 = EndPos1;

	EndPos2 = StartPos2 + float4::Left * 160;

	StartPos3 = EndPos2;

	EndPos3 = StartPos3 + float4::Right * 80;

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("TailWhip.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyTailWhip::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyTailWhip::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyTailWhip::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyTailWhip::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	Pos1Time += _Deltatime * 6.0f;

	float4 Pos1 = float4::LerpClamp(StartPos1, EndPos1, Pos1Time);
	EnemyMonster->SetPosition(Pos1);

	if (EndPos1.x == EnemyMonster->GetPosition().x)
	{
		Pos2Time += _Deltatime * 3.0f;

		float4 Pos2 = float4::LerpClamp(StartPos2, EndPos2, Pos2Time);
		EnemyMonster->SetPosition(Pos2);
	}

	if (EndPos2.x == EnemyMonster->GetPosition().x)
	{
		Pos3Time += _Deltatime * 6.0f;

		float4 Pos3 = float4::LerpClamp(StartPos3, EndPos3, Pos3Time);
		EnemyMonster->SetPosition(Pos3);
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyTailWhip::Update_BackWard(float _Deltatime)
{
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

void BattleSkill_EnemyTailWhip::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	EnemyMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	Pos1Time = 0.0f;
	Pos2Time = 0.0f;
	Pos3Time = 0.0f;
}