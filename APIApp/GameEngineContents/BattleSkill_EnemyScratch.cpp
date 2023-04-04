#include "BattleSkill_EnemyScratch.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
BattleSkill_EnemyScratch::BattleSkill_EnemyScratch() 
{
}

BattleSkill_EnemyScratch::~BattleSkill_EnemyScratch() 
{
}

void BattleSkill_EnemyScratch::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EffectRender = GetPlayerMonster()->CreateRender("Scratch.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 170 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "Scratch.bmp", .Loop = false, .FrameIndex = {5, 0, 1, 2, 3, 4, 5}, .FrameTime = {0.3f, 0.04f, 0.04f, 0.04f, 0.07f, 0.1f, 0.1f} });
	EffectRender->ChangeAnimation("Defalut");

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("Scratch.mp3");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyScratch::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyScratch::SkillState::Wait:
		Update_Wait(_DeltaTime);
		break;
	case BattleSkill_EnemyScratch::SkillState::BackWard:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyScratch::SkillState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	default:
		break;
	}
}

void BattleSkill_EnemyScratch::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	WaitTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	CurState = SkillState::Wait;
	PlayerMonster->On();
}

void BattleSkill_EnemyScratch::Update_Wait(float _DeltaTime)
{
	WaitTime += _DeltaTime;

	if (0.45f < WaitTime)
	{
		CurState = SkillState::BackWard;
	}
}

void BattleSkill_EnemyScratch::Update_BackWard(float _DeltaTime)
{
	BackwardTime += _DeltaTime;

	if (0.28f <= BackwardTime)
	{
		CurState = SkillState::Flashing;
	}
	else if (0.12f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else
	{
		PlayerMonster->SetPosition(float4::Right * 8);
	}
}

void BattleSkill_EnemyScratch::Update_Flashing(float _DeltaTime)
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
