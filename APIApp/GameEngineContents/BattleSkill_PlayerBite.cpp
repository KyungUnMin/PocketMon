#include "BattleSkill_PlayerBite.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Bite.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerBite::BattleSkill_PlayerBite() 
{
}

BattleSkill_PlayerBite::~BattleSkill_PlayerBite() 
{
}

void BattleSkill_PlayerBite::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	BiteRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bite>();
	BiteRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bite>();

	BiteRender1->SetPos({ 710, 50 });
	BiteRender2->SetPos({ 710, 270 });

	BiteRender1->BiteSetting(1);
	BiteRender2->BiteSetting(2);

	BiteRender1->Off();
	BiteRender2->Off();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl(BattleDefine::SfxName_Tackle);
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerBite::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerBite::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerBite::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerBite::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerBite::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	BiteRender1->On();
	BiteRender2->On();

	if (0.5f <= ForwardTime)
	{
		BiteRender1->Off();
		BiteRender2->Off();
	}
	else if (0.35f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 110 });
		BiteRender2->SetPos({ 710, 210 });
	}
	else if (0.4f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 90 });
		BiteRender2->SetPos({ 710, 230 });
	}
	else if (0.35f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 70 });
		BiteRender2->SetPos({ 710, 250 });
	}
	else if (0.3f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 90 });
		BiteRender2->SetPos({ 710, 230 });
	}
	else if (0.25f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 70 });
		BiteRender2->SetPos({ 710, 250 });
	}
	else if (0.2f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 90 });
		BiteRender2->SetPos({ 710, 230 });
	}
	else if (0.15f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 110 });
		BiteRender2->SetPos({ 710, 210 });
	}
	else if (0.1f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 90 });
		BiteRender2->SetPos({ 710, 230 });
	}
	else if (0.05f <= ForwardTime)
	{
		BiteRender1->SetPos({ 710, 70 });
		BiteRender2->SetPos({ 710, 250 });
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerBite::Update_BackWard(float _Deltatime)
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
		EnemyMonster->SetPosition(float4::Zero);
	}
	else
	{
		EnemyMonster->SetPosition(float4::Right * 8);
	}
}

void BattleSkill_PlayerBite::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerBite::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	BiteRender1->Death();
	BiteRender2->Death();
	BiteRender1 = nullptr;
	BiteRender2 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}
