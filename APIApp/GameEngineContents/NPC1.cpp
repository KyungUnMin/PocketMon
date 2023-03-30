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
#include "ShopUIManager.h"


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
	Dir.Move("7");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC_Shop.bmp"))->Cut(1, 1);



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
		R_NPC1->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "NPC_Shop.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		R_NPC1->SetScale({ 128,128 });
		R_NPC1->SetPosition({ 0,-10 });
	}
	{
		C_NPC_R = CreateCollision(CollisionOrder::NPC);
		C_NPC_R->SetDebugRenderType(CollisionType::CT_Rect);
		C_NPC_R->SetScale({ 128, 64 });
		C_NPC_R->SetPosition({ 64,0 });

		
	}
	R_NPC1->ChangeAnimation("Idle");
}




void NPC1::Update(float _DeltaTime)
{

	AutoRightMove(_DeltaTime);
	std::vector<GameEngineCollision*> CheckCollisions;
	CollisionCheckParameter CheckPlayer = { .TargetGroup = static_cast<int>(CollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == C_NPC_R->Collision(CheckPlayer, CheckCollisions))
	{
		FieldDialog* a = FieldDialog::GetFieldDialog();
		if (true == GameEngineInput::IsDown("NpcTalk") && Player::MainPlayer->GetPlayerMoveBool())
		{
			ShopUIManager::GetShopUIManager()->On();
		}
	}

}


void NPC1::Render(float _DeltaTime)
{
	if (GameEngineInput::IsPress("CollisionRender"))
	{
		C_NPC_R->DebugRender();
	}
}
bool Test1 = true;
bool Test2 = false;
bool Test3 = false;
bool Test4 = false;
void NPC1::AutoRightMove(float _DeltaTime)
{
		if (true == Test1)
		{
			MoveTime += _DeltaTime;
			StartPos = GetPos();
			EndPos = GetPos() + float4{ 64 ,0 };
			Dir = LookDir::Right;
			SetPos(float4::LerpClamp(StartPos, EndPos, MoveTime));
			if (MoveTime > 0.1f)
			{
				MoveTime = 0.0f;
				Dir = LookDir::Up;
				Test1 = false;
				Test2 = true;
			}
		}
		if (true == Test2)
		{
			MoveTime += _DeltaTime*0.1;
			StartPos = GetPos();
			EndPos = GetPos() + float4{ 0 ,-64 };
			Dir = LookDir::Right;
			SetPos(float4::LerpClamp(StartPos, EndPos, MoveTime));
			if (MoveTime > 1.0f)
			{
				Test2 = false;
				Test3 = true;
				MoveTime = 0.0f;
				Dir = LookDir::Left;
			}
		}




	
}



