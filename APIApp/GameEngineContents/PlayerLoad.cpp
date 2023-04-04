#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include "Player.h"
#include "ContentConst.h"




void Player::PlayerRenderLoad()
{
	SetMove(GameEngineWindow::GetScreenSize().half());  //시작하면위치는 가운데로
	SetPos(GameEngineWindow::GetScreenSize().half());
	{
		Players = CreateRender(RenderOrder::Player);
		Players->SetScale(ContentConst::NpcSize);
		Players->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdleRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "IdleLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "IdleUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "IdleDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });

		Players->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "WalkRight.bmp", .Start = 0, .End = 3, .InterTime = 0.05f });
		Players->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 3 , .InterTime = 0.05f });
		Players->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 3 , .InterTime = 0.05f });
		Players->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 3 , .InterTime = 0.05f });
		
		Players->CreateAnimation({ .AnimationName = "Right_Clear", .ImageName = "GymClear.bmp", .Start = 0, .End = 5 , .InterTime = 0.1f, .Loop = false});
		Players->CreateAnimation({ .AnimationName = "Left_Clear",  .ImageName = "GymClear.bmp", .Start = 0, .End = 5 , .InterTime = 0.1f, .Loop = false});
		Players->CreateAnimation({ .AnimationName = "Up_Clear",    .ImageName = "GymClear.bmp", .Start = 0, .End = 5 , .InterTime = 0.1f, .Loop = false});
		Players->CreateAnimation({ .AnimationName = "Down_Clear",  .ImageName = "GymClear.bmp", .Start = 0, .End = 5 , .InterTime = 0.1f, .Loop = false});

		Players->CreateAnimation({ .AnimationName = "Jump",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 0 , .InterTime = 0.5f });

		BikePlayers = CreateRender(RenderOrder::Player);
		BikePlayers->SetScale(ContentConst::NpcSize);
		BikePlayers->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "BikeStopRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "BikeStopLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "BikeStopUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "BikeStopDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });

		BikePlayers->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "BikeRight.bmp", .Start = 0, .End = 2, .InterTime = 0.05f });
		BikePlayers->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "BikeLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.05f });
		BikePlayers->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "BikeUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.05f });
		BikePlayers->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "BikeDown1.bmp", .Start = 0, .End = 2 , .InterTime = 0.05f });
		BikePlayers->Off();

		Shadow = CreateRender(RenderOrder::Player_Shadow);
		Shadow->SetScale({50,20});
		Shadow->SetPosition({ 0,40 });
		Shadow->CreateAnimation({ .AnimationName = "Shadow",  .ImageName = "Shadow.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Shadow->ChangeAnimation("Shadow");
		Shadow->Off();
	}
}

void Player::PlayerSoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	Dir.Move("FieldUI");

	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("PlayerJump.wav"));//Jump Sound
	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("PlayerMoveBlock.wav"));//Block Sound
	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BikeRing.wav"));//따릉
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