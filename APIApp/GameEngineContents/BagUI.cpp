#include "BagUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TextActor.h"
#include "ContentsEnum.h"
BagUI::BagUI() {
}

BagUI::~BagUI() {

}

void BagUI::Start()
{
	// ____________렌더 생성______________
	{
		GameEngineRender* BackUI = CreateRender("Bag_Back.bmp", RenderOrder::BackGround);
		BackUI->SetScaleToImage();
		BackUI->SetPosition(BackUI->GetScale().half());

		BagRender = CreateRender("Bag.bmp", RenderOrder::Player);
		BagRender->CreateAnimation({ .AnimationName = "Left", .ImageName = "Bag.bmp", .FilterName = "Bag_Roll.bmp", .Start = 0, .End = 0});
		BagRender->CreateAnimation({ .AnimationName = "Middle", .ImageName = "Bag.bmp", .FilterName = "Bag_Roll.bmp", .Start = 1, .End = 1 });
		BagRender->CreateAnimation({ .AnimationName = "Right", .ImageName = "Bag.bmp", .FilterName = "Bag_Roll.bmp", .Start = 2, .End = 2 });
		BagRender->SetScale({232, 252});
		BagRender->SetPosition({ 168, 276 });
		BagRender->ChangeAnimation("Left");

		GameEngineRender* BackShadow = CreateRender("Bag_Shadow.bmp", RenderOrder::Monster);
		BackShadow->SetScaleToImage();
		BackShadow->SetPosition({ 168, 276 });

		SpaceText = CreateRender("Bag_Items.bmp", RenderOrder::Player);
		SpaceText->SetScaleToImage();
		SpaceText->SetPosition({ 168, 62 });

		IconRender = CreateRender("Bag_EnterArrow.bmp", RenderOrder::Player);
		IconRender->SetScaleToImage();
		IconRender->SetPosition({ 80, 550 });

		RightArrow = CreateRender("Bag_RightArrow.bmp", RenderOrder::Player);
		RightArrow->SetScaleToImage();
		RightArrow->SetPosition({ 300, 280 });

		LeftArrow = CreateRender("Bag_LeftArrow.bmp", RenderOrder::Player);
		LeftArrow->SetScaleToImage();
		LeftArrow->SetPosition({ 28, 280 });

		UpArrow = CreateRender("Bag_UpArrow.bmp", RenderOrder::Player);
		UpArrow->SetScaleToImage();
		UpArrow->SetPosition({ 644, 22 });

		DownArrow = CreateRender("Bag_DownArrow.bmp", RenderOrder::Player);
		DownArrow->SetScaleToImage();
		DownArrow->SetPosition({ 644, 424 });

		CurrentCursor = CreateRender("Bag_CurrentArrow.bmp", RenderOrder::Player);
		CurrentCursor->SetScaleToImage();
		CurrentCursor->SetPosition({ 372, 68 });
	}
	CurrentSpace = BagSpace::Items;

	Items[0] = GetLevel()->CreateActor<TextActor>();
	Items[0]->SetText("POTION");
	Items[0]->SetPos({ 404, 72 });
	Items[1] = GetLevel()->CreateActor<TextActor>();
	Items[1]->SetText("REVIVE");
	Items[1]->SetPos({ 404, 136 });
	ItemInfo = GetLevel()->CreateActor<TextActor>();
	ItemInfo->SetText("A spary type wound medicine It restores the Hp of one POKEMON by 200 points", "Font_Dialog_White.bmp", true);
	ItemInfo->SetPos({ 172, 488 });
}

void BagUI::Update(float _DeltaTime)
{
	// 가방 조작
	if (GameEngineInput::IsDown("LeftMove"))
	{
		ChangeSpaceLeft();
	}
	if (GameEngineInput::IsDown("RightMove"))
	{
		ChangeSpaceRight();
	}
	if (GameEngineInput::IsDown("UpMove"))
	{

	}
	if (GameEngineInput::IsDown("DownMove"))
	{

	}

}

void BagUI::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
}

void BagUI::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void BagUI::ChangeSpace(BagSpace _Space)
{
	// 가방의 공간을 이동한다 (카테고리 변경)
	// 1. 도구, 2. 중요한물건, 3. 볼
	CurrentSpace = _Space;
	// 이동한 곳에 따라 렌더들을 변경
	switch (CurrentSpace)
	{
	case BagSpace::Items:
		BagRender->ChangeAnimation("Left");
		SpaceText->SetImage("Bag_Items.bmp");
		LeftArrow->Off();
		break;
	case BagSpace::KeyItems:
		BagRender->ChangeAnimation("Middle");
		SpaceText->SetImage("Bag_KeyItems.bmp");
		LeftArrow->On();
		RightArrow->On();
		break;
	case BagSpace::PokeBalls:
		BagRender->ChangeAnimation("Right");
		SpaceText->SetImage("Bag_PoketBalls.bmp");
		RightArrow->Off();
		break;
	default:
		break;
	}

	//______ (미구현) 해당 카테고리에 맞는 아이템들을 나열_______
}

void BagUI::ChangeSpaceLeft()
{
	// 가방의 왼쪽 공간으로 이동
	switch (CurrentSpace)
	{
	case BagSpace::Items:
		break;
	case BagSpace::KeyItems:
		ChangeSpace(BagSpace::Items);
		break;
	case BagSpace::PokeBalls:
		ChangeSpace(BagSpace::KeyItems);
		break;
	default:
		break;
	}
}

void BagUI::ChangeSpaceRight()
{
	// 가방의 오른쪽 공간으로 이동
	switch (CurrentSpace)
	{
	case BagSpace::Items:
		ChangeSpace(BagSpace::KeyItems);
		break;
	case BagSpace::KeyItems:
		ChangeSpace(BagSpace::PokeBalls);
		break;
	case BagSpace::PokeBalls:
		break;
	default:
		break;
	}
}
