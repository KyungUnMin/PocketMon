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
		Items.insert(Items.begin(), Item("POTION", "A sparytype wound medicine\nIt restores the HP of one\nPoK@Mon by 20 points.", _ItemCode, true));
		break;
	case 11:
		Items.insert(Items.begin(), Item("Candy", "good", _ItemCode, false));
		break;
	case 25:
		PokeBalls.insert(PokeBalls.begin(), Item("POK@ BALL", "A BALL thrown to catch a wild\nPOK@MON It is designed in a\ncapsule style", _ItemCode, true));
		break;
	case 26:
		PokeBalls.insert(PokeBalls.begin(), Item("GREAT BALL", "A good quality BALL that offers a higher POK@MON catch rate than a standard POK@ BALL", _ItemCode, true));
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
			if (0 >= --PokeBalls[i].Num)
			{
				PokeBalls.erase(PokeBalls.begin() + i);
			}
			return;
		}
	}
}

void PlayerBag::BattleOn()
{
	IsBattle = true;
}

void PlayerBag::Start()
{
	// �̱���
	if (MainBag != nullptr)
	{
		MsgAssert("������ 2�� �����Ǿ����ϴ�");
	}
	MainBag = this;
	// ____________���� ����______________
	{
		GameEngineRender* BackUI = CreateRender("Bag_Back.bmp", 0);
		BackUI->SetScaleToImage();
		BackUI->SetPosition(BackUI->GetScale().half());

		BagRender = CreateRender("Bag.bmp", 2);
		BagRender->SetRotFilter("Bag_Roll.bmp");
		BagRender->SetScale({232, 252});
		BagRender->SetPosition({ 168, 276 });
		BagRender->SetFrame(0);

		GameEngineRender* BackShadow = CreateRender("Bag_Shadow.bmp", 1);
		BackShadow->SetScaleToImage();
		BackShadow->SetPosition({ 168, 276 });

		SpaceText = CreateRender("Bag_SpaceText.bmp", 1);
		SpaceText->SetScale({308,116});
		SpaceText->SetPosition({ 168, 62 });

		IconRender = CreateRender("Items.bmp", 1);
		IconRender->SetScale({ 128,128 });
		IconRender->SetPosition({ 80, 550 });

		RightArrow = CreateRender("Bag_RightArrow.bmp", 1);
		RightArrow->SetScaleToImage();
		RightArrow->SetPosition({ 300, 280 });

		LeftArrow = CreateRender("Bag_LeftArrow.bmp", 1);
		LeftArrow->SetScaleToImage();
		LeftArrow->SetPosition({ 28, 280 });

		UpArrow = CreateRender("Bag_UpArrow.bmp", 1);
		UpArrow->SetScaleToImage();
		UpArrow->Off();

		DownArrow = CreateRender("Bag_DownArrow.bmp", 1);
		DownArrow->SetScaleToImage();
		DownArrow->SetPosition({ 644, 424 });
		DownArrow->Off();

		CursorRender = CreateRender("Bag_CurrentArrow.bmp", 1);
		CursorRender->SetScale({24, 40});
		CursorRender->SetFrame(0);
		CursorRender->SetPosition({ 372, 68 });

		TextBox = CreateRender("TextBox.bmp", 3);
		TextBox->SetScaleToImage();
		TextBox->SetPosition({408, 544});
		TextBox->Off();

		SelectBox = CreateRender("SelectMenu.bmp", 3);
		SelectBox->SetScale({280, 376});
		SelectBox->SetPosition({ 814, 444 });
		SelectBox->SetFrame(3);
		SelectBox->Off();

		SelectCursorRender = CreateRender("Bag_CurrentArrow.bmp", 4);
		SelectCursorRender->SetScale({ 24, 40 });
		SelectCursorRender->SetFrame(0);
		SelectCursorRender->SetPosition({ 712, 580 });
		SelectCursorRender->Off();
	}

	// �ؽ�Ʈ ���� ����
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
	ItemSelectText = BagLevel->CreateActor<TextActor>();
	ItemSelectText->SetPos({ 212, 518 });
	SelectText = BagLevel->CreateActor<TextActor>();
	
	SelectText->SetInterver({ 0, 20 });
	SelectText->SetLine(4);
	SelectText->Off();

	// ������ ����
	{
		Items.reserve(5);
		Items.push_back(Item("CANCEL", "CLOSE BAG", 29, true));
		KeyItems.reserve(2);
		KeyItems.push_back(Item("BIKE", "Bike Information", 24, false));
		KeyItems.push_back(Item("CANCEL", "CLOSE BAG", 29, true));
		PokeBalls.reserve(5);
		PokeBalls.push_back(Item("CANCEL", "CLOSE BAG", 29, true));
	}
	// ������ġ ����
	ChangeSpace(BagSpace::Items);
}

void PlayerBag::Update(float _DeltaTime)
{
	GetLevel()->DebugTextPush("1 : ������ ����");
	GetLevel()->DebugTextPush("2 : ��Ʋ���·� ����");
	if (true == IsBattle)
	{
		GetLevel()->DebugTextPush("��Ʋ��");
	}
	// ������ ����
	if (true == IsItemSelect)
	{
		if (GameEngineInput::IsDown("UpMove"))
		{
			SelectUp();
			return;
		}
		if (GameEngineInput::IsDown("DownMove"))
		{
			SelectDown();
			return;
		}
		if (GameEngineInput::IsDown("A"))
		{
			SelectMenu();
			return;
		}
		if (GameEngineInput::IsDown("B"))
		{
			SelectOff();
			return;
		}

		return;
	}

	// ���� ����
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
		SelectOn();
		return;
	}
	if (GameEngineInput::IsDown("B"))
	{
		Cancel();
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
	SelectOff();
	ChangeSpace(BagSpace::Items);
	CursorMove(0);
}

void PlayerBag::ChangeSpace(BagSpace _Space)
{
	// ������ ������ �̵��Ѵ� (ī�װ� ����)
	// 1. ����, 2. �߿��ѹ���, 3. ��
	CurrentSpace = _Space;
	// �̵��� ���� ���� �������� ����
	switch (CurrentSpace)
	{
	case BagSpace::Items:
		BagRender->SetFrame(0);
		SpaceText->SetFrame(0);
		LeftArrow->Off();
		break;
	case BagSpace::KeyItems:
		BagRender->SetFrame(1);
		SpaceText->SetFrame(1);
		LeftArrow->On();
		RightArrow->On();
		break;
	case BagSpace::PokeBalls:
		BagRender->SetFrame(2);
		SpaceText->SetFrame(2);
		RightArrow->Off();
		break;
	default:
		break;
	}

	//______ �ش� ī�װ��� �´� �����۵��� ����_______
	std::vector<Item>& CurrentSpaceItems = CurrentSpace == BagSpace::Items ? Items : (CurrentSpace == BagSpace::KeyItems ? KeyItems : PokeBalls);
	for (int i = 0; i < CurrentSpaceItems.size(); i++)
	{
		ItemName[i]->SetText(CurrentSpaceItems[i].Name);
		if (CurrentSpaceItems[i].ItemCode == CancelCode)
		{
			ItemNumSign[i]->Off();
			ItemNum[i]->Clear();
			break;
		}
		ItemNumSign[i]->On();
		ItemNum[i]->SetText(std::to_string(CurrentSpaceItems[i].Num));
	}
	// ���� ������ ������ ����
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
	// ������ ���� �������� �̵�
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
	// ������ ������ �������� �̵�
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
		ItemInfo->SetText(Items[CurrentCursor].Information, "Font_Dialog_White.bmp", 2, false);
		IconRender->SetFrame(Items[CurrentCursor].ItemCode);
	}
	else if (CurrentSpace == BagSpace::KeyItems)
	{
		if (CurrentCursor >= KeyItems.size())
		{
			return;
		}
		ItemInfo->SetText(KeyItems[CurrentCursor].Information, "Font_Dialog_White.bmp",2, false);
		IconRender->SetFrame(KeyItems[CurrentCursor].ItemCode);
	}
	else if (CurrentSpace == BagSpace::PokeBalls)
	{
		if (CurrentCursor >= PokeBalls.size())
		{
			return;
		}
		ItemInfo->SetText(PokeBalls[CurrentCursor].Information, "Font_Dialog_White.bmp",2, false);
		IconRender->SetFrame(PokeBalls[CurrentCursor].ItemCode);
	}
	CursorRender->SetPosition({ 372, 68.0f + 64 * CurrentCursor });
}

void PlayerBag::CursorMove(int _Cursor)
{
	CurrentCursor = _Cursor;
	CursorMove();
}


void PlayerBag::SelectOn()
{
	std::vector<Item>& CurrentSpaceItems = CurrentSpace == BagSpace::Items ? Items : (CurrentSpace == BagSpace::KeyItems ? KeyItems : PokeBalls);
	ItemCode = CurrentSpaceItems[CurrentCursor].ItemCode;
	if (ItemCode == CancelCode)
	{
		Cancel();
		return;
	}

	ItemInfo->Off();
	TextBox->On();
	SelectBox->On();
	ItemSelectText->SetText(CurrentSpaceItems[CurrentCursor].Name.data() + std::string(" is\nselected."));
	ItemSelectText->On();
	SelectText->On();
	SelectCursorRender->On();
	CursorRender->SetFrame(1);
	IsItemSelect = true;

	// ���� �� �϶�
	if (true == IsBattle)
	{
		if (true == CurrentSpaceItems[CurrentCursor].IsBattleItem)
		{
			SelectText->SetText("USE\nCANCEL");
			SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
			SelectFunctions[1] = std::bind(&PlayerBag::ItemUse, this);
			SelectSize = 1;
		}
		else
		{
			SelectText->SetText("CANCEL");
			SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
			SelectSize = 0;
		}
	}
	else
	{
		switch (CurrentSpace)
		{
		case BagSpace::Items:
			SelectText->SetText("USE\nGIVE\nCANCEL");
			SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
			SelectFunctions[1] = std::bind(&PlayerBag::ItemGive, this);
			SelectFunctions[2] = std::bind(&PlayerBag::ItemUse, this);
			SelectSize = 2;
			break;
		case BagSpace::KeyItems:
			SelectText->SetText("USE\nCANCEL");
			SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
			SelectFunctions[1] = std::bind(&PlayerBag::ItemUse, this);
			SelectSize = 1;
			break;
		case BagSpace::PokeBalls:
			SelectText->SetText("GIVE\nCANCEL");
			SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
			SelectFunctions[1] = std::bind(&PlayerBag::ItemGive, this);
			SelectSize = 1;
			break;
		default:
			break;
		}
	}
	
	CurrentSelectCursor = SelectSize;
	SelectText->SetPos({ 744, 580.0f - 68 * SelectSize });
	SelectCursorRender->SetPosition({ 712, 580.0f - 68 * SelectSize });
	SelectBox->SetFrame(SelectSize);
}

void PlayerBag::SelectOff()
{
	ItemInfo->On();
	TextBox->Off();
	SelectBox->Off();
	ItemSelectText->Off();
	SelectCursorRender->Off();
	SelectText->Off();
	CursorRender->SetFrame(0);
	IsItemSelect = false;
}

void PlayerBag::SelectUp()
{
	if (SelectSize <= CurrentSelectCursor)
	{
		return;
	}
	CurrentSelectCursor++;
	SelectMove();
}

void PlayerBag::SelectDown()
{
	if (0 >= CurrentSelectCursor)
	{
		return;
	}
	CurrentSelectCursor--;
	SelectMove();
}

void PlayerBag::SelectMove()
{
	SelectCursorRender->SetPosition({ 712, 580.0f - 68 * CurrentSelectCursor });
}

void PlayerBag::SelectMenu()
{
	SelectFunctions[CurrentSelectCursor]();
}

void PlayerBag::ItemUse()
{
	switch (CurrentSpace)
	{
	case BagSpace::Items:
		// ���ϸ� ������
		break;
	case BagSpace::KeyItems:
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		break;
	case BagSpace::PokeBalls:
		RemoveItem(ItemCode);
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		break;
	default:
		break;
	}
}
void PlayerBag::ItemGive()
{
}
void PlayerBag::Cancel()
{
	ItemCode = CancelCode;
	PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
}
