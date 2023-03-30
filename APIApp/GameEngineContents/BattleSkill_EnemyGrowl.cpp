#include "BattleSkill_EnemyGrowl.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "BattleLevel.h"
#include "SkillActor_Growl.h"
#include "ContentsEnum.h"

BattleSkill_EnemyGrowl::BattleSkill_EnemyGrowl() 
{
}

BattleSkill_EnemyGrowl::~BattleSkill_EnemyGrowl() 
{
}

void BattleSkill_EnemyGrowl::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	EnemyMonster = GetEnemyMonster()->GetRender();
	PlayerMonster = GetPlayerMonster()->GetRender();

	GrowlRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
	GrowlRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();
	GrowlRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Growl>();

	GrowlRender3->SetPos({ 510, 200 });
	GrowlRender2->SetPos({ 510, 400 });
	GrowlRender1->SetPos({ 510, 300 });

	Growl3StartPos = GrowlRender3->GetPos();
	Growl3EndPos = Growl3StartPos + float4::Up * 50 + float4::Left * 50;

	Growl2StartPos = GrowlRender2->GetPos();
	Growl2EndPos = Growl2StartPos + float4::Left * 50;

	Growl1StartPos = GrowlRender1->GetPos();
	Growl1EndPos = Growl1StartPos + float4::Down * 50 + float4::Left * 50;

	GrowlRender3->GrowlSetting(3);
	GrowlRender2->GrowlSetting(2);
	GrowlRender1->GrowlSetting(1);

	GrowlRender3->Off();
	GrowlRender2->Off();
	GrowlRender1->Off();
}

void BattleSkill_EnemyGrowl::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyGrowl::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyGrowl::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyGrowl::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyGrowl::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (true == ReStart)
	{
		GrowlTime += _Deltatime * 5.0f;

		float Ratio = (ForwardTime / ForwardDuration);

		GrowlRender1->On();
		GrowlRender2->On();
		GrowlRender3->On();

		float4 EffectPos1 = float4::LerpClamp(Growl1StartPos, Growl1EndPos, GrowlTime);
		GrowlRender1->SetPos(EffectPos1);

		float4 EffectPos2 = float4::LerpClamp(Growl2StartPos, Growl2EndPos, GrowlTime);
		GrowlRender2->SetPos(EffectPos2);

		float4 EffectPos3 = float4::LerpClamp(Growl3StartPos, Growl3EndPos, GrowlTime);
		GrowlRender3->SetPos(EffectPos3);

		if (Growl1EndPos.x == GrowlRender1->GetPos().x)
		{
			GrowlRender1->SetPos(Growl1StartPos);
			GrowlRender1->Off();
		}
		if (Growl2EndPos.x == GrowlRender2->GetPos().x)
		{
			GrowlRender2->SetPos(Growl2StartPos);
			GrowlRender2->Off();
		}
		if (Growl3EndPos.x == GrowlRender3->GetPos().x)
		{
			GrowlRender3->SetPos(Growl3StartPos);
			GrowlRender3->Off();
			ReStart = false;
		}
	}

	if (0.5f <= ForwardTime && 1 == ReCount)
	{
		ReCount = 0;
		ReStart = true;
		GrowlTime = 0.0f;
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyGrowl::Update_BackWard(float _Deltatime)
{
	GrowlRender3->Off();
	GrowlRender2->Off();
	GrowlRender1->Off();

	BackwardTime += _Deltatime;

	if (0.4f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Zero);
	}
	else if (0.2f <= BackwardTime)
	{
		PlayerMonster->SetPosition(float4::Left * 10);
	}
}

void BattleSkill_EnemyGrowl::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

	PlayerMonster = nullptr;

	GrowlRender1->Death();
	GrowlRender2->Death();
	GrowlRender3->Death();

	GrowlRender1 = nullptr;
	GrowlRender2 = nullptr;
	GrowlRender3 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
}

