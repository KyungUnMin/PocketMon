#include "BattleSkill_EnemyVinewhip.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_VineWhip.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyVinewhip::BattleSkill_EnemyVinewhip() 
{
}

BattleSkill_EnemyVinewhip::~BattleSkill_EnemyVinewhip() 
{
}

void BattleSkill_EnemyVinewhip::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	VineRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_VineWhip>();
	VineRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_VineWhip>();

	VineRender1->VineSetting(VineSet::Vine_L_Stop);
	VineRender2->VineSetting(VineSet::VineWhip);

	VineRender1->SetPos({ 570, 130 });
	VineRender2->SetPos({ 260, 370 });

	VineRender1->Off();
	VineRender2->Off();

	GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("VineWhip.wav");
	SFX.LoopCount(1);
	SFX.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyVinewhip::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyVinewhip::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyVinewhip::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyVinewhip::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyVinewhip::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.65f <= ForwardTime)
	{
		VineRender2->On();
	}

	if (0.5f <= ForwardTime)
	{
		VineRender1->VineSetting(VineSet::Vine_L);
	}
	else if (0.4f <= ForwardTime)
	{
		VineRender1->AlphaControl(255);
	}
	else if (0.35f <= ForwardTime)
	{
		VineRender1->AlphaControl(200);
	}
	else if (0.3f <= ForwardTime)
	{
		VineRender1->AlphaControl(150);
	}
	else if (0.25f <= ForwardTime)
	{
		VineRender1->AlphaControl(100);
	}
	else if (0.2f <= ForwardTime)
	{
		VineRender1->AlphaControl(50);
	}
	else if (0.15f <= ForwardTime)
	{
		VineRender1->On();
	}

	if (0.7f <= ForwardTime)
	{
		CurState = MoveState::Backward;
		GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl(BattleDefine::SfxName_Tackle);
		SFX.LoopCount(1);
		SFX.Volume(BattleDefine::WorldVolumn);
	}
}

void BattleSkill_EnemyVinewhip::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;

	if (0.28f <= BackwardTime)
	{
		CurState = MoveState::Flashing;
		GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("NormalDamage.wav");
		SfxCtrl.LoopCount(1);
		SfxCtrl.Volume(BattleDefine::WorldVolumn);
	}
	else if (0.12f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else
	{
		PlayerMonster->SetPosition(float4::Left * 10);
	}
}

void BattleSkill_EnemyVinewhip::Update_Flashing(float _Deltatime)
{
	FlashingTime += _Deltatime;

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

void BattleSkill_EnemyVinewhip::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

	VineRender1->Death();
	VineRender2->Death();

	VineRender1 = nullptr;
	VineRender2 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}