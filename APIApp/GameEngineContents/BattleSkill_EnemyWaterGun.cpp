#include "BattleSkill_EnemyWaterGun.h"

#include <GameEngineCore/GameEngineRender.h>

#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "SkillActor_WaterGun.h"

#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleSkill_EnemyWaterGun::BattleSkill_EnemyWaterGun() 
{
}

BattleSkill_EnemyWaterGun::~BattleSkill_EnemyWaterGun() 
{
}

void BattleSkill_EnemyWaterGun::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EnemyMonster = GetEnemyMonster()->GetRender();

	WaterGunRender = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_WaterGun>();

	WaterRender1 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_WaterGun>();
	WaterRender2 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_WaterGun>();
	WaterRender3 = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_WaterGun>();

	WaterGunRender->SetPos({ 620, 180 });
	WaterGunRender->WaterGunSetting(WaterGunSet::WaterGun_Shoot_L);

	WaterRender1->SetPos({ 180, 340 });
	WaterRender2->SetPos({ 240, 310 });
	WaterRender3->SetPos({ 290, 330 });

	WaterRender1->WaterGunSetting(WaterGunSet::WaterGun_Stop);
	WaterRender2->WaterGunSetting(WaterGunSet::WaterGun_Stop);
	WaterRender3->WaterGunSetting(WaterGunSet::WaterGun_Stop);

	WaterGunRender->Off();

	WaterRender1->Off();
	WaterRender2->Off();
	WaterRender3->Off();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("WaterGun.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_EnemyWaterGun::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		PlayerMonster->On();
		return;
	}

	switch (CurState)
	{
	case BattleSkill_EnemyWaterGun::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_EnemyWaterGun::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	case BattleSkill_EnemyWaterGun::MoveState::Flashing:
		Update_Flashing(_DeltaTime);
		break;
	}
}

void BattleSkill_EnemyWaterGun::Update_Forward(float _Deltatime)
{
	ForwardTime += _Deltatime;

	if (1.1f <= ForwardTime)
	{
		WaterRender3->Off();
	}
	else if (0.61f <= ForwardTime)
	{
		WaterRender3->SetMove(float4::Down * 60.0f * _Deltatime);
	}
	else if (0.6f <= ForwardTime)
	{
		WaterRender3->On();
	}

	if (1.05f <= ForwardTime)
	{
		WaterRender2->Off();
	}
	else if (0.56f <= ForwardTime)
	{
		WaterRender2->SetMove(float4::Down * 60.0f * _Deltatime);
	}
	else if (0.55f <= ForwardTime)
	{
		WaterRender2->On();
	}

	if (1.0f <= ForwardTime)
	{
		WaterRender1->Off();
	}
	else if (0.51f <= ForwardTime)
	{
		WaterRender1->SetMove(float4::Down * 60.0f * _Deltatime);
	}
	else if (0.5f <= ForwardTime)
	{
		WaterRender1->On();
	}

	if (0.11f <= ForwardTime)
	{
		WaterGunRender->SetMove(float4::Left * 10.0f * _Deltatime);
	}
	else if (0.1f <= ForwardTime)
	{
		WaterGunRender->On();
	}

	if (1.4f <= ForwardTime)
	{
		CurState = MoveState::Backward;
	}
}

void BattleSkill_EnemyWaterGun::Update_BackWard(float _Deltatime)
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

void BattleSkill_EnemyWaterGun::Update_Flashing(float _Deltatime)
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

void BattleSkill_EnemyWaterGun::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

	WaterGunRender->Death();

	WaterRender1->Death();
	WaterRender2->Death();
	WaterRender3->Death();

	WaterGunRender = nullptr;

	WaterRender1 = nullptr;
	WaterRender2 = nullptr;
	WaterRender3 = nullptr;

	CurState = MoveState::Forward;

	ForwardTime = 0.f;
	BackwardTime = 0.f;
	float FlashingTime = 0.f;
}
