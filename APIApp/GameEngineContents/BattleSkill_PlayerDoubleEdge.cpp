#include "BattleSkill_PlayerDoubleEdge.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
// #include <스킬 액터>

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerDoubleEdge::BattleSkill_PlayerDoubleEdge() 
{
}

BattleSkill_PlayerDoubleEdge::~BattleSkill_PlayerDoubleEdge() 
{
}

void BattleSkill_PlayerDoubleEdge::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	EffectRender1 = GetEnemyMonster()->CreateRender("Tackle.bmp", BattleRenderOrder::SkillEffect);
	EffectRender2 = GetEnemyMonster()->CreateRender("Tackle.bmp", BattleRenderOrder::SkillEffect);
	EffectRender3 = GetEnemyMonster()->CreateRender("Tackle.bmp", BattleRenderOrder::SkillEffect);

	EffectRender1->SetScaleToImage();
	EffectRender2->SetScaleToImage();
	EffectRender3->SetScaleToImage();

	EffectRender1->SetAlpha(200);
	EffectRender2->SetAlpha(200);
	EffectRender3->SetAlpha(200);

	EffectRender1->SetPosition(float4::Left * 60 + float4::Down * 30);
	EffectRender2->SetPosition(float4::Left * 0 + float4::Up * 60);
	EffectRender3->SetPosition(float4::Right * 50 + float4::Down * 10);

	float4 sclae = EffectRender1->GetImage()->GetImageScale();
	sclae.x -= 40.0f;
	sclae.y -= 40.0f;

	EffectRender1->SetScale(sclae);
	EffectRender2->SetScale(sclae);
	EffectRender3->SetScale(sclae);

	EffectRender1->Off();
	EffectRender2->Off();
	EffectRender3->Off();

	StartPos1 = PlayerMonster->GetPosition();

	EndPos1 = StartPos1 + float4::Right * 60;

	StartPos2 = EndPos1;

	EndPos2 = StartPos2 + float4::Left * 60;
}

void BattleSkill_PlayerDoubleEdge::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 1.2f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerDoubleEdge::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerDoubleEdge::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerDoubleEdge::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerDoubleEdge::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	Pos1Time += _Deltatime * 6.0f;

	float4 Pos1 = float4::LerpClamp(StartPos1, EndPos1, Pos1Time);
	PlayerMonster->SetPosition(Pos1);

	if (EndPos1.x == PlayerMonster->GetPosition().x)
	{
		Pos2Time += _Deltatime * 6.0f;

		float4 Pos2 = float4::LerpClamp(StartPos2, EndPos2, Pos2Time);
		PlayerMonster->SetPosition(Pos2);
	}

	if (0.35f <= ForwardTime)
	{
		EffectRender3->Off();
	}
	else if (0.2f <= ForwardTime)
	{
		EffectRender3->On();
	}

	if (0.3f <= ForwardTime)
	{
		EffectRender2->Off();
	}
	else if (0.15f <= ForwardTime)
	{
		EffectRender2->On();
	}

	if (0.25f <= ForwardTime)
	{
		EffectRender1->Off();
	}
	else if (0.1f <= ForwardTime)
	{
		EffectRender1->On();
	}

	if (0.6f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerDoubleEdge::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerDoubleEdge::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerDoubleEdge::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	EffectRender1->Death();
	EffectRender2->Death();
	EffectRender3->Death();

	EffectRender1 = nullptr;
	EffectRender2 = nullptr;
	EffectRender3 = nullptr;

	CurState = MoveState::Forward;

	Pos1Time = 0.0f;
	Pos2Time = 0.0f;
	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
}