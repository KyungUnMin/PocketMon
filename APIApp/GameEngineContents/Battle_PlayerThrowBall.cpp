#include "Battle_PlayerThrowBall.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

Battle_PlayerThrowBall::Battle_PlayerThrowBall()
{

}

Battle_PlayerThrowBall::~Battle_PlayerThrowBall()
{
}



void Battle_PlayerThrowBall::Start()
{
	GameEngineRender* RenderPtr = CreateRender(BattleRenderOrder::Particle0);

	std::vector<int> FrameIndex(8);
	for (size_t i = 0; i < FrameIndex.size(); ++i)
	{
		FrameIndex[i] = 7 - static_cast<int>(i);
	}

	RenderPtr->CreateAnimation
	({
		.AnimationName = "Roll",
		.ImageName = "BattleBallThrow.bmp",
		.FrameIndex = FrameIndex
	});

	RenderPtr->SetScale(RenderScale);
	RenderPtr->ChangeAnimation("Roll");
}

void Battle_PlayerThrowBall::Init(const float4& _DestPos, float _Duration)
{
	const float4 StartOffset = float4{ -100.f, -200.f };

	StartPosX.x = _DestPos.x + StartOffset.x;
	DestPosX.x = _DestPos.x;
	Duration = _Duration;

	SetPos(_DestPos + StartOffset);
}

void Battle_PlayerThrowBall::Update(float _DeltaTime)
{
	float LiveTime = GetLiveTime();
	if (Duration < LiveTime)
	{
		Death();
		return;
	}

	float Ratio = LiveTime / Duration;
	float4 NextPos = GetPos();
	NextPos.x = float4::Lerp(StartPosX, DestPosX, Ratio).x;

	VerticalSpeed += GravityAcc * _DeltaTime;
	NextPos.y += VerticalSpeed * _DeltaTime;
	SetPos(NextPos);
}
