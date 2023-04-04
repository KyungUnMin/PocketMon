#include "BattleEnemyMonster_CreatedInBall.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyMonsterFSM.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattleLevel.h"
#include "BattleDefine.h"
#include "Battle_PlayerBallParticle.h"

const std::string_view BattleEnemyMonster_CreatedInBall::BallFallAniName = "Fall";
const std::string_view BattleEnemyMonster_CreatedInBall::BallOpenAniName = "Open";

BattleEnemyMonster_CreatedInBall::BattleEnemyMonster_CreatedInBall()
{

}

BattleEnemyMonster_CreatedInBall::~BattleEnemyMonster_CreatedInBall()
{

}



void BattleEnemyMonster_CreatedInBall::EnterState()
{
	CreateRenders();

	GameEngineSoundPlayer Sfx = GameEngineResources::GetInst().SoundPlayToControl(BattleDefine::SfxName_BallPop);
	Sfx.LoopCount(1);
	Sfx.Volume(BattleDefine::WorldVolumn);

	float4 MonsterPos = BattleEnemy::EnemyPtr->GetMonster()->GetPos();
	DestOffset = MovePivot - MonsterPos;
}

void BattleEnemyMonster_CreatedInBall::CreateRenders()
{
	//몬스터의 실체 렌더 가져오기
	BattleMonsterEnemy* Monster = BattleEnemy::EnemyPtr->GetMonster();
	MonsterRender = Monster->GetRender();
	OriginScale = MonsterRender->GetScale();
	MonsterRender->SetScale(float4::Zero);

	//몬스터 이름을 바탕으로 이펙트 이미지 불러오기
	std::string MonsterName = Monster->GetName();
	std::string EffectImagePath = "Battle" + MonsterName + "FrontLight.bmp";

	//이펙트 이미지 설정
	EffectRender = Monster->CreateRender(EffectImagePath,BattleRenderOrder::CreateEffect);
	EffectRender->SetAlpha(150);
	EffectRender->SetScale(float4::Zero);

	//몬스터볼 애니메이션용 렌더 생성
	BallRender = Monster->CreateRender(BattleRenderOrder::MonsterBall);
	BallRender->SetScale(BallScale);

	//몬스터볼 회전 애니메이션
	BallRender->CreateAnimation
	({
		.AnimationName = BallFallAniName,
		.ImageName = "BattleMonsterBall.bmp",
		.Start = 0,
		.End = 7,
		.InterTime = 0.01f,
		.Loop = true
	});

	//몬스터볼 오픈 애니메이션
	BallRender->CreateAnimation
	({
		.AnimationName = BallOpenAniName,
		.ImageName = "BattleMonsterBallOpen.bmp",
		.Start = 0,
		.End = 1,
		.InterTime = 0.1f,
		.Loop = false
	});

	BallRender->ChangeAnimation(BallFallAniName);
}




void BattleEnemyMonster_CreatedInBall::Update(float _DeltaTime)
{
	switch (CurState)
	{
	case BattleEnemyMonster_CreatedInBall::State::JumpBall:
		Update_JumpBall(_DeltaTime);
		break;
	case BattleEnemyMonster_CreatedInBall::State::FallBall:
		Update_FallBall(_DeltaTime);
		break;
	case BattleEnemyMonster_CreatedInBall::State::OpenBall:
		Update_OpenBall(_DeltaTime);
		break;
	case BattleEnemyMonster_CreatedInBall::State::CreateMonster:
		Update_CreateMonster(_DeltaTime);
		break;
	}
}


void BattleEnemyMonster_CreatedInBall::Update_JumpBall(float _DeltaTime)
{
	static const float Duration = 0.25f;
	static float Timer = 0.f;

	Timer += _DeltaTime;
	float Ratio = (Timer / Duration);

	static const float4 StartOffset = MoveOffset + float4::Down * 25.f;
	float4 NowOffset = float4::LerpClamp(StartOffset, MoveOffset, Ratio);
	BallRender->SetPosition(NowOffset);

	if (Ratio <= 1.f)
		return;

	Timer = 0.f;
	CurState = State::FallBall;
}



void BattleEnemyMonster_CreatedInBall::Update_FallBall(float _DeltaTime)
{
	static const float Duration = 0.25f;
	static float Timer = 0.f;

	Timer += _DeltaTime;
	float Ratio = (Timer / Duration);

	//float4 NowOffset = float4::LerpClamp(MoveOffset, float4::Zero, Ratio);
	float4 NowOffset = float4::LerpClamp(MoveOffset, DestOffset, Ratio);
	BallRender->SetPosition(NowOffset);

	if (Ratio <= 1.f)
		return;

	GameEngineActor* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();

	Timer = 0.f;
	CurState = State::OpenBall;
	BallRender->ChangeAnimation(BallOpenAniName);

	BattleLevel::BattleLevelPtr->CreateActor<Battle_MonsterAppearEffect>(UpdateOrder::Battle_Actors);
	BattleLevel::BattleLevelPtr->CreateActor<Battle_PlayerBallParticle>(UpdateOrder::Battle_Actors)->SetPos(EnemyMonster->GetPos());
}



void BattleEnemyMonster_CreatedInBall::Update_OpenBall(float _DeltaTime)
{
	if (false == BallRender->IsAnimationEnd())
		return;

	CurState = State::CreateMonster;
}



void BattleEnemyMonster_CreatedInBall::Update_CreateMonster(float _DeltaTime)
{
	static float Timer = 0.f;
	static const float Duration = 0.25f;

	Timer += _DeltaTime;
	float Ratio = (Timer / Duration);
	float4 NowScale = float4::LerpClamp(float4::Zero, OriginScale, Ratio);

	MonsterRender->SetScale(NowScale);
	EffectRender->SetScale(NowScale);

	if (Ratio <= 1.f)
		return;

	Timer = 0.f;
	GetFSM()->ChangeState(BattleEnemyMonster_StateType::Idle);
	return;
}






void BattleEnemyMonster_CreatedInBall::ExitState()
{
	CurState = State::JumpBall;

	MonsterRender = nullptr;
	EffectRender->Death();
	EffectRender = nullptr;
	BallRender->Death();
	BallRender = nullptr;
}


