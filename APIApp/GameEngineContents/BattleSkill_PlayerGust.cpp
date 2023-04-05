#include "BattleSkill_PlayerGust.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_Gust.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_PlayerGust::BattleSkill_PlayerGust() 
{
}

BattleSkill_PlayerGust::~BattleSkill_PlayerGust() 
{
}

void BattleSkill_PlayerGust::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	GustRender = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_Gust>();
	GustRender->SetPos({ 400, 300 });
	GustRender->SetAlphaValue(0);
	GustRender->Off();

	NewPos = GustRender->GetPos();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("Gust.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerGust::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		EnemyMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_PlayerGust::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerGust::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_PlayerGust::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_PlayerGust::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;
	
	GustRender->On();

	if (1.1f <= ForwardTime)
	{
		IsRotate = false;
		IsShoot = true;
	}

	if (true == IsRotate)
	{
		RotationTime += _Deltatime;

		if (0.001f <= RotationTime)
		{
			Angle += 2.5f;
			RotationTime = 0.0f;
		}

		float4 Dir = float4::AngleToDirection2DToDeg(Angle);
		GustRender->SetPos(NewPos + Dir * 20.0f);

		if (0.5f <= ForwardTime)
		{
			GustRender->SetAlphaValue(255);
		}
		else if (0.4f <= ForwardTime)
		{
			GustRender->SetAlphaValue(210);
		}
		else if (0.3f <= ForwardTime)
		{
			GustRender->SetAlphaValue(150);
		}
		else if (0.2f <= ForwardTime)
		{
			GustRender->SetAlphaValue(90);
		}
		else if (0.1f <= ForwardTime)
		{
			GustRender->SetAlphaValue(30);
		}
	}

	if (true == IsShoot)
	{
		if (1 == ShootSet)
		{
			ShootSet = 0;
			StartPos = GustRender->GetPos();
			EndPos = StartPos + float4{ 500, -350 };
		}

		GustTime += _Deltatime * 4.0f;

		float4 Pos = float4::LerpClamp(StartPos, EndPos, GustTime);
		GustRender->SetPos(Pos);

		if (EndPos.x <= GustRender->GetPos().x)
		{
			GustRender->Off();
		}
	}

	if (1.4f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_PlayerGust::Update_BackWard(float _Deltatime)
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

void BattleSkill_PlayerGust::Update_Flashing(float _Deltatime)
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

void BattleSkill_PlayerGust::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	GustRender->Death();
	GustRender = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	RotationTime = 0.f;
	GustTime = 0.f;
	Angle = 0.0f;

	IsRotate = true;
	IsShoot = false;

	ShootSet = 1;

	StartPos = float4::Zero;
	EndPos = float4::Zero;
	NewPos = float4::Zero;
}
