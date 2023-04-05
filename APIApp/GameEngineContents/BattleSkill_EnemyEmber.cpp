#include "BattleSkill_EnemyEmber.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "BattleLevel.h"
#include "SkillActor_Ember.h"
BattleSkill_EnemyEmber::BattleSkill_EnemyEmber()
{
}

BattleSkill_EnemyEmber::~BattleSkill_EnemyEmber()
{
}

void BattleSkill_EnemyEmber::EnterState()
{
	BattleSkill_EnemyBase::EnterState();


	PlayerMonster = GetPlayerMonster()->GetRender();

	EmberActor = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Ember>();
	EmberActor->SetEmber(GetPlayerMonster()->GetPos() + StartPos, GetPlayerMonster()->GetPos() + EndPos);

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("TailWhip.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyEmber::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyEmber::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_EnemyEmber::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyEmber::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_EnemyEmber::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;

	CurState = SkillState::Wait;
	PlayerMonster->On();
}

void BattleSkill_EnemyEmber::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (0.6f < WaitTime)
	{
		CurState = SkillState::BackWard;
		GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("Ember.wav");
		SFX.LoopCount(1);
		SFX.Volume(BattleDefine::WorldVolumn);
	}
}


void BattleSkill_EnemyEmber::Update_BackWard(float _DeltaTime)
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
		PlayerMonster->SetPosition(float4::Zero);
	}
	else
	{
		PlayerMonster->SetPosition(float4::Left * 8);
	}
}

void BattleSkill_EnemyEmber::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08f <= FlashingTime)
	{
		PlayerMonster->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		PlayerMonster->Off();
	}
}
