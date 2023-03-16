#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>

#include "Player.h"


Player* Player::MainPlayer;

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	MainPlayer = this; 

	SetMove(GameEngineWindow::GetScreenSize().half());  //시작하면위치는 가운데로
	SetPos(GameEngineWindow::GetScreenSize().half());
	{
		Players = CreateRender(PlayerTestOrder::R_Player);
		Players->SetScale({ 50,50 });
		Players->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdleRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "IdleLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "IdleUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		Players->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "IdleDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });

		Players->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "WalkRight.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
		Players->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		Players->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		Players->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		Players->On();

		BikePlayers = CreateRender(PlayerTestOrder::R_Player);
		BikePlayers->SetScale({ 50,50 });
		BikePlayers->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "BikeStopRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "BikeStopLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "BikeStopUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		BikePlayers->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "BikeStopDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		
		BikePlayers->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "BikeRight.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
		BikePlayers->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "BikeLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		BikePlayers->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "BikeUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		BikePlayers->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "BikeDown.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		BikePlayers->Off();

	}
	ChangeState(PlayerState::IDLE);
}

void Player::Update(float _DeltaTime)
{
	//CollisionCheck(_DeltaTime);
	//Movecalculation(_DeltaTime);
	UpdateState(_DeltaTime);
	SetMove(MoveDir* _DeltaTime);
}

//맵 충돌 관리
void Player::Movecalculation(float _DeltaTime)
{
	
}

//collision 체크
void Player::CollisionCheck(float _DeltaTime)
{
	
}


void Player::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	Players->ChangeAnimation(DirString + _AnimationName.data());
	BikePlayers->ChangeAnimation(DirString + _AnimationName.data());

	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
	}
	else if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
	}

	if (PrevDirString != DirString)
	{
		Players->ChangeAnimation(DirString + _AnimationName.data());
		BikePlayers->ChangeAnimation(DirString + _AnimationName.data());
	}
}



void Player::Render(float _DeltaTime)
{
	
}