#include "BattleSkill_EnemyQuickAttack.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyQuickAttack::BattleSkill_EnemyQuickAttack() 
{
}

BattleSkill_EnemyQuickAttack::~BattleSkill_EnemyQuickAttack() 
{
}

void BattleSkill_EnemyQuickAttack::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	EffectRender = GetEnemyMonster()->CreateRender("Tackle.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScaleToImage();
	EffectRender->SetAlpha(200);
	EffectRender->SetPosition({-450, 200});
	EffectRender->Off();

	std::function SoundFunction = [](GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*) {
		GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl(BattleDefine::SfxName_Tackle);
		SfxCtrl.LoopCount(1);
		SfxCtrl.Volume(BattleDefine::WorldVolumn);
	};
	TimeEvent.AddEvent(0.3f, SoundFunction, false);
}

void BattleSkill_EnemyQuickAttack::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 1.5f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyQuickAttack::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyQuickAttack::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyQuickAttack::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyQuickAttack::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (0.4f <= ForwardTime)
	{
		EnemyMonster->Off();
		IsMove = false;
	}

	if (true == IsMove)
	{
		float MoveSpeed = 150.0f;
		float DownMoveSpeed = 50.0f;

		if (0.3f <= ForwardTime && 0.4f >= ForwardTime)
		{
			MoveSpeed = 3500.0f;
			DownMoveSpeed = 200.0f;
		}
		else if (0.1f <= ForwardTime && 0.3f >= ForwardTime)
		{
			MoveSpeed = 0.0f;
			DownMoveSpeed = 0.0f;
		}

		EnemyMonster->SetMove(float4::Left * MoveSpeed * _Deltatime + float4::Down * DownMoveSpeed * _Deltatime);
	}

	if (0.85f <= ForwardTime)
	{
		EffectRender->SetAlpha(0);
	}
	else if (0.8f <= ForwardTime)
	{
		EffectRender->SetAlpha(30);
	}
	else if (0.75f <= ForwardTime)
	{
		EffectRender->SetAlpha(60);
	}
	else if (0.7f <= ForwardTime)
	{
		EffectRender->SetAlpha(90);
	}
	else if (0.65f <= ForwardTime)
	{
		EffectRender->SetAlpha(120);
	}

	if (0.55f <= ForwardTime)
	{
		EffectRender->On();
	}

	if (0.4f <= ForwardTime)
	{
		EnemyMonster->SetAlpha(0);
	}
	else if (0.375f <= ForwardTime)
	{
		EnemyMonster->SetAlpha(60);
	}
	else if (0.35f <= ForwardTime)
	{
		EnemyMonster->SetAlpha(120);
	}
	else if (0.325f <= ForwardTime)
	{
		EnemyMonster->SetAlpha(180);
	}

	if (0.9f <= ForwardTime)
	{
		EnemyMonster->On();
		EnemyMonster->SetPosition(float4::Zero);
		EnemyMonster->SetAlpha(255);
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyQuickAttack::Update_BackWard(float _Deltatime)
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

void BattleSkill_EnemyQuickAttack::Update_Flashing(float _Deltatime)
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

void BattleSkill_EnemyQuickAttack::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	EnemyMonster->SetPosition(float4::Zero);

	EffectRender->Death();
	EffectRender = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	FlashingTime = 0.f;
	IsMove = true;
}
