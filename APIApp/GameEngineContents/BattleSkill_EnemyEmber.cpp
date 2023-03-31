#include "BattleSkill_EnemyEmber.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
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

	EffectRender = GetPlayerMonster()->CreateRender("Ember.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetPosition(StartPos);
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "Ember.bmp", .Loop = false, .FrameIndex = {0, 1, 2, 3, 4, 5, 6 }, .FrameTime = {0.65f, 0.07f, 0.07f, 0.07f, 0.07f, 0.07f, 0.07f} });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
}

void BattleSkill_EnemyEmber::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyEmber::SkillState::Shoot:
		Update_Shoot(_DeltaTime);
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

	if (true == EffectRender->IsAnimationEnd())
	{
		EffectRender->Off();
	}
}

void BattleSkill_EnemyEmber::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	ShootTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;

	CurState = SkillState::Shoot;
	PlayerMonster->On();
}

void BattleSkill_EnemyEmber::Update_Shoot(float _DeltaTime)
{
	ShootTime += EmberSpeed * _DeltaTime;
	EffectRender->SetPosition(float4::LerpClamp(StartPos, EndPos, ShootTime));

	if (1.0f < ShootTime)
	{
		CurState = SkillState::BackWard;
	}
}


void BattleSkill_EnemyEmber::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;
	EffectRender->SetMove(float4::Left * 172 * _DeltaTime);
	if (0.12f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
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
