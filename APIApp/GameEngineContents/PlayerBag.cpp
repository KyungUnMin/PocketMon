#include "PlayerBag.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TextActor.h"
#include "PokemonUI.h"
#include "ContentsEnum.h"
#include "Player.h"
#include "LevelChangeFade.h"
#include "BattleLevel.h"
#include <GameEngineCore/GameEngineResources.h>
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


void PlayerBag::AddItem(ItemCode _ItemCode, int _Num)
{
	for (size_t i = 0; i < Items.size(); i++)
	{
		if (Items[i].GetItemCode() == _ItemCode)
		{
			Items[i].AddNum(_Num);
			return;
		}
	}
	for (size_t i = 0; i < PokeBalls.size(); i++)
	{
		if (PokeBalls[i].GetItemCode() == _ItemCode)
		{
			PokeBalls[i].AddNum(_Num);
			return;
		}
	}

	Item NewItem = Item::GetItem(_ItemCode);
	NewItem.AddNum(_Num - 1);

	if (_ItemCode < ItemCode::Bike)
	{
		Items.insert(Items.begin(), NewItem);
	}
	else if (_ItemCode == ItemCode::Bike)
	{
		KeyItems.insert(KeyItems.begin(), NewItem);
	}
	else
	{
		PokeBalls.insert(PokeBalls.begin(), NewItem);
	}
}

void PlayerBag::RemoveItem(ItemCode _ItemCode)
{
	if (_ItemCode < ItemCode::Bike)
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
	}
	for (size_t i = 0; i < PokeBalls.size(); i++)
	{
		if (PokeBalls[i].GetItemCode() == _ItemCode)
		{
			PokeBalls[i].AddNum(-1);
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
	// 싱글톤
	if (MainBag != nullptr)
	{
		MsgAssert("가방이 2개 생성되었습니다");
	}
	MainBag = this;
	// ____________렌더 생성______________
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
	ItemSelectText = BagLevel->CreateActor<TextActor>();
	ItemSelectText->SetPos({ 212, 518 });
	SelectText = BagLevel->CreateActor<TextActor>();
	
	SelectText->SetInterver({ 0, 20 });
	SelectText->SetLine(4);
	SelectText->Off();

	// 아이템 생성
	{
		Items.reserve(5);
		Items.push_back(Item::GetItem(ItemCode::Cancel));
		KeyItems.reserve(2);
		KeyItems.push_back(Item::GetItem(ItemCode::Bike));
		KeyItems.push_back(Item::GetItem(ItemCode::Cancel));
		PokeBalls.reserve(5);
		PokeBalls.push_back(Item::GetItem(ItemCode::Cancel));
	}
	// 가방위치 지정
	ChangeSpace(BagSpace::Items);
}

void PlayerBag::Update(float _DeltaTime)
{
	if (IsStop == true) { return; }
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

	// 아이템 조작
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
	IsStop = false;
	if (_PrevLevel->GetName() == "PokemonLevel")
	{
		SelectOff();
		ChangeSpace(CurrentSpace);
		return;
	}
	else
	{
		PrevLevel = _PrevLevel;
		if (PrevLevel->GetName() == "FieldmapLevel")
		{
			IsBattle = false;
		}
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
		// 타임이벤트
		TimeEvent.AddEvent(0.03f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::RightTurn), false);
		TimeEvent.AddEvent(0.06f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::Idle), false);
	}
	else if (AnimState == BagAnim::UpMove)
	{
		BagRender->SetAngle(0);
		BagRender->SetPosition({ 168, 276 });
		// 타임 이벤트
		TimeEvent.AddEvent(0.07f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::DownMove), false);
		TimeEvent.AddEvent(0.14f, std::bind(&PlayerBag::ChangeAnimation, this, BagAnim::Idle), false);
	}
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

	//______ 해당 카테고리에 맞는 아이템들을 나열_______
	std::vector<Item>& CurrentSpaceItems = CurrentSpace == BagSpace::Items ? Items : (CurrentSpace == BagSpace::KeyItems ? KeyItems : PokeBalls);
	
	size_t ItemCount = CurrentSpaceItems.size();

	if (ItemCount > ItemName.size())
	{
		ItemCount = ItemName.size();
	}

	for (int i = 0; i < ItemCount; i++)
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

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);

	ChangeAnimation(BagAnim::UpMove);
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
		return;
	default:
		return;
	}

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);

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

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);

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

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);

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

	// 전투 중 일때
	if (true == IsBattle)
	{
		if (true == CurrentSpaceItems[CurrentCursor].IsBattleuse())
		{
			if (CurrentSpace == BagSpace::PokeBalls) {
				if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
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
				SelectText->SetText("USE\nCANCEL");
				SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
				SelectFunctions[1] = std::bind(&PlayerBag::ItemUse, this);
				SelectSize = 1;
			}
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
		{
			if (CurrentSpaceItems[CurrentCursor].GetItemCode() <= ItemCode::Ether)
			{
				SelectText->SetText("USE\nGIVE\nCANCEL");
				SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
				SelectFunctions[1] = std::bind(&PlayerBag::ItemGive, this);
				SelectFunctions[2] = std::bind(&PlayerBag::ItemUse, this);
				SelectSize = 2;
			}
			else
			{
				SelectText->SetText("GIVE\nCANCEL");
				SelectFunctions[0] = std::bind(&PlayerBag::SelectOff, this);
				SelectFunctions[1] = std::bind(&PlayerBag::ItemGive, this);
				SelectSize = 1;
			}
			break;
		}
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

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
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

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);
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
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
}

void PlayerBag::SelectMenu()
{
	SelectFunctions[CurrentSelectCursor]();
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
}

void PlayerBag::ItemUse()
{
	switch (CurrentSpace)
	{
	case BagSpace::Items:
		// 포켓몬 레벨로
		PokemonUI::MainPokemon->SetState_ItemUse(CurrentItemCode);
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut("PokemonLevel");
		IsStop = true;
		break;
	case BagSpace::KeyItems:
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut(PrevLevel->GetName());
		IsStop = true;
		Player::MainPlayer->SetRideValue(!Player::MainPlayer->GetIsRideValue());
		break;
	case BagSpace::PokeBalls:
		RemoveItem(CurrentItemCode);
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut(PrevLevel->GetName());
		BattleLevel::BattleLevelPtr->UseMonsterBall(CurrentItemCode);
		IsStop = true;
		break;
	default:
		break;
	}
}
void PlayerBag::ItemGive()
{
	// 포켓몬 레벨로
	PokemonUI::MainPokemon->SetState_ItemGive(CurrentItemCode);
	LevelChangeFade::MainLevelFade->LevelChangeFadeOut("PokemonLevel");
	IsStop = true;
}
void PlayerBag::Cancel()
{
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);
	CurrentItemCode = ItemCode::Cancel;
	LevelChangeFade::MainLevelFade->LevelChangeFadeOut(PrevLevel->GetName());
	IsStop = true;
}
