#include "BattleSkill_EnemyEarthquake.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"
#include "SkillActor_BlackBox.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyEarthquake::BattleSkill_EnemyEarthquake() 
{
}

BattleSkill_EnemyEarthquake::~BattleSkill_EnemyEarthquake() 
{
}

void BattleSkill_EnemyEarthquake::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	BBox = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_BlackBox>();

	EnemyMonster->EffectCameraOff();
	FriendlyHPBackground::FriendlyPtr->GetWindowPtr()->EffectCameraOff();
	FriendlyHPBackground::FriendlyPtr->GetHPPtr()->EffectCameraOff();
	FriendlyHPBackground::FriendlyPtr->GetEXPPtr()->EffectCameraOff();
	EnemyHPBackground::EnemyPtr->GetWindowPtr()->EffectCameraOff();
	EnemyHPBackground::EnemyPtr->GetHPPtr()->EffectCameraOff();

	InitCameraPos = BattleLevel::BattleLevelPtr->GetCameraPos();

	GameEngineSoundPlayer SFX = GameEngineResources::GetInst().SoundPlayToControl("Earthquake.wav");
	SFX.LoopCount(1);
	SFX.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyEarthquake::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 2.3f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyEarthquake::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyEarthquake::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyEarthquake::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyEarthquake::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.2f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos);
	}
	else if (1.15f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (1.1f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (1.05f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (1.0f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.95f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.9f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.85f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.8f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.75f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.7f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.65f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.6f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.55f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.5f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}

	if (1.4f <= ForwardTime)
	{
		BBox->FadeOutStart();
	}
	else if (0.1f <= ForwardTime)
	{
		BBox->FadeInStart();
	}

	if (1.7f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyEarthquake::Update_BackWard(float _Deltatime)
{
	BackwardTime += _Deltatime;

	if (0.28f <= BackwardTime)
	{
		CurState = MoveState::Flashing;
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

void BattleSkill_EnemyEarthquake::Update_Flashing(float _Deltatime)
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

void BattleSkill_EnemyEarthquake::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	EnemyMonster->EffectCameraOn();
	FriendlyHPBackground::FriendlyPtr->GetWindowPtr()->EffectCameraOn();
	FriendlyHPBackground::FriendlyPtr->GetHPPtr()->EffectCameraOn();
	FriendlyHPBackground::FriendlyPtr->GetEXPPtr()->EffectCameraOn();
	EnemyHPBackground::EnemyPtr->GetWindowPtr()->EffectCameraOn();
	EnemyHPBackground::EnemyPtr->GetHPPtr()->EffectCameraOn();

	EnemyMonster->SetPosition(float4::Zero);

	BBox->Death();
	BBox = nullptr;
	
	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}

