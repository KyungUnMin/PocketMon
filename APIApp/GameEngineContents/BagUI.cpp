#include "BagUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
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

		BagRender = CreateRender("Bag_LeftOpen.bmp", RenderOrder::Player);
		BagRender->SetScaleToImage();
		BagRender->SetPosition({ 168, 276 });

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

		CurrentArrow = CreateRender("Bag_CurrentArrow.bmp", RenderOrder::Player);
		CurrentArrow->SetScaleToImage();
		CurrentArrow->SetPosition({ 372, 64 });
	}
	ChangeSpace(BagSpace::Items);	// 아이템 공간으로 이동

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
	if (GameEngineInput::IsDown("LevelChange1"))
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
		BagRender->SetImage("Bag_LeftOpen.bmp");
		SpaceText->SetImage("Bag_Items.bmp");
		LeftArrow->Off();
		break;
	case BagSpace::KeyItems:
		BagRender->SetImage("Bag_MiddleOpen.bmp");
		SpaceText->SetImage("Bag_KeyItems.bmp");
		LeftArrow->On();
		RightArrow->On();
		break;
	case BagSpace::PokeBalls:
		BagRender->SetImage("Bag_RightOpen.bmp");
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
