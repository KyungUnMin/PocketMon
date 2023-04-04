#include "BattleSkill_PlayerVineWhip.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_VineWhip.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerVineWhip::BattleSkill_PlayerVineWhip()
{
}

BattleSkill_PlayerVineWhip::~BattleSkill_PlayerVineWhip()
{
}

void BattleSkill_PlayerVineWhip::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	VineRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_VineWhip>();
	VineRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_VineWhip>();

	VineRender1->VineSetting(VineSet::Vine_R_Stop);
	VineRender2->VineSetting(VineSet::VineWhip);
	
	VineRender1->SetPos({ 390, 330 });
	VineRender2->SetPos({ 710, 170 });

	VineRender1->Off();
	VineRender2->Off();

	GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("VineWhip.wav");
	SFX.LoopCount(1);
	SFX.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerVineWhip::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerVineWhip::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerVineWhip::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerVineWhip::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerVineWhip::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.65f <= ForwardTime)
	{
		VineRender2->On();
	}

	if (0.5f <= ForwardTime)
	{
		VineRender1->VineSetting(VineSet::Vine_R);
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

void BattleSkill_PlayerVineWhip::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;

	if (0.28f <= BackwardTime)
	{
		CurState = MoveState::Flashing;
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

void BattleSkill_PlayerVineWhip::Update_Flashing(float _Deltatime)
{
	FlashingTime += _Deltatime;

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

void BattleSkill_PlayerVineWhip::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	VineRender1->Death();
	VineRender2->Death();

	VineRender1 = nullptr;
	VineRender2 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}
