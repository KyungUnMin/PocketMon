#include "PlayerBag.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TextActor.h"
#include "PocketMonCore.h"
#include "PokemonUI.h"
#include "ContentsEnum.h"
PlayerBag* PlayerBag::MainBag = nullptr;

PlayerBag::PlayerBag() {
}

PlayerBag::~PlayerBag() {
}

void PlayerBag::AddItem(ItemCode _ItemCode)
{
	for (size_t i = 0; i < Items.size(); i++)
	{
		if (Items[i].GetItemCode() == _ItemCode)
		{
			Items[i].AddNum(1);
			return;
		}
	}
	for (size_t i = 0; i < PokeBalls.size(); i++)
	{
		if (PokeBalls[i].GetItemCode() == _ItemCode)
		{
			PokeBalls[i].AddNum(1);
			return;
		}
	}

	if (_ItemCode < ItemCode::Bike)
	{
		Items.insert(Items.begin(), Item::GetItem(_ItemCode));
	}
	else if (_ItemCode == ItemCode::Bike)
	{
		KeyItems.insert(KeyItems.begin(), Item::GetItem(_ItemCode));
	}
	else
	{
		PokeBalls.insert(PokeBalls.begin(), Item::GetItem(_ItemCode));
	}
}


void PlayerBag::RemoveItem(ItemCode _ItemCode)
{
	for (size_t i = 0; i < Items.size(); i++)
	{
		if (Items[i].GetItemCode() == _ItemCode)
		{
			Items[i].AddNum(-1);
			if (0 >= Items[i].GetNum())
			{
				Items.erase(Items.begin() + i);
				int a = 0;
			}
			return;
		}
	}
	for (size_t i = 0; i < PokeBalls.size(); i++)
	{
		if (PokeBalls[i].GetItemCode() == _ItemCode)
		{
			Items[i].AddNum(-1);
			if (0 >= PokeBalls[i].GetNum())
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
		Items.push_back(Item::GetItem(ItemCode::Cancel));
		KeyItems.reserve(2);
		KeyItems.push_back(Item::GetItem(ItemCode::Bike));
		KeyItems.push_back(Item::GetItem(ItemCode::Cancel));
		PokeBalls.reserve(5);
		PokeBalls.push_back(Item::GetItem(ItemCode::Cancel));
	}
	// ������ġ ����
	ChangeSpace(BagSpace::Items);
}

void PlayerBag::Update(float _DeltaTime)
{
	TimeEvent.Update(_DeltaTime);
	switch (AnimState)
	{
	case BagAnim::Idle:
		break;
	case BagAnim::LeftTurn:
		BagRender->SetAngleAdd(-500 * _DeltaTime);
		break;
	case BagAnim::RightTurn:
		BagRender->SetAngleAdd(500 * _DeltaTime);
		break;
	case BagAnim::UpMove:
		BagRender->SetMove(float4::Up * 250 * _DeltaTime);
		break;
	case BagAnim::DownMove:
		BagRender->SetMove(float4::Down * 250 * _DeltaTime);
		break;
	default:
		break;
	}

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
	if (_PrevLevel->GetName() != "PokemonLevel")
	{
		PrevLevel = _PrevLevel;
	}
	if (PrevLevel->GetName() == "BattleLevel")
	{
		IsBattle = true;
	}
	SelectOff();
	ChangeSpace(BagSpace::Items);
	CursorMove(0);
}

void PlayerBag::ChangeAnimation(BagAnim _AnimState)
{
	AnimState = _AnimState;
	if (AnimState == BagAnim::Idle)
	{
		BagRender->SetAngle(0);
		BagRender->SetPosition({ 168, 276 });
	}
	else if (AnimState == BagAnim::LeftTurn)
	{
		BagRender->SetAngle(0);
		BagRender->SetPosition({ 168, 276 });
		// Ÿ���̺�Ʈ
		TimeEvent.AddEvent(0.03f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::RightTurn), false);
		TimeEvent.AddEvent(0.06f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::Idle), false);
	}
	else if (AnimState == BagAnim::UpMove)
	{
		BagRender->SetAngle(0);
		BagRender->SetPosition({ 168, 276 });
		// Ÿ�� �̺�Ʈ
		TimeEvent.AddEvent(0.07f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::DownMove), false);
		TimeEvent.AddEvent(0.14f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::Idle), false);
	}
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
		ItemName[i]->SetText(CurrentSpaceItems[i].GetItemName());
		if (CurrentSpaceItems[i].GetItemCode() == ItemCode::Cancel)
		{
			ItemNumSign[i]->Off();
			ItemNum[i]->Clear();
			break;
		}
		ItemNumSign[i]->On();
		ItemNum[i]->SetText(std::to_string(CurrentSpaceItems[i].GetNum()));
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
		return;
	case BagSpace::KeyItems:
		ChangeSpace(BagSpace::Items);
		break;
	case BagSpace::PokeBalls:
		ChangeSpace(BagSpace::KeyItems);
		break;
	default:
		return;
	}

	ChangeAnimation(BagAnim::UpMove);
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
		return;
	default:
		return;
	}

	ChangeAnimation(BagAnim::UpMove);
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

	ChangeAnimation(BagAnim::LeftTurn);
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

	ChangeAnimation(BagAnim::LeftTurn);
}

void PlayerBag::CursorMove()
{
	if (CurrentSpace == BagSpace::Items)
	{
		if (CurrentCursor >= Items.size())
		{
			return;
		}
		ItemInfo->SetText(Items[CurrentCursor].GetItemExplanation(), "Font_Dialog_White.bmp", 2, false);
		IconRender->SetFrame(Items[CurrentCursor].GetItemCodeInt());
	}
	else if (CurrentSpace == BagSpace::KeyItems)
	{
		if (CurrentCursor >= KeyItems.size())
		{
			return;
		}
		ItemInfo->SetText(KeyItems[CurrentCursor].GetItemExplanation(), "Font_Dialog_White.bmp", 2, false);
		IconRender->SetFrame(KeyItems[CurrentCursor].GetItemCodeInt());
	}
	else if (CurrentSpace == BagSpace::PokeBalls)
	{
		if (CurrentCursor >= PokeBalls.size())
		{
			return;
		}
		ItemInfo->SetText(PokeBalls[CurrentCursor].GetItemExplanation(), "Font_Dialog_White.bmp",2, false);
		IconRender->SetFrame(PokeBalls[CurrentCursor].GetItemCodeInt());
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
	CurrentItemCode = CurrentSpaceItems[CurrentCursor].GetItemCode();
	if (CurrentItemCode == ItemCode::Cancel)
	{
		Cancel();
		return;
	}

	ItemInfo->Off();
	TextBox->On();
	SelectBox->On();
	ItemSelectText->SetText(CurrentSpaceItems[CurrentCursor].GetItemName().data() + std::string(" is\nselected."));
	ItemSelectText->On();
	SelectText->On();
	SelectCursorRender->On();
	CursorRender->SetFrame(1);
	IsItemSelect = true;

	// ���� �� �϶�
	if (true == IsBattle)
	{
		if (true == CurrentSpaceItems[CurrentCursor].IsBattleuse())
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
		PokemonUI::MainPokemon->SetState_ItemUse(CurrentItemCode);
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
		break;
	case BagSpace::KeyItems:
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		break;
	case BagSpace::PokeBalls:
		RemoveItem(CurrentItemCode);
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		break;
	default:
		break;
	}
}
void PlayerBag::ItemGive()
{
	// ���ϸ� ������
	PokemonUI::MainPokemon->SetState_ItemGive(CurrentItemCode);
	PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
}
void PlayerBag::Cancel()
{
	CurrentItemCode = ItemCode::Cancel;
	PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
}
