#include "BattleSkill_PlayerThunderbolt.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Thunderbolt.h"
#include "SkillActor_BlackBox.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerThunderbolt::BattleSkill_PlayerThunderbolt() 
{
}

BattleSkill_PlayerThunderbolt::~BattleSkill_PlayerThunderbolt() 
{
}

void BattleSkill_PlayerThunderbolt::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	ThunderboltRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender4 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender5 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();

	BBox = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_BlackBox>();

	ThunderboltRender1->SetPos({ 620, 100 });
	ThunderboltRender2->SetPos({ 690, 60 });
	ThunderboltRender3->SetPos({ 720, 140 });
	ThunderboltRender4->SetPos({ 780, 120 });

	ThunderboltRender5->SetPos({ 710, 180 });

	ThunderboltRender5->ThunderboltAfterSet();

	ThunderboltRender1->Off();
	ThunderboltRender2->Off();
	ThunderboltRender3->Off();
	ThunderboltRender4->Off();
	ThunderboltRender5->Off();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("Thunderbolt.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerThunderbolt::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.3f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerThunderbolt::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerThunderbolt::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerThunderbolt::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerThunderbolt::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.2f <= ForwardTime)
	{
		ThunderboltRender5->On();
	}

	if (1.0f <= ForwardTime)
	{
		ThunderboltRender4->Off();
	}
	else if (0.7f <= ForwardTime)
	{
		ThunderboltRender4->On();
		ThunderboltRender4->SetMove(float4::Down * 150.0f * _Deltatime);
	}

	if (0.9f <= ForwardTime)
	{
		ThunderboltRender3->Off();
	}
	else if (0.6f <= ForwardTime)
	{
		ThunderboltRender3->On();
		ThunderboltRender3->SetMove(float4::Down * 150.0f * _Deltatime);
	}

	if (0.8f <= ForwardTime)
	{
		ThunderboltRender2->Off();
	}
	else if (0.5f <= ForwardTime)
	{
		ThunderboltRender2->On();
		ThunderboltRender2->SetMove(float4::Down * 150.0f * _Deltatime);
	}

	if (0.7f <= ForwardTime)
	{
		ThunderboltRender1->Off();
	}
	else if (0.4f <= ForwardTime)
	{
		ThunderboltRender1->On();
		ThunderboltRender1->SetMove(float4::Down * 150.0f * _Deltatime);
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

void BattleSkill_PlayerThunderbolt::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerThunderbolt::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerThunderbolt::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	ThunderboltRender1->Death();
	ThunderboltRender2->Death();
	ThunderboltRender3->Death();
	ThunderboltRender4->Death();
	ThunderboltRender5->Death();
	BBox->Death();

	ThunderboltRender1 = nullptr;
	ThunderboltRender2 = nullptr;
	ThunderboltRender3 = nullptr;
	ThunderboltRender4 = nullptr;
	ThunderboltRender5 = nullptr;
	BBox = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}
