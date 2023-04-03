#include "BattleSkill_EnemyIronDefense.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
#include "SkillActor_BlackBox.h"
#include "BattleLevel.h"
BattleSkill_EnemyIronDefense::BattleSkill_EnemyIronDefense()
{
}

BattleSkill_EnemyIronDefense::~BattleSkill_EnemyIronDefense()
{
}

void BattleSkill_EnemyIronDefense::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	EffectRender = GetEnemyMonster()->CreateRender("DefenseCurl.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 225 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "DefenseCurl.bmp", .Start = 0, .End = 7, .Loop = false, .FrameTime = {0.15f, 0.15f, 0.08f, 0.1f, 0.06f, 0.04f, 0.02f, 1.0f} });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
	Timer = 0;
	BBox = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_BlackBox>();
}

void BattleSkill_EnemyIronDefense::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	Timer += _DeltaTime;
	if (1.2f < Timer)
	{
		BBox->FadeOutStart();
	}
	else if (0 < Timer)
	{
		BBox->FadeInStart();
	}
}

void BattleSkill_EnemyIronDefense::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	BBox->Death();
	BBox = nullptr;
}
