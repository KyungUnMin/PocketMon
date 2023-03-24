#include "EndingPlayerAnimActor.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

EndingPlayerAnimActor::EndingPlayerAnimActor()
{
}

EndingPlayerAnimActor::~EndingPlayerAnimActor()
{
}

void EndingPlayerAnimActor::Start()
{
	AnimRender = CreateRender("EndingWalk.BMP", RenderOrder::EndingFront);
	AnimRender->CreateAnimation({ .AnimationName = "WalkAnim"
		,.ImageName = "EndingWalk.bmp"
		, .Start = 0
		, .End = 5
		, .InterTime = 0.09f
		, .Loop = true });
	AnimRender->ChangeAnimation("WalkAnim");
	AnimRender->SetPosition(float4::Zero);
	AnimRender->SetScale(float4(280, 280));
	AnimRender->EffectCameraOff();
}