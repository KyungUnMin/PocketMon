#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>

#include "ShopNpc.h"
#include "ContentsEnum.h"
#include "Player.h"
#include "FieldDialog.h"
#include "ShopUIManager.h"


ShopNpc::ShopNpc()
{
}

ShopNpc::~ShopNpc()
{
}
void ShopNpc::ImageLoad()
{
	

}

void ShopNpc::Start()
{
	
	
	ImageLoad();
	

	{
		R_NPC1 = CreateRender(RenderOrder::Player);
		R_NPC1->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "NPC_Shop.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
		R_NPC1->SetScale({ 110,110 });
		R_NPC1->SetPosition({ 0,-8 });
	}
	{
		C_NPC_R = CreateCollision(CollisionOrder::NPC);
		C_NPC_R->SetDebugRenderType(CollisionType::CT_Rect);
		C_NPC_R->SetScale({ 128, 64 });
		C_NPC_R->SetPosition({ 64,0 });

		
	}
	R_NPC1->ChangeAnimation("Idle");
}




void ShopNpc::Update(float _DeltaTime)
{
	if (Player::MainPlayer->GetDir() != LookDir::Left)
	{
		return;
	}
	
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


void ShopNpc::Render(float _DeltaTime)
{
}








