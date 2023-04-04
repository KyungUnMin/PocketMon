#include "BattleSkill_PlayerAgility.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattleMonsterPlayer.h"
BattleSkill_PlayerAgility::BattleSkill_PlayerAgility()
{
}

BattleSkill_PlayerAgility::~BattleSkill_PlayerAgility()
{
}

void BattleSkill_PlayerAgility::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	EffectRender = GetPlayerMonster()->CreateRender("Agility.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 0 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "Agility.bmp", .Start = 0, .End = 7, .InterTime = 0.12f, .Loop = true, });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
}

void BattleSkill_PlayerAgility::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerAgility::SkillState::WaitAppear:
		Update_WaitAppear(_DeltaTime);
		break;
	case BattleSkill_PlayerAgility::SkillState::Appear:
		Update_Appear(_DeltaTime);
		break;
	case BattleSkill_PlayerAgility::SkillState::Disappear:
		Update_Disappear(_DeltaTime);
		break;
	case BattleSkill_PlayerAgility::SkillState::WaitDisappear:
		Update_WaitDisappear(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_PlayerAgility::ExitState()
{
	BattleSkill_PlayerBase::ExitState();
	CurState = SkillState::WaitAppear;

	WaitAppearTime = 0.f;
	AppearTime = 0.f;
	WaitDisappearTime = 0.f;
	DisappearTime = 0.f;
}

void BattleSkill_PlayerAgility::Update_Appear(float _DeltaTime)
{
	AppearTime += _DeltaTime;

	EffectRender->SetAlpha(static_cast<int>(std::lerp(0, 255, AppearTime * 5)));

	if (0.2f <= AppearTime)
	{
		CurState = SkillState::WaitDisappear;
		EffectRender->SetAlpha(255);
	}
}

void BattleSkill_PlayerAgility::Update_WaitAppear(float _DeltaTime)
{
	WaitAppearTime += _DeltaTime;

	if (0.5f < WaitAppearTime)
	{
		CurState = SkillState::Appear;
		GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("BuffSound.wav");
		SFX.LoopCount(1);
		SFX.Volume(BattleDefine::WorldVolumn);
	}
}

void BattleSkill_PlayerAgility::Update_Disappear(float _DeltaTime)
{
	DisappearTime += _DeltaTime;
	if (0.5f <= DisappearTime)
	{
		EffectRender->SetAlpha(0);
		return;
	}
	int _Alpha = static_cast<int>(std::lerp(255, 0, DisappearTime * 2));
	EffectRender->SetAlpha(_Alpha);

}

void BattleSkill_PlayerAgility::Update_WaitDisappear(float _DeltaTime)
{
	WaitDisappearTime += _DeltaTime;

	if (1.2f < WaitDisappearTime)
	{
		CurState = SkillState::Disappear;
	}
}
