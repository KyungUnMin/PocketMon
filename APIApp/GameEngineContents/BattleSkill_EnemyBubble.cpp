#include "BattleSkill_EnemyBubble.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Bubble.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyBubble::BattleSkill_EnemyBubble() 
{
}

BattleSkill_EnemyBubble::~BattleSkill_EnemyBubble() 
{
}

void BattleSkill_EnemyBubble::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	BubbleRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bubble>();
	BubbleRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bubble>();
	BubbleRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bubble>();

	BubbleRender1->SetPos({ 330, 330 });
	BubbleRender2->SetPos({ 330, 340 });
	BubbleRender3->SetPos({ 330, 350 });

	StartPos1 = BubbleRender1->GetPos();
	EndPos1 = StartPos1 + float4::Up * 140.0f + float4::Right * 320.0f;

	StartPos2 = BubbleRender2->GetPos();
	EndPos2 = StartPos2 + float4::Up * 120.0f + float4::Right * 350.0f;

	StartPos3 = BubbleRender3->GetPos();
	EndPos3 = StartPos3 + float4::Up * 110.0f + float4::Right * 370.0f;

	BubbleRender1->Off();
	BubbleRender2->Off();
	BubbleRender3->Off();
}

void BattleSkill_EnemyBubble::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 2.4f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyBubble::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyBubble::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyBubble::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyBubble::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.1f <= ForwardTime)
	{
		IsShoot1 = true;
	}

	if (0.25f <= ForwardTime)
	{
		IsShoot2 = true;
	}

	if (0.4f <= ForwardTime)
	{
		IsShoot3 = true;
	}

	if (true == IsShoot1)
	{
		ShootTime1 += _Deltatime * 2.0f;

		float4 Pos1 = float4::LerpClamp(StartPos1, EndPos1, ShootTime1);
		BubbleRender1->SetPos(Pos1);

		if (EndPos1.x == BubbleRender1->GetPos().x && 1 == SetCount1)
		{
			SetCount1 = 0;
			IsShoot1_A = true;
			StartPos1_A = BubbleRender1->GetPos();
			EndPos1_A = StartPos1_A + float4::Up * 60.0f + float4::Right * 40.0f;
		}
		else
		{
			BubbleRender1->On();
		}

		if (true == IsShoot1_A)
		{
			ShootTime1_A += _Deltatime * 1.2f;

			float4 Pos2 = float4::LerpClamp(StartPos1_A, EndPos1_A, ShootTime1_A);
			BubbleRender1->SetPos(Pos2);

			if (EndPos1_A.x == BubbleRender1->GetPos().x)
			{
				BubbleRender1->BubbleSetting(BubbleSet::Bubble_Pop);
			}
		}
	}

	if (true == IsShoot2)
	{
		ShootTime2 += _Deltatime * 2.0f;

		float4 Pos3 = float4::LerpClamp(StartPos2, EndPos2, ShootTime2);
		BubbleRender2->SetPos(Pos3);

		if (EndPos2.x == BubbleRender2->GetPos().x && 1 == SetCount2)
		{
			SetCount2 = 0;
			IsShoot2_A = true;
			StartPos2_A = BubbleRender2->GetPos();
			EndPos2_A = StartPos2_A + float4::Up * 30.0f + float4::Right * 40.0f;
		}
		else
		{
			BubbleRender2->On();
		}

		if (true == IsShoot2_A)
		{
			ShootTime2_A += _Deltatime * 1.4f;

			float4 Pos4 = float4::LerpClamp(StartPos2_A, EndPos2_A, ShootTime2_A);
			BubbleRender2->SetPos(Pos4);

			if (EndPos2_A.x == BubbleRender2->GetPos().x)
			{
				BubbleRender2->BubbleSetting(BubbleSet::Bubble_Pop);
			}
		}
	}

	if (true == IsShoot3)
	{
		ShootTime3 += _Deltatime * 2.0f;

		float4 Pos5 = float4::LerpClamp(StartPos3, EndPos3, ShootTime3);
		BubbleRender3->SetPos(Pos5);

		if (EndPos3.x == BubbleRender3->GetPos().x && 1 == SetCount3)
		{
			SetCount3 = 0;
			IsShoot3_A = true;
			StartPos3_A = BubbleRender3->GetPos();
			EndPos3_A = StartPos3_A + float4::Up * 60.0f + float4::Right * 60.0f;
		}
		else
		{
			BubbleRender3->On();
		}

		if (true == IsShoot3_A)
		{
			ShootTime3_A += _Deltatime * 1.5f;

			float4 Pos6 = float4::LerpClamp(StartPos3_A, EndPos3_A, ShootTime3_A);
			BubbleRender3->SetPos(Pos6);

			if (EndPos3_A.x == BubbleRender3->GetPos().x)
			{
				BubbleRender3->BubbleSetting(BubbleSet::Bubble_Pop);
				float fdfff = ForwardTime;

				int a = 0;
			}
		}
	}

	if (1.8f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyBubble::Update_BackWard(float _Deltatime)
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

void BattleSkill_EnemyBubble::Update_Flashing(float _Deltatime)
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

void BattleSkill_EnemyBubble::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

	BubbleRender1->Death();
	BubbleRender2->Death();
	BubbleRender3->Death();

	BubbleRender1 = nullptr;
	BubbleRender2 = nullptr;
	BubbleRender3 = nullptr;

	CurState = MoveState::Forward;

	SetCount1 = 1;
	SetCount2 = 1;
	SetCount3 = 1;

	IsShoot1 = false;
	IsShoot2 = false;
	IsShoot3 = false;

	IsShoot1_A = false;
	IsShoot2_A = false;
	IsShoot3_A = false;

	ShootTime1 = 0.0f;
	ShootTime2 = 0.0f;
	ShootTime3 = 0.0f;

	ShootTime1_A = 0.0f;
	ShootTime2_A = 0.0f;
	ShootTime3_A = 0.0f;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}
