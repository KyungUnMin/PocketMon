#include "BattleSkill_EnemyTackle.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleMonsterEnemy.h"
#include "BattleMonsterPlayer.h"

BattleSkill_EnemyTackle::BattleSkill_EnemyTackle()
{

}

BattleSkill_EnemyTackle::~BattleSkill_EnemyTackle()
{

}

void BattleSkill_EnemyTackle::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	EnemyMonster = GetEnemyMonster()->GetRender();
	EffectRender = GetPlayerMonster()->CreateRender("Tackle.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScaleToImage();
	EffectScale = EffectRender->GetScale();
	EffectRender->SetAlpha(150);
}

void BattleSkill_EnemyTackle::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 1.1f))
		return;

	switch (CurState)
	{
	case BattleSkill_EnemyTackle::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyTackle::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyTackle::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}


void BattleSkill_EnemyTackle::Update_Forward(float _DeltaTime)
{
	ForwardTimer += _DeltaTime;
	float Ratio = (ForwardTimer / ForwardDuration);

	float4 NowOffset = float4::LerpClamp(float4::Zero, MoveOffset, Ratio);
	EffectRender->SetPosition(NowOffset);

	float4 NowEffectScale = float4::LerpClamp(float4::Zero, EffectScale, Ratio);
	EffectRender->SetScale(NowEffectScale);

	if (Ratio <= 1.f)
		return;

	CurState = MoveState::Backward;
	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl(BattleDefine::SfxName_Tackle);
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(SfxVolumn * BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyTackle::Update_BackWard(float _DeltaTime)
{
	BackwardTimer += _DeltaTime;
	float Ratio = (BackwardTimer / BackwardDuration);

	float4 NowOffset = float4::LerpClamp(MoveOffset, float4::Zero, Ratio);
	EnemyMonster->SetPosition(NowOffset);

	float4 NowEffectScale = float4::LerpClamp(EffectScale, float4::Zero, Ratio);
	EffectRender->SetScale(NowEffectScale);


	if (BackwardTimer > BackwardDuration + 0.2f)
	{
		CurState = MoveState::Flashing;
		GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("NormalDamage.wav");
		SfxCtrl.LoopCount(1);
		SfxCtrl.Volume(BattleDefine::WorldVolumn);
	}
}

void BattleSkill_EnemyTackle::Update_Flashing(float _DeltaTime)
{
	FlashingTime += _DeltaTime;


	if (0.08 <= FlashingTime)
	{
		GetPlayerMonster()->GetRender()->On();
		FlashingTime = 0;
	}
	else if (0.04f <= FlashingTime)
	{
		GetPlayerMonster()->GetRender()->Off();
	}
}



void BattleSkill_EnemyTackle::ExitState()
{
	GetPlayerMonster()->GetRender()->On();
	BattleSkill_EnemyBase::ExitState();
	EnemyMonster->SetPosition(float4::Zero);
	EnemyMonster = nullptr;

	EffectRender->Death();
	EffectRender = nullptr;

	CurState = MoveState::Forward;

	ForwardTimer = 0.f;
	BackwardTimer = 0.f;

}