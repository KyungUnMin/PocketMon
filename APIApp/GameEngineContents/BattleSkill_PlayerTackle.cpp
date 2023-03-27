#include "BattleSkill_PlayerTackle.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"
#include "ContentsEnum.h"


BattleSkill_PlayerTackle::BattleSkill_PlayerTackle()
{

}

BattleSkill_PlayerTackle::~BattleSkill_PlayerTackle()
{

}

//#include "PokeDataBase.h"
//#include "PokeBattleSystem.h"

/*int HP = GetEnemyMonster()->GetDB()->GetMonsterMaxHP_int();
int CurHP = GetEnemyMonster()->GetDB()->GetMonsterCurrentHP();

PokeDataBase* DB = GetPlayerMonster()->GetDB();
PokeBattleSystem::Battle(DB, 1, GetEnemyMonster()->GetDB());

HP = GetEnemyMonster()->GetDB()->GetMonsterMaxHP_int();
CurHP = GetEnemyMonster()->GetDB()->GetMonsterCurrentHP();*/



void BattleSkill_PlayerTackle::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	PlayerMonster = GetPlayerMonster()->GetRender();
	EffectRender = GetEnemyMonster()->CreateRender("Tackle.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScaleToImage();
	EffectScale = EffectRender->GetScale();
	EffectRender->SetAlpha(150);
}

void BattleSkill_PlayerTackle::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, ForwardDuration + BackwardDuration))
		return;

	switch (CurState)
	{
	case BattleSkill_PlayerTackle::MoveState::Forward:
		Update_Forward(_DeltaTime);
		break;
	case BattleSkill_PlayerTackle::MoveState::Backward:
		Update_BackWard(_DeltaTime);
		break;
	}
}


void BattleSkill_PlayerTackle::Update_Forward(float _DeltaTime)
{
	ForwardTimer += _DeltaTime;
	float Ratio = (ForwardTimer / ForwardDuration);

	float4 NowOffset = float4::LerpClamp(float4::Zero, MoveOffset, Ratio);
	PlayerMonster->SetPosition(NowOffset);

	float4 NowEffectScale = float4::LerpClamp(float4::Zero, EffectScale, Ratio);
	EffectRender->SetScale(NowEffectScale);

	if (Ratio <= 1.f)
		return;

	CurState = MoveState::Backward;
}

void BattleSkill_PlayerTackle::Update_BackWard(float _DeltaTime)
{
	BackwardTimer += _DeltaTime;
	float Ratio = (BackwardTimer / BackwardDuration);

	float4 NowOffset = float4::LerpClamp(MoveOffset, float4::Zero, Ratio);
	PlayerMonster->SetPosition(NowOffset);

	float4 NowEffectScale = float4::LerpClamp(EffectScale, float4::Zero, Ratio);
	EffectRender->SetScale(NowEffectScale);
}


void BattleSkill_PlayerTackle::ExitState()
{
	BattleSkill_PlayerBase::ExitState();
	PlayerMonster->SetPosition(float4::Zero);
	PlayerMonster = nullptr;

	EffectRender->Death();
	EffectRender = nullptr;

	CurState = MoveState::Forward;

	ForwardTimer = 0.f;
	BackwardTimer = 0.f;
}

