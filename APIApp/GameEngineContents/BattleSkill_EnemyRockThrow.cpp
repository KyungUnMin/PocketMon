#include "BattleSkill_EnemyRockThrow.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "SkillActor_RockThrow.h"
#include "BattleLevel.h"
BattleSkill_EnemyRockThrow::BattleSkill_EnemyRockThrow()
{
}

BattleSkill_EnemyRockThrow::~BattleSkill_EnemyRockThrow()
{
}

void BattleSkill_EnemyRockThrow::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();

	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetPlayerMonster()->GetPos() + float4({ -24, -12 }), { 64, 64 }, 0.0f, false);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetPlayerMonster()->GetPos() + float4({ -12, 12 }), { 96, 96 }, 0.2f, true);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetPlayerMonster()->GetPos() + float4({ 12, -4 }), { 64, 64 }, 0.5f, false);
	BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RockThrow>()->SetRock(GetPlayerMonster()->GetPos() + float4({ 24, 0 }), { 32, 32 }, 0.57f, true);
	GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("RockThrow.wav");
	SFX.LoopCount(3);
	SFX.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyRockThrow::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyRockThrow::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_EnemyRockThrow::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyRockThrow::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}

}

void BattleSkill_EnemyRockThrow::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	CurState = SkillState::Wait;
	PlayerMonster->On();
}

void BattleSkill_EnemyRockThrow::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (0.7f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_EnemyRockThrow::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;

	if (1.25f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
		GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("NormalDamage.wav");
		SfxCtrl.LoopCount(1);
		SfxCtrl.Volume(BattleDefine::WorldVolumn);
	}
	else if (0.9f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else if (0.8f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Down * 8);
	}
	else if (0.7f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else if (0.6f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Down * 8);
	}
	else if (0.5f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else if (0.4f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Down * 8);
	}
	else if (0.3f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else if (0.2f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Down * 8);
	}
	else if (0.1f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else
	{
		PlayerMonster->SetPosition(float4::Down * 8);
	}
}

void BattleSkill_EnemyRockThrow::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08 <= FlashingTime)
	{
		PlayerMonster->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		PlayerMonster->Off();
	}
}