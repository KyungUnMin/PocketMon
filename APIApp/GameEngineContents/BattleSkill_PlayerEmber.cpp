#include "BattleSkill_PlayerEmber.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
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

	EffectRender = GetEnemyMonster()->CreateRender("Ember.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetPosition(StartPos);
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "Ember.bmp", .Loop = false, .FrameIndex = {0, 1, 2, 3, 4, 5, 6 }, .FrameTime = {0.65f, 0.07f, 0.07f, 0.07f, 0.07f, 0.07f, 0.07f} });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
}

void BattleSkill_PlayerEmber::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerEmber::SkillState::Shoot:
		Update_Shoot(_DeltaTime);
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

	if (true == EffectRender->IsAnimationEnd())
	{
		EffectRender->Off();
	}
}

void BattleSkill_PlayerEmber::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	ShootTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	
	CurState = SkillState::Shoot;
	EnemyMonster->On();
}

void BattleSkill_PlayerEmber::Update_Shoot(float _DeltaTime)
{
	ShootTime += EmberSpeed * _DeltaTime;
	EffectRender->SetPosition(float4::LerpClamp(StartPos, EndPos, ShootTime));

	if (1.0f < ShootTime)
	{
		CurState = SkillState::BackWard;
	}
}


void BattleSkill_PlayerEmber::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;
	EffectRender->SetMove(float4::Right * 172 * _DeltaTime);
	if (0.12f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
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
