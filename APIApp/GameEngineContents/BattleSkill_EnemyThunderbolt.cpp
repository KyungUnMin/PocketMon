#include "BattleSkill_EnemyThunderbolt.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Thunderbolt.h"
#include "SkillActor_BlackBox.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyThunderbolt::BattleSkill_EnemyThunderbolt() 
{
}

BattleSkill_EnemyThunderbolt::~BattleSkill_EnemyThunderbolt() 
{
}

void BattleSkill_EnemyThunderbolt::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	ThunderboltRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender4 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();
	ThunderboltRender5 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Thunderbolt>();

	BBox = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_BlackBox>();

	ThunderboltRender1->SetPos({ 160, 290 });
	ThunderboltRender2->SetPos({ 240, 250 });
	ThunderboltRender3->SetPos({ 270, 330 });
	ThunderboltRender4->SetPos({ 340, 310 });

	ThunderboltRender5->SetPos({ 270, 360 });

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

void BattleSkill_EnemyThunderbolt::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 2.3f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyThunderbolt::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyThunderbolt::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyThunderbolt::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyThunderbolt::Update_Forward(float _Deltatime)
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

void BattleSkill_EnemyThunderbolt::Update_BackWard(float _Deltatime)
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

void BattleSkill_EnemyThunderbolt::Update_Flashing(float _Deltatime)
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

void BattleSkill_EnemyThunderbolt::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	
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
