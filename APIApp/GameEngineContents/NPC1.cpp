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
	R_NPC1->ChangeAnimation("Idle");
}

void NPC1::Update(float _DeltaTime)
{
	NPC1index= Fieldmap::GetIndex(GetPos()); //��� index check






	//�÷��̾ ��ó���ְ�, ��ȣ�ۿ�Ű����������, ��� �������߰��ؾ���.
	//�Ǵ� Ÿ�ϸ���index�� �������ٲ㼭 ����ȭ�ϱ�
	if (NPCtalkValue::UP == Player::MainPlayer->GetPlayerNPCtalkValue()
		&&GameEngineInput::IsDown("NpcTalk"))
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


