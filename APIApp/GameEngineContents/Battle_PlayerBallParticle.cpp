#include "Battle_PlayerBallParticle.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

Battle_PlayerBallParticle::Battle_PlayerBallParticle()
{

}

Battle_PlayerBallParticle::~Battle_PlayerBallParticle()
{

}

void Battle_PlayerBallParticle::Start()
{
	const int ParticleCnt = 10;
	const float MaxRangeX = 100.f;
	const float MaxJumpScale = 300.f;
	const float MinJumpScale = 250.f;
	const float MinInterTime = 0.05f;
	const float MaxInterTime = 0.1f;

	Particles.resize(ParticleCnt);

	for (std::pair<GameEngineRender*, float4>& Pair : Particles)
	{
		GameEngineRender* RenderPtr = CreateRender(BattleRenderOrder::Particle1);
		RenderPtr->CreateAnimation
		({
			.AnimationName = "Particle",
			.ImageName = "BattleBallParticle.bmp",
			.Start = 0,
			.End = 6,
			.InterTime = GameEngineRandom::MainRandom.RandomFloat(MinInterTime, MaxInterTime)
		});

		RenderPtr->ChangeAnimation("Particle");
		RenderPtr->SetScale(RenderScale);
		Pair.first = RenderPtr;

		Pair.second.x = GameEngineRandom::MainRandom.RandomFloat(-MaxRangeX, MaxRangeX);
		float JumpScale = GameEngineRandom::MainRandom.RandomFloat(MinJumpScale, MaxJumpScale);
		Pair.second.y = -JumpScale;
	}
}

void Battle_PlayerBallParticle::Update(float _DeltaTime)
{
	static const float GravityAcc = 300.f;
	
	if (Duration < GetLiveTime())
	{
		Death();
		return;
	}

	for (std::pair<GameEngineRender*, float4>& Pair : Particles)
	{
		float4& NowSpeed = Pair.second;
		NowSpeed += float4::Down * GravityAcc * _DeltaTime;

		GameEngineRender* RenderPtr = Pair.first;
		RenderPtr->SetMove(NowSpeed * _DeltaTime);
	}
}
