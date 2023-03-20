#include "PlayerBag.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TextActor.h"
#include "PocketMonCore.h"
#include "ContentsEnum.h"
PlayerBag* PlayerBag::MainBag = nullptr;

PlayerBag::PlayerBag() {
}

PlayerBag::~PlayerBag() {

}

void PlayerBag::AddItem(int _ItemCode)
{
	for (size_t i = 0; i < Items.size(); i++)
	{
		if (Items[i].ItemCode == _ItemCode)
		{
			Items[i].Num++;
			return;
		}
	}
	for (size_t i = 0; i < PokeBalls.size(); i++)
	{
		if (PokeBalls[i].ItemCode == _ItemCode)
		{
			PokeBalls[i].Num++;
			return;
		}
	}
	switch (_ItemCode)
	{
	case 0:
		Items.insert(Items.begin(), Item("POTION", "A sparytype wound medicine\nIt restores the HP of one\nPoKMon by 20 points", _ItemCode));
		break;
	case 11:
		Items.insert(Items.begin(), Item("Candy", "good", _ItemCode));
		break;
	case 25:
		PokeBalls.insert(PokeBalls.begin(), Item("POKe BALL", "A BALL thrown to catch a wild\nPOKeMON It is designed in a\ncapsule style", _ItemCode));
		break;
	case 26:
		PokeBalls.insert(PokeBalls.begin(), Item("GREAT BALL", "A good quality BALL that offers a higher POKeMON catch rate than a standard POKe BALL", _ItemCode));
		break;
	default:
		break;
	}
}

void PlayerBag::RemoveItem(int _ItemCode)
{
	for (size_t i = 0; i < Items.size(); i++)
	{
		if (Items[i].ItemCode == _ItemCode)
		{
			
			if (0 >= --Items[i].Num)
			{
				Items.erase(Items.begin() + i);
				int a = 0;
			}
			return;
		}
	}
	for (size_t i = 0; i < PokeBalls.size(); i++)
	{
		if (PokeBalls[i].ItemCode == _ItemCode)
		{
			if (0 >= --Items[i].Num)
			{
				PokeBalls.erase(Items.begin() + i);
			}
			return;
		}
	}
}

void PlayerBag::Start()
{
	// 싱글톤
	if (MainBag != nullptr)
	{
		MsgAssert("가방이 2개 생성되었습니다");
	}
	MainBag = this;
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
		UpArrow->Off();

		DownArrow = CreateRender("Bag_DownArrow.bmp", RenderOrder::Player);
		DownArrow->SetScaleToImage();
		DownArrow->SetPosition({ 644, 424 });
		DownArrow->Off();

		CursorRender = CreateRender("Bag_CurrentArrow.bmp", RenderOrder::Player);
		CursorRender->SetScaleToImage();
		CursorRender->SetPosition({ 372, 68 });
	}

	// 텍스트 엑터 생성
	GameEngineLevel* BagLevel = GetLevel();
	for (int i = 0; i < ItemName.size(); i++)
	{
		ItemName[i] = BagLevel->CreateActor<TextActor>();
		ItemName[i]->SetPos({ 404, 72.0f + 64 * i });
		ItemNum[i] = BagLevel->CreateActor<TextActor>();
		ItemNum[i]->SetAligned(true);
		ItemNum[i]->SetPos({ 880, 70.0f + 64 * i });
		ItemNumSign[i] = BagLevel->CreateActor<TextActor>();
		ItemNumSign[i]->SetText("x");
		ItemNumSign[i]->SetPos({ 792, 68.0f + 64 * i });
	}
	ItemInfo = BagLevel->CreateActor<TextActor>();
	ItemInfo->SetPos({ 172, 488 });

	// 아이템 생성
	{
		Items.reserve(5);
		//Items.push_back(Item("POTION", "A spary type wound medicine It restores the Hp of one POKEMON by 200 points", 1, 0));
		//Items.push_back(Item("POTION", "A spary type wound medicine It restores the Hp of one POKEMON by 200 points", 2, 0));
		Items.push_back(Item("CANCEL", "CLOSE BAG", 29));
		KeyItems.reserve(2);
		KeyItems.push_back(Item("BIKE", "Bike Information", 24));
		KeyItems.push_back(Item("CANCEL", "CLOSE BAG", 29));
		PokeBalls.reserve(5);
		PokeBalls.push_back(Item("CANCEL", "CLOSE BAG", 29));
	}
	// 가방위치 지정
	ChangeSpace(BagSpace::Items);
}

void PlayerBag::Update(float _DeltaTime)
{
	// 가방 조작
	if (GameEngineInput::IsDown("LeftMove"))
	{
		ChangeSpaceLeft();
		return;
	}
	if (GameEngineInput::IsDown("RightMove"))
	{
		ChangeSpaceRight();
		return;
	}
	if (GameEngineInput::IsDown("UpMove"))
	{
		CursorUp();
		return;
	}
	if (GameEngineInput::IsDown("DownMove"))
	{
		CursorDown();
		return;
	}
	if (GameEngineInput::IsDown("A"))
	{
		ItemSelect();
		return;
	}
	if (GameEngineInput::IsDown("B"))
	{
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		return;
	}

}

void PlayerBag::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
	
}

void PlayerBag::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	PrevLevel = _PrevLevel;
	if (PrevLevel->GetName() == "BattleLevel")
	{
		IsBattle = true;
	}
	ChangeSpace(BagSpace::Items);
	CursorMove(0);
}

void PlayerBag::ChangeSpace(BagSpace _Space)
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

	//______ 해당 카테고리에 맞는 아이템들을 나열_______
	std::vector<Item>& CurrentSpaceItems = CurrentSpace == BagSpace::Items ? Items : (CurrentSpace == BagSpace::KeyItems ? KeyItems : PokeBalls);
	for (int i = 0; i < CurrentSpaceItems.size(); i++)
	{
		ItemName[i]->SetText(CurrentSpaceItems[i].Name);
		if (CurrentSpaceItems[i].Num == -1)
		{
			ItemNumSign[i]->Off();
			ItemNum[i]->Clear();
			break;
		}
		ItemNumSign[i]->On();
		ItemNum[i]->SetText(std::to_string(CurrentSpaceItems[i].Num));
	}
	// 남은 공간이 있으면 지움
	for (size_t i = CurrentSpaceItems.size(); i < ItemName.size(); i++)
	{
		ItemName[i]->Clear();
		ItemNum[i]->Clear();
		ItemNumSign[i]->Off();
	}
	CursorMove(0);
}

void PlayerBag::ChangeSpaceLeft()
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

void PlayerBag::ChangeSpaceRight()
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

void PlayerBag::CursorUp()
{
	if (0 >= CurrentCursor)
	{
		CurrentCursor = 0;
		return;
	}
	CurrentCursor--;
	CursorMove();
}

void PlayerBag::CursorDown()
{
	std::vector<Item>& CurrentSpaceItems = CurrentSpace == BagSpace::Items ? Items : (CurrentSpace == BagSpace::KeyItems ? KeyItems : PokeBalls);
	if (CurrentSpaceItems.size() <= ++CurrentCursor)
	{
		CurrentCursor = CurrentSpaceItems.size() - 1;
		return;
	}
	CursorMove();
}

void PlayerBag::CursorMove()
{
	if (CurrentSpace == BagSpace::Items)
	{
		if (CurrentCursor >= Items.size())
		{
			return;
		}
		ItemInfo->SetText(Items[CurrentCursor].Information, "Font_Dialog_White.bmp", false);
		IconRender->SetFrame(Items[CurrentCursor].ItemCode);
	}
	else if (CurrentSpace == BagSpace::KeyItems)
	{
		if (CurrentCursor >= KeyItems.size())
		{
			return;
		}
		ItemInfo->SetText(KeyItems[CurrentCursor].Information, "Font_Dialog_White.bmp", false);
		IconRender->SetFrame(KeyItems[CurrentCursor].ItemCode);
	}
	else if (CurrentSpace == BagSpace::PokeBalls)
	{
		if (CurrentCursor >= PokeBalls.size())
		{
			return;
		}
		ItemInfo->SetText(PokeBalls[CurrentCursor].Information, "Font_Dialog_White.bmp", false);
		IconRender->SetFrame(PokeBalls[CurrentCursor].ItemCode);
	}
	CursorRender->SetPosition({ 372, 68.0f + 64 * CurrentCursor });
}

void PlayerBag::CursorMove(int _Cursor)
{
	CurrentCursor = _Cursor;
	CursorMove();
}

void PlayerBag::ItemSelect()
{
	std::vector<Item>& CurrentSpaceItems = CurrentSpace == BagSpace::Items ? Items : (CurrentSpace == BagSpace::KeyItems ? KeyItems : PokeBalls);
	ItemCode = CurrentSpaceItems[CurrentCursor].ItemCode;

	if (ItemCode == 27)
	{
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		return;
	}
	if (true == IsBattle && CurrentSpace == BagSpace::KeyItems)
	{
		return;
	}
	if (false == IsBattle && CurrentSpace == BagSpace::PokeBalls)
	{
		return;
	}

	if (CurrentSpace == BagSpace::PokeBalls)
	{
		CurrentSpaceItems[CurrentCursor].Num--;
	}
	PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
}
