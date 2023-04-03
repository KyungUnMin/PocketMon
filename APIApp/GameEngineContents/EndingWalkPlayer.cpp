#include "EndingWalkPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "ContentConst.h"
#include "Player.h"
#include "Fieldmap.h"

EndingWalkPlayer::EndingWalkPlayer()
{
}

EndingWalkPlayer::~EndingWalkPlayer()
{
}

void EndingWalkPlayer::Start()
{
	AnimRender = CreateRender(RenderOrder::Player);

	AnimRender->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "IdleDown.bmp", .Start = 0, .End = 0, .InterTime = 0.0625f });
	AnimRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "WalkRight.bmp", .Start = 0, .End = 3, .InterTime = 0.0625f });
	AnimRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 3 , .InterTime = 0.0625f });
	AnimRender->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 3 , .InterTime = 0.0625f });
	AnimRender->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 3 , .InterTime = 0.0625f });
	AnimRender->SetScale(ContentConst::NpcSize);

	AnimRender->ChangeAnimation("Idle");
	
	int2 TempIndex = int2(15, 16);

	SetPos(Fieldmap::GetPos("PewterCity", TempIndex));

	TempIndex.y += 1;
	MovePoint.push_back(Fieldmap::GetPos("PewterCity", TempIndex));

	for (size_t i = 0; i < 10; i++)
	{
		TempIndex.x -= 1;
		MovePoint.push_back(Fieldmap::GetPos("PewterCity", TempIndex));
	}

	ProgressTime = 1.0f;
}

void EndingWalkPlayer::Update(float _DeltaTime)
{
	if (0 < WaitTime)
	{
		WaitTime -= _DeltaTime;
		return;
	}

	ProgressTime += _DeltaTime * Speed;

	if (MovePoint.size() == 0)
	{
		if (1.0f <= ProgressTime)
		{
			Death();
			return;
		}
	}
	else if (1.0f <= ProgressTime)
	{
		ProgressTime -= 1.0f;

		MoveStartPos = GetPos();
		MoveEndPos = MovePoint.front();
		MovePoint.pop_front();

		switch (Player::CalLookDir(MoveStartPos, MoveEndPos))
		{
		case LookDir::Up:
			AnimRender->ChangeAnimation("Up_Move");
			break;
		case LookDir::Down:
			AnimRender->ChangeAnimation("Down_Move");
			break;
		case LookDir::Left:
			AnimRender->ChangeAnimation("Left_Move");
			break;
		case LookDir::Right:
			AnimRender->ChangeAnimation("Right_Move");
			break;
		default:
			AnimRender->ChangeAnimation("Idle");
			break;
		}
	}


	SetPos(float4::LerpClamp(MoveStartPos, MoveEndPos, ProgressTime));
}
