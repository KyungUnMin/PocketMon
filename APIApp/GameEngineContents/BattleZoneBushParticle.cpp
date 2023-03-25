#include "BattleZoneBushParticle.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

BattleZoneBushParticle::BattleZoneBushParticle()
{
}

BattleZoneBushParticle::~BattleZoneBushParticle()
{
}

void BattleZoneBushParticle::Start()
{
	AnimRender = CreateRender("BushEffect.bmp", RenderOrder::Particle);
	AnimRender->CreateAnimation({.AnimationName = "Play",
		.ImageName = "BushEffect.bmp",
		.Start = 0,
		.End = 3,
		.InterTime = 0.1f,
		.Loop = false});
	AnimRender->ChangeAnimation("Play");
	AnimRender->SetScale(float4(Fieldmap::TileSize, Fieldmap::TileSize));
}

void BattleZoneBushParticle::Update(float _DeltaTime)
{
	if (true == AnimRender->IsAnimationEnd())
	{
		Death();
	}
}