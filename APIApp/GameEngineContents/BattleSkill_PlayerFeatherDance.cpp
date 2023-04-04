#include "BattleSkill_PlayerFeatherDance.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
BattleSkill_PlayerFeatherDance::BattleSkill_PlayerFeatherDance()
{
}

BattleSkill_PlayerFeatherDance::~BattleSkill_PlayerFeatherDance()
{
}

void BattleSkill_PlayerFeatherDance::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	EffectRender = GetPlayerMonster()->CreateRender("FeatherDance.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 0 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "FeatherDance.bmp", .Start = 0, .End = 7, .InterTime = 0.12f, .Loop = true, });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
}

void BattleSkill_PlayerFeatherDance::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerFeatherDance::SkillState::WaitAppear:
		Update_WaitAppear(_DeltaTime);
		break;
	case BattleSkill_PlayerFeatherDance::SkillState::Appear:
		Update_Appear(_DeltaTime);
		break;
	case BattleSkill_PlayerFeatherDance::SkillState::Disappear:
		Update_Disappear(_DeltaTime);
		break;
	case BattleSkill_PlayerFeatherDance::SkillState::WaitDisappear:
		Update_WaitDisappear(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_PlayerFeatherDance::ExitState()
{
	BattleSkill_PlayerBase::ExitState();
	CurState = SkillState::WaitAppear;
	
	WaitAppearTime = 0.f;
	AppearTime = 0.f;
	WaitDisappearTime = 0.f;
	DisappearTime = 0.f;
}

void BattleSkill_PlayerFeatherDance::Update_Appear(float _DeltaTime)
{
	AppearTime += _DeltaTime;

	EffectRender->SetAlpha(static_cast<int>(std::lerp(0, 255, AppearTime * 5)));

	if (0.2f <= AppearTime)
	{
		CurState = SkillState::WaitDisappear;
		EffectRender->SetAlpha(255);
	}
}

void BattleSkill_PlayerFeatherDance::Update_WaitAppear(float _DeltaTime)
{
	WaitAppearTime += _DeltaTime;

	if (0.5f < WaitAppearTime)
	{
		CurState = SkillState::Appear;
	}
}

void BattleSkill_PlayerFeatherDance::Update_Disappear(float _DeltaTime)
{
	DisappearTime += _DeltaTime;
	int _Alpha = static_cast<int>(std::lerp(255, 0, DisappearTime * 5));
	EffectRender->SetAlpha(_Alpha);

	if (0.2f <= AppearTime)
	{
		EffectRender->SetAlpha(0);
	}
}

void BattleSkill_PlayerFeatherDance::Update_WaitDisappear(float _DeltaTime)
{
	WaitDisappearTime += _DeltaTime;

	if (1.7f < WaitDisappearTime)
	{
		CurState = SkillState::Disappear;
	}
}
