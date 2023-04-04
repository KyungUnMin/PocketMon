#include "BattleSkill_EnemyFeatherDance.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
BattleSkill_EnemyFeatherDance::BattleSkill_EnemyFeatherDance()
{
}

BattleSkill_EnemyFeatherDance::~BattleSkill_EnemyFeatherDance()
{
}

void BattleSkill_EnemyFeatherDance::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	EffectRender = GetEnemyMonster()->CreateRender("FeatherDance.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 0 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "FeatherDance.bmp", .Start = 0, .End = 7, .InterTime = 0.12f, .Loop = true, });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
}

void BattleSkill_EnemyFeatherDance::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyFeatherDance::SkillState::WaitAppear:
		Update_WaitAppear(_DeltaTime);
		break;
	case BattleSkill_EnemyFeatherDance::SkillState::Appear:
		Update_Appear(_DeltaTime);
		break;
	case BattleSkill_EnemyFeatherDance::SkillState::Disappear:
		Update_Disappear(_DeltaTime);
		break;
	case BattleSkill_EnemyFeatherDance::SkillState::WaitDisappear:
		Update_WaitDisappear(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_EnemyFeatherDance::ExitState()
{
	BattleSkill_EnemyBase::ExitState();
	CurState = SkillState::WaitAppear;

	WaitAppearTime = 0.f;
	AppearTime = 0.f;
	WaitDisappearTime = 0.f;
	DisappearTime = 0.f;
}

void BattleSkill_EnemyFeatherDance::Update_Appear(float _DeltaTime)
{
	AppearTime += _DeltaTime;

	EffectRender->SetAlpha(static_cast<int>(std::lerp(0, 255, AppearTime * 5)));

	if (0.2f <= AppearTime)
	{
		CurState = SkillState::WaitDisappear;
		EffectRender->SetAlpha(255);
	}
}

void BattleSkill_EnemyFeatherDance::Update_WaitAppear(float _DeltaTime)
{
	WaitAppearTime += _DeltaTime;

	if (0.5f < WaitAppearTime)
	{
		CurState = SkillState::Appear;
	}
}

void BattleSkill_EnemyFeatherDance::Update_Disappear(float _DeltaTime)
{
	DisappearTime += _DeltaTime;
	int _Alpha = static_cast<int>(std::lerp(255, 0, DisappearTime * 5));
	EffectRender->SetAlpha(_Alpha);

	if (0.2f <= AppearTime)
	{
		EffectRender->SetAlpha(0);
	}
}

void BattleSkill_EnemyFeatherDance::Update_WaitDisappear(float _DeltaTime)
{
	WaitDisappearTime += _DeltaTime;

	if (1.7f < WaitDisappearTime)
	{
		CurState = SkillState::Disappear;
	}
}
