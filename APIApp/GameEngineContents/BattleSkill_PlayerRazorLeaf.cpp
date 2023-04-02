#include "BattleSkill_PlayerRazorLeaf.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_RazorLeaf.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerRazorLeaf::BattleSkill_PlayerRazorLeaf()
{
}

BattleSkill_PlayerRazorLeaf::~BattleSkill_PlayerRazorLeaf()
{
}

void BattleSkill_PlayerRazorLeaf::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	LeafRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender4 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	LeafRender5 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();

	RazorRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();
	RazorRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_RazorLeaf>();

	LeafRender1->SetPos({ 370, 360 });
	LeafRender2->SetPos({ 310, 300 });
	LeafRender3->SetPos({ 240, 290 });
	LeafRender4->SetPos({ 160, 330 });
	LeafRender5->SetPos({ 110, 370 });

	RazorRender1->SetPos({ 320, 320 });
	RazorRender2->SetPos({ 250, 320 });

	StartPos1 = RazorRender1->GetPos();
	EndPos1 = StartPos1 + float4::Up * 250.0f + float4::Right * 600.0f;

	StartPos2 = RazorRender2->GetPos();
	EndPos2 = StartPos1 + float4::Up * 250.0f + float4::Right * 600.0f;

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

void BattleSkill_PlayerRazorLeaf::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 5.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerRazorLeaf::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerRazorLeaf::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerRazorLeaf::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerRazorLeaf::Update_Forward(float _Deltatime)
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

void BattleSkill_PlayerRazorLeaf::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerRazorLeaf::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerRazorLeaf::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

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
