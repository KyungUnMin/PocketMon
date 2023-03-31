#include "BattleSkill_PlayerScratch.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
BattleSkill_PlayerScratch::BattleSkill_PlayerScratch() 
{
}

BattleSkill_PlayerScratch::~BattleSkill_PlayerScratch() 
{
}

void BattleSkill_PlayerScratch::EnterState()
{
	BattleSkill_PlayerBase::EnterState();


	EnemyMonster = GetEnemyMonster()->GetRender();
	EffectRender = GetEnemyMonster()->CreateRender("Scratch.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({128, 128});
	EffectRender->SetAlpha({170});
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "Scratch.bmp", .Loop = false, .FrameIndex = {5, 0, 1, 2, 3, 4, 5}, .FrameTime = {0.3f, 0.04f, 0.04f, 0.04f, 0.07f, 0.1f, 0.1f} });
	EffectRender->ChangeAnimation("Defalut");
}

void BattleSkill_PlayerScratch::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerScratch::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_PlayerScratch::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerScratch::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}

}

void BattleSkill_PlayerScratch::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	CurState = SkillState::Wait;
	EnemyMonster->On();
}

void BattleSkill_PlayerScratch::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (0.45f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_PlayerScratch::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;

	if (0.28f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
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

void BattleSkill_PlayerScratch::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


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