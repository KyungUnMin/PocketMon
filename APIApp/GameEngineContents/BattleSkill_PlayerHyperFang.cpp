#include "BattleSkill_PlayerHyperFang.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"
#include "SkillActor_Bite.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerHyperFang::BattleSkill_PlayerHyperFang() 
{
}

BattleSkill_PlayerHyperFang::~BattleSkill_PlayerHyperFang() 
{
}

void BattleSkill_PlayerHyperFang::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	PlayerMonster->EffectCameraOff();
	FriendlyHPBackground::FriendlyPtr->GetWindowPtr()->EffectCameraOff();
	FriendlyHPBackground::FriendlyPtr->GetHPPtr()->EffectCameraOff();
	FriendlyHPBackground::FriendlyPtr->GetEXPPtr()->EffectCameraOff();
	EnemyHPBackground::EnemyPtr->GetWindowPtr()->EffectCameraOff();
	EnemyHPBackground::EnemyPtr->GetHPPtr()->EffectCameraOff();

	InitCameraPos = BattleLevel::BattleLevelPtr->GetCameraPos();

	BiteRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bite>();
	BiteRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bite>();

	BiteRender1->SetPos({ 710, 50 });
	BiteRender2->SetPos({ 710, 270 });

	BiteRender1->BiteSetting(1);
	BiteRender2->BiteSetting(2);

	BiteRender1->Off();
	BiteRender2->Off();
}

void BattleSkill_PlayerHyperFang::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerHyperFang::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerHyperFang::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerHyperFang::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerHyperFang::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.8f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos);
	}
	else if (0.7f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.6f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}
	else if (0.5f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Down * 10);
	}
	else if (0.4f <= ForwardTime)
	{
		BattleLevel::BattleLevelPtr->SetCameraPos(InitCameraPos + float4::Up * 10);
	}

	if (0.35f <= ForwardTime)
	{
		BiteRender1->Off();
		BiteRender2->Off();
	}
	else if (0.3f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 110 });
		BiteRender2->SetPos({ 710, 210 });
	}
	else if (0.2f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 90 });
		BiteRender2->SetPos({ 710, 230 });
	}
	else if (0.1f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 70 });
		BiteRender2->SetPos({ 710, 250 });
	}
	else if (0.01f <= ForwardTime)
	{
		BiteRender1->On();
		BiteRender2->On();
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerHyperFang::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerHyperFang::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerHyperFang::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

	PlayerMonster->EffectCameraOn();
	FriendlyHPBackground::FriendlyPtr->GetWindowPtr()->EffectCameraOn();
	FriendlyHPBackground::FriendlyPtr->GetHPPtr()->EffectCameraOn();
	FriendlyHPBackground::FriendlyPtr->GetEXPPtr()->EffectCameraOn();
	EnemyHPBackground::EnemyPtr->GetWindowPtr()->EffectCameraOn();
	EnemyHPBackground::EnemyPtr->GetHPPtr()->EffectCameraOn();

	BiteRender1->Death();
	BiteRender2->Death();

	BiteRender1 = nullptr;
	BiteRender2 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}
