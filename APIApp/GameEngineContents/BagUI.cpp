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
		BagRender->SetRotFilter("Bag_Roll.bmp");
		BagRender->SetScale({232, 252});
		BagRender->SetPosition({ 168, 276 });
		BagRender->SetFrame(0);

		GameEngineRender* BackShadow = CreateRender("Bag_Shadow.bmp", RenderOrder::Monster);
		BackShadow->SetScaleToImage();
		BackShadow->SetPosition({ 168, 276 });

		SpaceText = CreateRender("Bag_Items.bmp", RenderOrder::Player);
		SpaceText->SetScaleToImage();
		SpaceText->SetPosition({ 168, 62 });

		IconRender = CreateRender("Items.bmp", RenderOrder::Player);
		IconRender->SetScale({ 128,128 });
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

		CursorRender = CreateRender("Bag_CurrentArrow.bmp", RenderOrder::Player);
		CursorRender->SetScaleToImage();
		CursorRender->SetPosition({ 372, 68 });
	}
	CurrentSpace = BagSpace::Items;
	GameEngineLevel* BagLevel = GetLevel();
	ItemName[0] = BagLevel->CreateActor<TextActor>();
	ItemName[0]->SetPos({ 404, 72 });
	ItemName[1] = BagLevel->CreateActor<TextActor>();
	ItemName[1]->SetPos({ 404, 136 });
	ItemInfo = BagLevel->CreateActor<TextActor>();
	ItemInfo->SetPos({ 172, 488 });
	//ItemInfo->SetText("A spary type wound medicine It restores the Hp of one POKEMON by 200 points", "Font_Dialog_White.bmp", true);

	// 아이템 생성
	{
		Items.reserve(2);
		Items.push_back(Item("POTION", "A spary type wound medicine It restores the Hp of one POKEMON by 200 points", 0, 0));
		Items.push_back(Item("CANCEL", "CLOSE BAG", 27, -1));
		ItemName[0]->SetText(Items[0].Name);
		ItemInfo->SetText(Items[0].Information, "Font_Dialog_White.bmp", false);
		IconRender->SetFrame(Items[0].ItemCode);
		ItemName[1]->SetText(Items[1].Name);
	}
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
		CursorUp();
	}
	if (GameEngineInput::IsDown("DownMove"))
	{
		CursorDown();
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
		BagRender->SetFrame(0);
		SpaceText->SetImage("Bag_Items.bmp");
		LeftArrow->Off();
		break;
	case BagSpace::KeyItems:
		BagRender->SetFrame(1);
		SpaceText->SetImage("Bag_KeyItems.bmp");
		LeftArrow->On();
		RightArrow->On();
		break;
	case BagSpace::PokeBalls:
		BagRender->SetFrame(2);
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

void BagUI::CursorUp()
{
	if (0 >= CurrentCursor)
	{
		CurrentCursor = 0;
		return;
	}
	CurrentCursor--;
	ItemName[CurrentCursor]->SetText(Items[CurrentCursor].Name);
	ItemInfo->SetText(Items[CurrentCursor].Information, "Font_Dialog_White.bmp", false);
	IconRender->SetFrame(Items[CurrentCursor].ItemCode);
}

void BagUI::CursorDown()
{
	if (Items.size() <= ++CurrentCursor)
	{
		CurrentCursor = Items.size() - 1;
		return;
	}
	ItemName[CurrentCursor]->SetText(Items[CurrentCursor].Name);
	ItemInfo->SetText(Items[CurrentCursor].Information, "Font_Dialog_White.bmp", false);
	IconRender->SetFrame(Items[CurrentCursor].ItemCode);
}
