#include "BattleSkill_PlayerEmber.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
#include "BattleLevel.h"
#include "SkillActor_Ember.h"
BattleSkill_PlayerEmber::BattleSkill_PlayerEmber()
{
}

BattleSkill_PlayerEmber::~BattleSkill_PlayerEmber()
{
}

void BattleSkill_PlayerEmber::EnterState()
{
	BattleSkill_PlayerBase::EnterState();


	EnemyMonster = GetEnemyMonster()->GetRender();

	EmberActor = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>();
	EmberActor->SetEmber(GetEnemyMonster()->GetPos() + StartPos, GetEnemyMonster()->GetPos() + EndPos);

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("TailWhip.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerEmber::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerEmber::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_PlayerEmber::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerEmber::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_PlayerEmber::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	
	CurState = SkillState::Wait;
	EnemyMonster->On();
}

void BattleSkill_PlayerEmber::Update_Wait(float _DeltaTime)
{
	WaitTime +=  _DeltaTime;

	if (0.6f < WaitTime)
	{
		CurState = SkillState::BackWard;
		GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("Ember.wav");
		SFX.LoopCount(1);
		SFX.Volume(BattleDefine::WorldVolumn);
	}
}


void BattleSkill_PlayerEmber::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;
	if (0.12f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
		GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("NormalDamage.wav");
		SfxCtrl.LoopCount(1);
		SfxCtrl.Volume(BattleDefine::WorldVolumn);
	}
	else if (0.06f <= BackwardTime)
	{
		EnemyMonster->SetPosition(float4::Zero);
	}
	else
	{
		EnemyMonster->SetPosition(float4::Right * 8);
	}
}

void BattleSkill_PlayerEmber::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08f <= FlashingTime)
	{
		EnemyMonster->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		EnemyMonster->Off();
	}
}
