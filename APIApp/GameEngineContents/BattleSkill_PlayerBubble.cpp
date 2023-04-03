#include "BattleSkill_PlayerBubble.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Bubble.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerBubble::BattleSkill_PlayerBubble()
{
}

BattleSkill_PlayerBubble::~BattleSkill_PlayerBubble()
{
}

void BattleSkill_PlayerBubble::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	BubbleRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bubble>();
	BubbleRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bubble>();
	BubbleRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Bubble>();

	BubbleRender1->SetPos({ 320, 320 });
	BubbleRender2->SetPos({ 320, 320 });
	BubbleRender3->SetPos({ 320, 320 });

	StartPos1 = BubbleRender1->GetPos();
	EndPos1 = StartPos1 + float4::Up * 250.0f + float4::Right * 600.0f;

	StartPos2 = BubbleRender2->GetPos();
	EndPos2 = StartPos1 + float4::Up * 250.0f + float4::Right * 600.0f;

	StartPos3 = BubbleRender2->GetPos();
	EndPos3 = StartPos1 + float4::Up * 250.0f + float4::Right * 600.0f;

	BubbleRender1->Off();
	BubbleRender2->Off();
	BubbleRender3->Off();
}

void BattleSkill_PlayerBubble::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.6f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerBubble::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerBubble::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerBubble::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerBubble::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.1f <= ForwardTime)
	{
		IsShoot1 = true;
	}

	if (true == IsShoot1)
	{
		ShootTime1 += _Deltatime * 2.0f;

		float4 Pos = float4::LerpClamp(StartPos1, EndPos1, ShootTime1);
		BubbleRender1->SetPos(Pos);

		if (EndPos1.x == BubbleRender1->GetPos().x)
		{
			BubbleRender1->Off();
			float sfsf = ForwardTime;
		}
		else
		{
			BubbleRender1->On();
		}
	}

	if (1.0f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerBubble::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerBubble::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerBubble::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	BubbleRender1->Death();
	BubbleRender2->Death();
	BubbleRender3->Death();

	BubbleRender1 = nullptr;
	BubbleRender2 = nullptr;
	BubbleRender3 = nullptr;

	CurState = MoveState::Forward;

	ShootTime1 = 0.0f;
	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}
