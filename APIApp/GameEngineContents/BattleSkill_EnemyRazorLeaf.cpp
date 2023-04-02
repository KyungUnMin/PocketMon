#include "BattleSkill_EnemyRazorLeaf.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_RazorLeaf.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyRazorLeaf::BattleSkill_EnemyRazorLeaf() 
{
}

BattleSkill_EnemyRazorLeaf::~BattleSkill_EnemyRazorLeaf() 
{
}

void BattleSkill_EnemyRazorLeaf::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	LeafRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender4 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender5 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();

	RazorRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	RazorRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();

	LeafRender1->SetPos({ 830, 150 }); 
	LeafRender2->SetPos({ 770, 90 });
	LeafRender3->SetPos({ 700, 80 });
	LeafRender4->SetPos({ 620, 120 }); 
	LeafRender5->SetPos({ 570, 160 }); 

	RazorRender1->SetPos({ 670, 160 });
	RazorRender2->SetPos({ 600, 160 });

	StartPos1 = RazorRender1->GetPos();
	EndPos1 = StartPos1 + float4::Down * 300.0f + float4::Left * 550.0f;

	StartPos2 = RazorRender2->GetPos();
	EndPos2 = StartPos1 + float4::Down * 300.0f + float4::Left * 550.0f;

	LeafRender1->LeafSetting(LeafSet::Leafs_Stop);
	LeafRender2->LeafSetting(LeafSet::Leafs_Stop);
	LeafRender3->LeafSetting(LeafSet::Leafs_Stop);
	LeafRender4->LeafSetting(LeafSet::Leafs_Stop);
	LeafRender5->LeafSetting(LeafSet::Leafs_Stop);

	RazorRender1->LeafSetting(LeafSet::RazorLeaf);
	RazorRender2->LeafSetting(LeafSet::RazorLeaf);

	LeafRender1->Off();
	LeafRender2->Off();
	LeafRender3->Off();
	LeafRender4->Off();
	LeafRender5->Off();

	RazorRender1->Off();
	RazorRender2->Off();
}

void BattleSkill_EnemyRazorLeaf::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 5.6f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyRazorLeaf::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyRazorLeaf::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyRazorLeaf::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyRazorLeaf::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.4f <= ForwardTime)
	{
		LeafRender2->SetMove(float4::Down * LeafRender1->GetMoveSpeed() * _Deltatime);
		LeafRender5->SetMove(float4::Down * LeafRender1->GetMoveSpeed() * _Deltatime);
	}
	else if (0.91f <= ForwardTime)
	{
		LeafRender2->LeafSetting(LeafSet::Leafs_Move);
		LeafRender5->LeafSetting(LeafSet::Leafs_Move);
	}
	else if (0.9f <= ForwardTime)
	{
		LeafRender2->SetMove(float4::Down * 10.0f * _Deltatime);
		LeafRender5->SetMove(float4::Down * 10.0f * _Deltatime);
	}
	else if (0.6f <= ForwardTime)
	{
		LeafRender2->On();
		LeafRender5->On();

		LeafRender2->SetMove(float4::Up * 300.0f * _Deltatime);
		LeafRender5->SetMove(float4::Up * 300.0f * _Deltatime);
	}

	if (1.2f <= ForwardTime)
	{
		LeafRender1->SetMove(float4::Down * LeafRender1->GetMoveSpeed() * _Deltatime);
		LeafRender3->SetMove(float4::Down * LeafRender1->GetMoveSpeed() * _Deltatime);
		LeafRender4->SetMove(float4::Down * LeafRender1->GetMoveSpeed() * _Deltatime);
	}
	else if (0.61f <= ForwardTime)
	{
		LeafRender1->LeafSetting(LeafSet::Leafs_Move);
		LeafRender3->LeafSetting(LeafSet::Leafs_Move);
		LeafRender4->LeafSetting(LeafSet::Leafs_Move);
	}
	else if (0.6f <= ForwardTime)
	{
		LeafRender1->SetMove(float4::Down * 10.0f * _Deltatime);
		LeafRender3->SetMove(float4::Down * 10.0f * _Deltatime);
		LeafRender4->SetMove(float4::Down * 10.0f * _Deltatime);
	}
	else if (0.3f <= ForwardTime)
	{
		LeafRender1->On();
		LeafRender3->On();
		LeafRender4->On();

		LeafRender1->SetMove(float4::Up * 300.0f * _Deltatime);
		LeafRender3->SetMove(float4::Up * 300.0f * _Deltatime);
		LeafRender4->SetMove(float4::Up * 300.0f * _Deltatime);
	}

	if (true == LeafRender1->IsRazorShoot())
	{
		IsShoot1 = true;
	}

	if (true == LeafRender2->IsRazorShoot())
	{
		IsShoot2 = true;
	}

	if (true == IsShoot1)
	{
		ShootTime1 += _Deltatime * 2.0f;

		float4 Pos = float4::LerpClamp(StartPos1, EndPos1, ShootTime1);
		RazorRender1->SetPos(Pos);

		if (EndPos1.x == RazorRender1->GetPos().x)
		{
			RazorRender1->Off();
			float sfsf = ForwardTime;
		}
		else
		{
			RazorRender1->On();
		}
	}

	if (true == IsShoot2)
	{
		ShootTime2 += _Deltatime * 2.0f;

		float4 Pos = float4::LerpClamp(StartPos2, EndPos2, ShootTime2);
		RazorRender2->SetPos(Pos);

		if (EndPos2.x == RazorRender2->GetPos().x)
		{
			RazorRender2->Off();
		}
		else
		{
			RazorRender2->On();
		}
	}

	if (5.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyRazorLeaf::Update_BackWard(float _Deltatime)
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

void BattleSkill_EnemyRazorLeaf::Update_Flashing(float _Deltatime)
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

void BattleSkill_EnemyRazorLeaf::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	EnemyMonster->SetPosition(float4::Zero);

	StartPos1 = float4::Zero;
	StartPos2 = float4::Zero;
	EndPos1 = float4::Zero;
	EndPos2 = float4::Zero;

	LeafRender1->Death();
	LeafRender2->Death();
	LeafRender3->Death();
	LeafRender4->Death();
	LeafRender5->Death();

	RazorRender1->Death();
	RazorRender2->Death();

	LeafRender1 = nullptr;
	LeafRender2 = nullptr;
	LeafRender3 = nullptr;
	LeafRender4 = nullptr;
	LeafRender5 = nullptr;

	RazorRender1 = nullptr;
	RazorRender2 = nullptr;

	CurState = MoveState::Forward;

	IsShoot1 = false;
	IsShoot2 = false;
	ShootTime1 = 0.0f;
	ShootTime2 = 0.0f;
	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}