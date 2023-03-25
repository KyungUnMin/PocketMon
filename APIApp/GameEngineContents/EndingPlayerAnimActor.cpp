#include "EndingPlayerAnimActor.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

EndingPlayerAnimActor::EndingPlayerAnimActor()
{
}

EndingPlayerAnimActor::~EndingPlayerAnimActor()
{
}

void EndingPlayerAnimActor::MovePos(const float4& _Start, const float4& _Dest, float _Speed)
{
	if (true == IsMove)
	{
		return;
	}

	IsMove = true;
	Speed = _Speed;

	Progress = 0.0f;
	StartPos = _Start;
	DestPos = _Dest;
}

void EndingPlayerAnimActor::Start()
{
	AnimRender = CreateRender("EndingWalk.BMP", RenderOrder::EndingFront);
	AnimRender->CreateAnimation({ .AnimationName = "WalkAnim"
		,.ImageName = "EndingWalk.bmp"
		, .Start = 0
		, .End = 5
		, .InterTime = 0.2f
		, .Loop = true });
	AnimRender->ChangeAnimation("WalkAnim");
	AnimRender->SetPosition(float4::Zero);
	AnimRender->SetScale(float4(280, 280));
	AnimRender->EffectCameraOff();

	GroundRender = CreateRender("EndingGround.BMP", RenderOrder::EndingMiddle);
	GroundRender->SetPosition(float4(0, 110));
	GroundRender->SetScale(float4(275, 74));
	GroundRender->EffectCameraOff();
}

void EndingPlayerAnimActor::Update(float _DeltaTime)
{
	if (false == IsMove)
	{
		return;
	}

	Progress += _DeltaTime * Speed;
	SetPos(float4::LerpClamp(StartPos, DestPos, Progress));

	if (1.0f <= Progress)
	{
		IsMove = false;
	}
}