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
#include "FieldDialog.h"


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

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Walk_Left.bmp"))->Cut(3, 1);
	//GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Up.bmp"))->Cut(1, 1);
	//GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Up.bmp"))->Cut(1, 1);
	//GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green_Idle_Up.bmp"))->Cut(1, 1);


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
		
	
		R_NPC1->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Green_Walk_Left.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
		R_NPC1->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		R_NPC1->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
		R_NPC1->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
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

	Script.push_back("Hi");
	Script.push_back("Im your rival");
	Script.push_back("bye bye");
}




void NPC1::Update(float _DeltaTime)
{
	NpcMoveTime += _DeltaTime;

	NPC1index= Fieldmap::GetIndex(GetPos()); //��� index check
	Fieldmap::SetWalkable("PalletTown", NPC1index, false);

	int2 Nextindexs = NPC1index;
	if (NpcMoveTime > 2.0f)
	{
		Nextindexs.x += 1;
		NpcMoveTime = 0.0f;
	}
	float4 Start = GetPos();
	float4 End = Fieldmap::GetPos(Nextindexs);

	float4 Position=float4::LerpClamp(Start, End, NpcMoveTime);
	SetPos(Position);
	if (NpcMoveTime > 1.0f)
	{
		NpcMoveTime = 0.0f;
	}

	
	
	
	

	std::vector<GameEngineCollision*> CheckCollisions;
	CollisionCheckParameter CheckPlayer = { .TargetGroup = static_cast<int>(CollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	
	if (true == C_NPC_U->Collision(CheckPlayer, CheckCollisions) ||
		true == C_NPC_D->Collision(CheckPlayer, CheckCollisions) ||
		true == C_NPC_L->Collision(CheckPlayer, CheckCollisions) ||
		true == C_NPC_R->Collision(CheckPlayer, CheckCollisions))
	{
		if (GameEngineInput::IsDown("NpcTalk")&& true==Player::MainPlayer->GetPlayerMoveBool())
		{
			Player::MainPlayer->SetPlayerMoveBool(false);
			if (NPCtalkValue::UP == Player::MainPlayer->GetPlayerNPCtalkValue())
			{
				R_NPC1->ChangeAnimation("upIdle");
			}
			if (NPCtalkValue::DOWN == Player::MainPlayer->GetPlayerNPCtalkValue())
			{
				R_NPC1->ChangeAnimation("Idle");
			}
			if (NPCtalkValue::RIGHT == Player::MainPlayer->GetPlayerNPCtalkValue())
			{
				R_NPC1->ChangeAnimation("rightIdle");
			}
			if (NPCtalkValue::LEFT == Player::MainPlayer->GetPlayerNPCtalkValue())
			{
				R_NPC1->ChangeAnimation("leftIdle");
			}
			FieldDialog::GetFieldDialog()->ConversationStart(&Script);
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

void NPC1::MovePattern1()
{
	
}
void MovePattern2();
void MovePattern3();
void MovePattern4();

