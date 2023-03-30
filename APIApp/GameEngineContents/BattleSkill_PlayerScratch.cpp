#include "BattleSkill_PlayerScratch.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterEnemy.h"
BattleSkill_PlayerScratch::BattleSkill_PlayerScratch() 
{
}

BattleSkill_PlayerScratch::~BattleSkill_PlayerScratch() 
{
}

void BattleSkill_PlayerScratch::EnterState()
{
	BattleSkill_PlayerBase::EnterState();


	EnemyRender = GetEnemyMonster()->GetRender();
	EffectRender = GetEnemyMonster()->CreateRender("Scratch.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({128, 128});
	EffectRender->SetAlpha({150});
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "Scratch.bmp", .Loop = false, .FrameIndex = {5, 0, 1, 2, 3, 4, 5}, .FrameTime = {0.5f, 0.04f, 0.04f, 0.04f, 0.07f, 0.1f, 0.1f} });
	EffectRender->ChangeAnimation("Defalut");
}

void BattleSkill_PlayerScratch::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	Timer += _DeltaTime;
}

void BattleSkill_PlayerScratch::ExitState()
{
	BattleSkill_PlayerBase::ExitState();
	Timer = 0;
}
