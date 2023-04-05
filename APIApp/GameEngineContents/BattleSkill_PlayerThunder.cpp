#include "BattleSkill_PlayerThunder.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Thunder.h"
#include "SkillActor_ThunderBack.h"
#include "SkillActor_BlackBox.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerThunder::BattleSkill_PlayerThunder() 
{
}

BattleSkill_PlayerThunder::~BattleSkill_PlayerThunder() 
{
}

void BattleSkill_PlayerThunder::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	ThunderRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunder>();
	ThunderRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunder>();
	ThunderRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunder>();
	ThunderRender4 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunder>();
	ThunderRender5 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunder>();

	ThunderRender1->SetPos({ 630, 80 });
	ThunderRender2->SetPos({ 750, 110 });

	ThunderRender5->SetPos({ 700, 10 });
	ThunderRender5->ThunderSetting(ThunderSet::Thunder1);

	ThunderRender1->ThunderSetting(ThunderSet::Thunder1);
	ThunderRender2->ThunderSetting(ThunderSet::Thunder1);

	ThunderRender3->SetPos({ 700, 150 });
	ThunderRender3->ThunderSetting(ThunderSet::Thunder2);

	ThunderRender4->SetPos({ 760, 120 });
	ThunderRender4->ThunderSetting(ThunderSet::Thunder3);

	BackGround1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_ThunderBack>();
	BackGround2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_ThunderBack>();

	BBox = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_BlackBox>();

	BackGround2->SetPos({-870, 0});

	BackGround1->Off();
	BackGround2->Off();

	ThunderRender1->Off();
	ThunderRender2->Off();
	ThunderRender3->Off();
	ThunderRender4->Off();
	ThunderRender5->Off();

	BBox->Off();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("Thunder.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerThunder::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 4.7f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerThunder::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerThunder::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerThunder::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerThunder::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (3.3f <= ForwardTime)
	{
		ThunderRender4->On();
	}

	if (3.0f <= ForwardTime)
	{
		ThunderRender5->Off();
		ThunderRender3->On();
	}
	else if (2.0f <= ForwardTime)
	{
		ThunderRender5->On();
		ThunderRender5->SetMove(float4::Down * 120.0f * _Deltatime);
	}

	if (3.4f <= ForwardTime)
	{
		BBox->FadeOutStart();
	}
	else if (1.7f <= ForwardTime)
	{
		BBox->On();
		BBox->FadeInStart();
	}

	if (1.5f <= ForwardTime)
	{
		ThunderRender2->Off();
	}
	else if (1.2f <= ForwardTime)
	{
		ThunderRender2->On();
		ThunderRender2->SetMove(float4::Down * 150.0f * _Deltatime);
	}

	if (1.3f <= ForwardTime)
	{
		ThunderRender1->Off();
	}
	else if (1.0f <= ForwardTime)
	{
		ThunderRender1->On();
		ThunderRender1->SetMove(float4::Down * 150.0f * _Deltatime);
	}

	if (3.8f <= ForwardTime)
	{
		BackGround1->FadeOutStart();
		BackGround2->FadeOutStart();
	}
	else if (0.2f <= ForwardTime)
	{
		BackGround1->On();
		BackGround2->On();

		BackGround1->FadeInStart();
		BackGround2->FadeInStart();
	}

	if (4.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerThunder::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerThunder::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerThunder::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	ThunderRender1->Death();
	ThunderRender2->Death();
	ThunderRender3->Death();
	ThunderRender4->Death();
	ThunderRender5->Death();

	BackGround1->Death();
	BackGround2->Death();

	BBox->Death();
	
	ThunderRender1 = nullptr;
	ThunderRender2 = nullptr;
	ThunderRender3 = nullptr;
	ThunderRender4 = nullptr;
	ThunderRender5 = nullptr;

	BackGround1 = nullptr;
	BackGround2 = nullptr;

	BBox = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}
