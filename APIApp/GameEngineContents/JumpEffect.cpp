#include "JumpEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

JumpEffect::JumpEffect()
{
}

JumpEffect::~JumpEffect()
{
}

void JumpEffect::Start()
{
	Effect = CreateRender(RenderOrder::Player_Shadow);
	Effect->SetScale({ 120,50 });
	Effect->SetPosition({ 0,10 });
	Effect->CreateAnimation({ .AnimationName = "JumpEffect",  .ImageName = "JumpEffect.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
}

void JumpEffect::Update(float _DeltaTime)
{
	Effect->ChangeAnimation("JumpEffect");
	if (Effect->IsAnimationEnd())
	{
		Death();
	}
}