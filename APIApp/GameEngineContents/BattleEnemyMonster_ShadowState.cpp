#include "BattleEnemyMonster_ShadowState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemyMonsterFSM.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "ContentsEnum.h"
#include "BattleTrainerBase.h"


BattleEnemyMonster_ShadowState::BattleEnemyMonster_ShadowState()
{

}

BattleEnemyMonster_ShadowState::~BattleEnemyMonster_ShadowState()
{

}

void BattleEnemyMonster_ShadowState::EnterState()
{
	Enemy = BattleEnemy::EnemyPtr;
	Monster = Enemy->GetMonster();
	
	std::string Name = Monster->GetName();
	std::string ImagePath = "Battle" + Name + "Shadow.bmp";

	ShadowRender = Monster->CreateRender(ImagePath, BattleRenderOrder::CreateEffect);
	ShadowRender->SetScaleToImage();
	ShadowRender->SetAlpha(StartAlpha.ix());

	MoveTime = BattleTrainerBase::MoveDuration;
}

void BattleEnemyMonster_ShadowState::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (LiveTime < MoveTime)
	{
		Monster->SetPos(Enemy->GetPos() + MoveOffset);
		return;
	}

	float Time = (LiveTime - MoveTime);
	float Ratio = (Time / ShadowDuration);

	float4 NowAlpha = float4::LerpClamp(StartAlpha, float4::Zero, Ratio);
	ShadowRender->SetAlpha(NowAlpha.ix());

	if (Ratio <= 1.f)
		return;

	GetFSM()->ChangeState(BattleEnemyMonster_StateType::Idle);
}

void BattleEnemyMonster_ShadowState::ExitState()
{
	ShadowRender->Death();
}
