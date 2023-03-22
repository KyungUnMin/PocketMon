#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>

#include "NPC1.h"
#include "ContentsEnum.h"
#include "Player.h"


NPC1::NPC1()
{
}

NPC1::~NPC1()
{
}

void NPC1::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Plyer_YDM");
	Dir.Move("NPC");
	Dir.Move("Green");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Down.bmp"))->Cut(1, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Left.bmp"))->Cut(1, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Right.bmp"))->Cut(1, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Up.bmp"))->Cut(1, 1);



}

void NPC1::Start()
{
	if (NPC1ImageLoad = true)
	{
		ImageLoad();
		NPC1ImageLoad = false;
	}

	{
		R_NPC1 = CreateRender(RenderOrder::Player);
		R_NPC1->SetScale({ 50,50 });
		R_NPC1->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "Green_Idle_Down.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		R_NPC1->CreateAnimation({ .AnimationName = "leftIdle",  .ImageName = "Green_Idle_Left.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		R_NPC1->CreateAnimation({ .AnimationName = "rightIdle",  .ImageName = "Green_Idle_Right.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		R_NPC1->CreateAnimation({ .AnimationName = "upIdle",  .ImageName = "Green_Idle_Up.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		
	/*
		R_NPC1->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "WalkRight.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
		R_NPC1->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		R_NPC1->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		R_NPC1->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });*/
	}
	{
		C_NPC_U = CreateCollision(CollisionOrder::NPC);
		C_NPC_U->SetDebugRenderType(CollisionType::CT_Rect);
		C_NPC_U->SetScale({ 64, 64 });
		C_NPC_U->SetPosition({ 0,-64 });

		C_NPC_D = CreateCollision(CollisionOrder::NPC);
		C_NPC_D->SetDebugRenderType(CollisionType::CT_Rect);
		C_NPC_D->SetScale({ 64, 64 });
		C_NPC_D->SetPosition({ 0,64 });

		C_NPC_R = CreateCollision(CollisionOrder::NPC);
		C_NPC_R->SetDebugRenderType(CollisionType::CT_Rect);
		C_NPC_R->SetScale({ 64, 64 });
		C_NPC_R->SetPosition({ 64,0 });

		C_NPC_L = CreateCollision(CollisionOrder::NPC);
		C_NPC_L->SetDebugRenderType(CollisionType::CT_Rect);
		C_NPC_L->SetScale({ 64, 64 });
		C_NPC_L->SetPosition({ -64,0 });
	}
	R_NPC1->ChangeAnimation("Idle");
}




void NPC1::Update(float _DeltaTime)
{
	//아직미사용
	NPC1index= Fieldmap::GetIndex(GetPos()); //계속 index check

	std::vector<GameEngineCollision*> CheckCollisions;
	CollisionCheckParameter CheckPlayer = { .TargetGroup = static_cast<int>(CollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	
	if (true == C_NPC_U->Collision(CheckPlayer, CheckCollisions) ||
		true == C_NPC_D->Collision(CheckPlayer, CheckCollisions) ||
		true == C_NPC_L->Collision(CheckPlayer, CheckCollisions) ||
		true == C_NPC_R->Collision(CheckPlayer, CheckCollisions))
	{
		if (NPCtalkValue::UP == Player::MainPlayer->GetPlayerNPCtalkValue()
			&& GameEngineInput::IsDown("NpcTalk"))
		{
			R_NPC1->ChangeAnimation("upIdle");
		}
		if (NPCtalkValue::DOWN == Player::MainPlayer->GetPlayerNPCtalkValue()
			&& GameEngineInput::IsDown("NpcTalk"))
		{
			R_NPC1->ChangeAnimation("Idle");
		}
		if (NPCtalkValue::RIGHT == Player::MainPlayer->GetPlayerNPCtalkValue()
			&& GameEngineInput::IsDown("NpcTalk"))
		{
			R_NPC1->ChangeAnimation("rightIdle");
		}
		if (NPCtalkValue::LEFT == Player::MainPlayer->GetPlayerNPCtalkValue()
			&& GameEngineInput::IsDown("NpcTalk"))
		{
			R_NPC1->ChangeAnimation("leftIdle");
		}
	}
	
}

void NPC1::Render(float _DeltaTime)
{
	if (GameEngineInput::IsPress("CollisionRender"))
	{
		C_NPC_U->DebugRender();
		C_NPC_D->DebugRender();
		C_NPC_L->DebugRender();
		C_NPC_R->DebugRender();
	}
}

