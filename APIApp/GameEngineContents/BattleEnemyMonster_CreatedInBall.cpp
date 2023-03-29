#include "BattleEnemyMonster_CreatedInBall.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyMonsterFSM.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattleLevel.h"


BattleEnemyMonster_CreatedInBall::BattleEnemyMonster_CreatedInBall()
{

}

BattleEnemyMonster_CreatedInBall::~BattleEnemyMonster_CreatedInBall()
{

}

void BattleEnemyMonster_CreatedInBall::EnterState()
{
	CreateRenders();
}

void BattleEnemyMonster_CreatedInBall::CreateRenders()
{
	BattleMonsterEnemy* Monster = BattleEnemy::EnemyPtr->GetMonster();
	MonsterRender = Monster->GetRender();
	OriginScale = MonsterRender->GetScale();
	MonsterRender->SetScale(float4::Zero);

	std::string MonsterName = Monster->GetName();
	std::string EffectImagePath = "Battle" + MonsterName + "FrontLight.bmp";

	EffectRender = Monster->CreateRender(EffectImagePath,BattleRenderOrder::CreateEffect);
	EffectRender->SetAlpha(150);
	EffectRender->SetScale(float4::Zero);

	const std::string_view AniName = "Open";
	BallRender = Monster->CreateRender(BattleRenderOrder::MonsterBall);
	BallRender->SetScale(BallScale);
	BallRender->CreateAnimation
	({
		.AnimationName = AniName ,
		.ImageName = "BattleMonsterBallOpen.bmp",
		.Start = 0,
		.End = 1,
		.InterTime = 0.1f,
		.Loop = false
	});


	BallRender->ChangeAnimation(AniName);

	BattleLevel::BattleLevelPtr->CreateActor<Battle_MonsterAppearEffect>(UpdateOrder::Battle_Actors);
}




void BattleEnemyMonster_CreatedInBall::Update(float _DeltaTime)
{
	if (false == BallRender->IsAnimationEnd())
		return;

	Timer += _DeltaTime;
	float Ratio = (Timer / Duration);
	float4 NowScale = float4::LerpClamp(float4::Zero, OriginScale, Ratio);

	MonsterRender->SetScale(NowScale);
	EffectRender->SetScale(NowScale);

	if (1.f < Ratio)
	{
		GetFSM()->ChangeState(BattleEnemyMonster_StateType::Idle);
		return;
	}
}

void BattleEnemyMonster_CreatedInBall::ExitState()
{
	MonsterRender = nullptr;
	EffectRender->Death();
	EffectRender = nullptr;
	BallRender->Death();
	BallRender = nullptr;
}


