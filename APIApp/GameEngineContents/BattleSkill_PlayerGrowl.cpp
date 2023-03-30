#include "BattleSkill_PlayerGrowl.h"

#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

#include "ContentsEnum.h"

BattleSkill_PlayerGrowl::BattleSkill_PlayerGrowl()
{
}

BattleSkill_PlayerGrowl::~BattleSkill_PlayerGrowl()
{
}

void BattleSkill_PlayerGrowl::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EffectRender = GetEnemyMonster()->CreateRender("Growl1.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScaleToImage();

}
void BattleSkill_PlayerGrowl::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, 2.0f))
	{
		return;
	}
	
	EffectRender->SetPosition(PlayerMonster->GetPosition());

	// ForwardTimer += _DeltaTime;
	// float Ratio = (ForwardTimer / ForwardDuration);

	// float4 NowOffset = float4::LerpClamp(float4::Zero, MoveOffset, Ratio);
	// PlayerMonster->SetPosition(NowOffset);

	//float4 NowEffectScale = float4::LerpClamp(float4::Zero, EffectScale, Ratio);
	//EffectRender->SetScale(NowEffectScale);

	//if (Ratio <= 1.f)
	//	return;

	//CurState = MoveState::Backward;
}
void BattleSkill_PlayerGrowl::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	PlayerMonster->SetPosition(float4::Zero);

	PlayerMonster = nullptr;

	EffectRender->Death();

	EffectRender = nullptr;

	//CurState = MoveState::Forward;

	//ForwardTimer = 0.f;
	//BackwardTimer = 0.f;
}

