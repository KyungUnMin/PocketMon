#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "Player.h"
#include "ContentConst.h"




void Player::PlayerRenderLoad()
{
	SetMove(GameEngineWindow::GetScreenSize().half());  //�����ϸ���ġ�� �����
	SetPos(GameEngineWindow::GetScreenSize().half());
	{
		Players = CreateRender(RenderOrder::Player);
		Players->SetScale(ContentConst::NpcSize);
		Players->SetPosition(ContentConst::NpcRenderPos);
		Players->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdleRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "IdleLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "IdleUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "IdleDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });

		Players->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "WalkRight.bmp", .Start = 0, .End = 2, .InterTime = 0.0625f });
		Players->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.0625f });
		Players->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.0625f });
		Players->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 3 , .InterTime = 0.0625f });


		BikePlayers = CreateRender(RenderOrder::Player);
		BikePlayers->SetScale(ContentConst::NpcSize);
		BikePlayers->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "BikeStopRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "BikeStopLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "BikeStopUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "BikeStopDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });

		BikePlayers->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "BikeRight.bmp", .Start = 0, .End = 2, .InterTime = 0.04f });
		BikePlayers->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "BikeLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.04f });
		BikePlayers->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "BikeUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.04f });
		BikePlayers->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "BikeDown.bmp", .Start = 0, .End = 2 , .InterTime = 0.04f });
		BikePlayers->Off();
	}
}

void Player::PlayerCollisionSet()
{
	RedCollision = CreateCollision(CollisionOrder::Player);
	RedCollision->SetScale({ 64, 64 });
	RedCollision->SetPosition({ 0,0 });
	RedCollision->On();
	RedCollision->SetDebugRenderType(CollisionType::CT_Rect);
}

void Player::PlayerKeyLoad()
{
	if (false == GameEngineInput::IsKey("NpcTalk"))
	{
		GameEngineInput::CreateKey("NpcTalk", 'Z');
	}
}