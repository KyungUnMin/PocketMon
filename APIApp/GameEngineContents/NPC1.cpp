#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>

#include "NPC1.h"
#include "ContentsEnum.h"



//NPC1::NPC1()
//{
//}
//
//NPC1::~NPC1()
//{
//}
//
//void NPC1::ImageLoad()
//{
//	GameEngineDirectory Dir;
//	Dir.MoveParentToDirectory("ContentsResources");
//	Dir.Move("ContentsResources");
//	Dir.Move("Image");
//	Dir.Move("Plyer_YDM");
//	Dir.Move("NPC");
//}
//
//void NPC1::Start()
//{
//	{
//		R_NPC1 = CreateRender(RenderOrder::Player);
//		R_NPC1->SetScale({ 50,50 });
//		R_NPC1->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IdleRight.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
//		R_NPC1->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "IdleLeft.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
//		R_NPC1->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "IdleUp.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
//		R_NPC1->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "IdleDown.bmp", .Start = 0, .End = 0, .InterTime = 1.0f });
//	
//		R_NPC1->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "WalkRight.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
//		R_NPC1->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "WalkLeft.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
//		R_NPC1->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "WalkUp.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
//		R_NPC1->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "WalkDown.bmp", .Start = 0, .End = 2 , .InterTime = 0.1f });
//	}
//	
//}
//
//void NPC1::Update(float _DeltaTime)
//{
//	
//}


