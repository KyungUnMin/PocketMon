#include "PokemonUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "PokeDataBase.h"
#include "PlayerBag.h"
#include "TextActor.h"
#include "LevelChangeFade.h"
#include "PokemonHPBar.h"
#include "BattleLevel.h"
#include "Player.h"
#include "FriendlyHPBackground.h"
PokemonUI* PokemonUI::MainPokemon = nullptr;

PokemonUI::PokemonUI() 
{
}

PokemonUI::~PokemonUI() 
{
}

void PokemonUI::SetState_ItemUse(ItemCode _ItemCode)
{
	StateValue = PokemonUIState::Potion;
	CurrentItemCode = _ItemCode;
}
void PokemonUI::SetState_ItemGive(ItemCode _ItemCode)
{
	StateValue = PokemonUIState::Give;
	CurrentItemCode = _ItemCode;
}
void PokemonUI::SetState_Shift()
{
	StateValue = PokemonUIState::Shift;
}


void PokemonUI::Start()
{
	CurrentLevel = GetLevel();
	MainPokemon = this;

	// ____________렌더 생성______________
	{

		GameEngineRender* BackUI = CreateRender("PokemonUI_Back.bmp", 0);
		BackUI->SetScaleToImage();
		BackUI->SetPosition(BackUI->GetScale().half());

		// 포켓몬 뒷 배경
		PokemonBack[0] = CreateRender("MainPokemon.bmp", 1);
		PokemonBack[0]->SetScale({ 336, 228 });
		PokemonBack[0]->SetPosition({ 172, 196 });
		// 포켓몬 이미지
		PokemonRender[0] = CreateRender(2);
		PokemonRender[0]->SetPosition({ 52, 172 });

		// 지닌 물건
		PokemonItem[0] = CreateRender("PokemonItem.bmp", 2);
		PokemonItem[0]->SetScaleToImage();
		PokemonItem[0]->SetPosition({ 72, 206 });

		// 포켓몬 이름
		PokemonNameText[0] = CurrentLevel->CreateActor<TextActor>();
		PokemonNameText[0]->SetPos({ 108, 172 });

		// 포켓몬 레벨
		PokemonLevelText[0] = CurrentLevel->CreateActor<TextActor>();
		PokemonLevelText[0]->SetPos({ 212, 212 });

		// 포켓몬 HP
		PokemonCurrentHPText[0] = CurrentLevel->CreateActor<TextActor>();
		PokemonCurrentHPText[0]->SetPos({ 218, 282 });
		PokemonCurrentHPText[0]->SetAligned(true);
		// 포켓몬 최대 HP
		PokemonMaxHPText[0] = CurrentLevel->CreateActor<TextActor>();
		PokemonMaxHPText[0]->SetPos({ 326, 282 });
		PokemonMaxHPText[0]->SetAligned(true);

		PokemonHPBars[0] = CurrentLevel->CreateActor<PokemonHPBar>();
		PokemonHPBars[0]->SetPos({124, 256});

		for (int i = 1; i < 6; i++)
		{
			// 포켓몬 뒷 배경
			PokemonBack[i] = CreateRender("SubPokemon.bmp", 1);
			PokemonBack[i]->SetScale({ 600, 96 });
			PokemonBack[i]->SetPosition({ 652, -12.0f + 96 * i });

			// 포켓몬 이미지
			PokemonRender[i] = CreateRender(2);
			PokemonRender[i]->SetPosition({ 408, 2.0f + 96 * i });

			// 지닌 물건
			PokemonItem[i] = CreateRender("PokemonItem.bmp", 2);
			PokemonItem[i]->SetScaleToImage();
			PokemonItem[i]->SetPosition({ 428, 24.0f + 96 * i });

			// 포켓몬 이름
			PokemonNameText[i] = CurrentLevel->CreateActor<TextActor>();
			PokemonNameText[i]->SetPos({ 468, -22.0f + 96 * i });

			// 포켓몬 레벨
			PokemonLevelText[i] = CurrentLevel->CreateActor<TextActor>();
			PokemonLevelText[i]->SetPos({ 570, 19.0f + 96 * i });

			// 포켓몬 HP
			PokemonCurrentHPText[i] = CurrentLevel->CreateActor<TextActor>();
			PokemonCurrentHPText[i]->SetPos({ 824, 16.0f + 96 * i });
			PokemonCurrentHPText[i]->SetAligned(true);
			// 포켓몬 최대 HP
			PokemonMaxHPText[i] = CurrentLevel->CreateActor<TextActor>();
			PokemonMaxHPText[i]->SetPos({ 924, 16.0f + 96 * i });
			PokemonMaxHPText[i]->SetAligned(true);

			PokemonHPBars[i] = CurrentLevel->CreateActor<PokemonHPBar>();
			PokemonHPBars[i]->SetPos({736, -14.0f + 96 * i});
		}
		// 취소 버튼
		CancelButtonRender = CreateRender("CancelButton.bmp", 1);
		CancelButtonRender->SetScale({ 216, 96 });
		CancelButtonRender->SetPosition({ 848, 580 });
		CancelButtonRender->SetFrame(0);
		

		TextBarRender = CreateRender("TextBar.bmp", 1);
		TextBarRender->SetScale({ 720, 112 });
		TextBarRender->SetPosition({ 370, 580 });
		TextBarRender->SetFrame(0);

		BarText = CurrentLevel->CreateActor<TextActor>();
		BarText->SetPos({ 52, 580 });
		BarText->SetLine(1);

		SelectRender = CreateRender("SelectMenu.bmp", 20);
		SelectRender->SetScale({ 280, 376 });
		SelectRender->SetPosition({ 814, 444 });
		SelectRender->Off();

		SelectCursorRender = CreateRender("Bag_CurrentArrow.bmp", 22);
		SelectCursorRender->SetScale({ 24, 40 });
		SelectCursorRender->SetFrame(0);
		SelectCursorRender->SetPosition({ 712, 580 });
		SelectCursorRender->Off();

		SelectText = CurrentLevel->CreateActor<TextActor>();
		SelectText->SetInterver({ 0, 20 });
		SelectText->SetLine(4);
		SelectText->Off();


	}
}

void PokemonUI::SetCursor(int _Cursor)
{
	SelectOff();
	CurrentCursor = _Cursor;
	CursorMove();
	SelectOn();
}

bool PokemonUI::GetIsPotion()
{
	return IsPotion;
}

void PokemonUI::Update(float _DeltaTime)
{
	TimeEvent.Update(_DeltaTime);
	AnimUpdate(_DeltaTime);
	if (IsStop == true) { 
		if (IsPotion == true)
		{
			Timer += _DeltaTime;
			PokemonCurrentHPText[CurrentCursor]->SetText(std::to_string(static_cast<int>(std::lerp(BeforeHP, CurrentHP, std::min<float>(1, Timer)))), "Font_Dialog_White.bmp", 3, false);
		}
		return; }
	if (GameEngineInput::IsDown("FieldUITestSwitch"))
	{
		Pokemons[CurrentCursor].MinusMonsterCurrentHP(10);
		PokeDataSetting();
	}
	if (true == IsSelect)
	{
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
		return;
	}
	if (StateValue == PokemonUIState::Switch)
	{
		if (GameEngineInput::IsDown("LeftMove"))
		{
			CurrentCursor = 0;
			CursorMove();
			return;
		}
		if (GameEngineInput::IsDown("RightMove"))
		{
			CursorDown();
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
			SwitchSelect();
			return;
		}
		if (GameEngineInput::IsDown("B"))
		{
			SwitchCancel();
			return;
		}
		return;
	}
	if (GameEngineInput::IsDown("LeftMove"))
	{
		CurrentCursor = 0;
		CursorMove();
		return;
	}
	if (GameEngineInput::IsDown("RightMove"))
	{
		CursorDown();
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
		MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
		MenuSound.Volume(0.5f);
		MenuSound.LoopCount(1);
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut(PrevLevel->GetName());
		IsStop = true;
		return;
	}

}

void PokemonUI::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
	Player::MainPlayer->GetPlayerPokemon()->Pokemons = Pokemons;
	if (_PrevLevel->GetName() == "SummaryLevel")
	{
		return;
	}
	StateValue = PokemonUIState::Normal;
}

void PokemonUI::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	IsStop = false;
	IsPotion = false;
	PokeDataSetting();
	if (_PrevLevel->GetName() == "SummaryLevel")
	{
		return;
	}
	else if (_PrevLevel->GetName() == "BagLevel")
	{
		IsBattle = PlayerBag::MainBag->GetIsBattle();
	}
	else if (_PrevLevel->GetName() == "BattleLevel")
	{
		IsBattle = true;
		StateValue = PokemonUIState::Shift;
	}
	else if (_PrevLevel->GetName() == "FieldMapLevel")
	{
		IsBattle = false;
	}
	PrevLevel = _PrevLevel;
	CurrentCursor = 0;
	CursorMove();
	SelectOff();
	SetBarText();
}

void PokemonUI::PokeDataSetting()
{
	Pokemons = Player::MainPlayer->GetPlayerPokemon()->Pokemons;

	// ____________렌더 생성______________
	
	{
		CursorRender.resize(Pokemons.size() + 1);
		for (int i = 0; i < Pokemons.size(); i++)
		{
			CursorRender[i] = PokemonBack[i];
			// 포켓몬 이미지
			std::string ImageStr = Pokemons[i].ForUI_GetMonsterName().data();
			ImageStr += "_mini.bmp";
			PokemonRender[i]->SetImage(ImageStr);
			float4 _RenderScale = PokemonRender[i]->GetImage()->GetImageScale();
			_RenderScale.x /= 2;
			PokemonRender[i]->SetScale(_RenderScale);
			// 포켓몬 이름
			PokemonNameText[i]->SetText(Pokemons[i].ForUI_GetMonsterName(), "Font_Dialog_White.bmp", 3, false);
			// 포켓몬 레벨
			PokemonLevelText[i]->SetText(Pokemons[i].ForUI_GetMonsterLevel(), "Font_Dialog_White.bmp", 3, false);
			// 포켓몬 최대 HP
			PokemonMaxHPText[i]->SetText(Pokemons[i].ForUI_GetMonsterMaxHP(), "Font_Dialog_White.bmp", 3, false);
			// 지닌 물건
			Pokemons[i].GetPossession() != ItemCode::Cancel ? PokemonItem[i]->On() : PokemonItem[i]->Off();
			// 포켓몬 HP
			PokemonCurrentHPText[i]->SetText(Pokemons[i].ForUI_GetMonsterCurrentHP(), "Font_Dialog_White.bmp", 3, false);

			PokemonHPBars[i]->SetValue(Pokemons[i].GetMonsterCurrentHP() / Pokemons[i].GetMonsterMaxHP_float());

			PokemonRender[i]->On();
			PokemonNameText[i]->On();
			PokemonLevelText[i]->On();
			PokemonCurrentHPText[i]->On();
			PokemonMaxHPText[i]->On();
		}
		for (size_t i = Pokemons.size(); i < 6; i++)
		{
			// 포켓몬 뒷 배경
			PokemonBack[i]->SetFrame(6);
			PokemonRender[i]->Off();
			PokemonNameText[i]->Off();
			PokemonLevelText[i]->Off();
			PokemonCurrentHPText[i]->Off();
			PokemonMaxHPText[i]->Off();
			PokemonItem[i]->Off();
			PokemonHPBars[i]->SetValue(0);
		}
		CursorRender[Pokemons.size()] = CancelButtonRender;
	}
	
}

void PokemonUI::CursorUp()
{
	CurrentCursor--;
	if (CurrentCursor == -1)
	{
		CurrentCursor = static_cast<int>(CursorRender.size()) - 1;
	}
	CursorMove();
}

void PokemonUI::CursorDown()
{
	CurrentCursor++;
	if (CurrentCursor == CursorRender.size())
	{
		CurrentCursor = 0;
	}
	CursorMove();
}

void PokemonUI::CursorMove()
{
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);

	if (StateValue != PokemonUIState::Switch)
	{
		for (int i = 0; i < CursorRender.size(); i++)
		{
			if (i < Pokemons.size() && true ==  Pokemons[i].IsMonsterStern())
			{
				CursorRender[i]->SetFrame(4);
				continue;
			}
			CursorRender[i]->SetFrame(0);
		}
		if (CurrentCursor < Pokemons.size() &&true ==  Pokemons[CurrentCursor].IsMonsterStern())
		{
			CursorRender[CurrentCursor]->SetFrame(5);
			return;
		}
		CursorRender[CurrentCursor]->SetFrame(1);
		return;
	}

	for (int i = 0; i < CursorRender.size(); i++)
	{
		if (i < Pokemons.size() && true == Pokemons[i].IsMonsterStern())
		{
			CursorRender[i]->SetFrame(4);
			continue;
		}
		CursorRender[i]->SetFrame(0);
	}
	if (SwitchCursor < Pokemons.size() && true == Pokemons[SwitchCursor].IsMonsterStern())
	{
		CursorRender[SwitchCursor]->SetFrame(5);
	}
	else
	{
		CursorRender[SwitchCursor]->SetFrame(2);
	}
	if (CurrentCursor == CursorRender.size() - 1)
	{
		CursorRender[CurrentCursor]->SetFrame(1);
		return;
	}
	if (CurrentCursor < Pokemons.size() && true ==  Pokemons[CurrentCursor].IsMonsterStern())
	{
		CursorRender[CurrentCursor]->SetFrame(5);
	}
	CursorRender[CurrentCursor]->SetFrame(3);
}

void PokemonUI::SelectOn()
{
	if (CurrentCursor == CursorRender.size() - 1)
	{
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut(PrevLevel->GetName());
		IsStop = true;
		return;
	}

	// 여기서 상황을 판단
	switch (StateValue)
	{
	case PokemonUIState::Normal:
	{
		if (ItemCode::Cancel != Pokemons[CurrentCursor].GetPossession())
		{
			SelectSize = 3;
			SelectText->SetText("SUMMARY\nSWITCH\nITEM\nCANCEL", "Font_Dialog.bmp", 22, false);
			SelectFunctions[0] = std::bind(&PokemonUI::SelectOff, this);
			SelectFunctions[1] = std::bind(&PokemonUI::Item, this);
			SelectFunctions[2] = std::bind(&PokemonUI::Switch, this);
			SelectFunctions[3] = std::bind(&PokemonUI::Summary, this);
		}
		else
		{
			SelectSize = 2;
			SelectText->SetText("SUMMARY\nSWITCH\nCANCEL", "Font_Dialog.bmp", 22, false);
			SelectFunctions[0] = std::bind(&PokemonUI::SelectOff, this);
			SelectFunctions[1] = std::bind(&PokemonUI::Switch, this);
			SelectFunctions[2] = std::bind(&PokemonUI::Summary, this);
		}
		break;
	}
	case PokemonUIState::Shift:
	{
		if (CurrentCursor == 0 || true == Pokemons[CurrentCursor].IsMonsterStern())
		{
			SelectSize = 1;
			SelectText->SetText("SUMMARY\nCANCEL", "Font_Dialog.bmp", 22, false);
			SelectFunctions[0] = std::bind(&PokemonUI::SelectOff, this);
			SelectFunctions[1] = std::bind(&PokemonUI::Summary, this);
		}
		else
		{
			SelectSize = 2;
			SelectText->SetText("SHIFT\nSUMMARY\nCANCEL", "Font_Dialog.bmp", 22, false);
			SelectFunctions[0] = std::bind(&PokemonUI::SelectOff, this);
			SelectFunctions[1] = std::bind(&PokemonUI::Summary, this);
			SelectFunctions[2] = std::bind(&PokemonUI::Shift, this);
		}
		break;
	}
	case PokemonUIState::Potion:
		if (false == Pokemons[CurrentCursor].IsMonsterStern())
		{
			PotionUse();
		}
		return;
	case PokemonUIState::Give:
		GiveItem();
		return;
	default:
		break;
	}

	IsSelect = true;
	SelectRender->On();
	SelectCursorRender->On();
	TextBarRender->SetFrame(1);
	TextBarRender->SetOrder(3);
	SelectRender->SetFrame(SelectSize);

	

	CurrentSelectCursor = SelectSize;
	SelectText->SetPos({ 744, 580.0f - 68 * SelectSize });
	SelectText->On();
	SelectCursorRender->SetPosition({ 712, 580.0f - 68 * SelectSize });

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
}

void PokemonUI::SelectOff()
{
	IsSelect = false;
	SelectRender->Off();
	SelectCursorRender->Off();
	TextBarRender->SetFrame(0);
	TextBarRender->SetOrder(1);
	SelectText->Off();
}

void PokemonUI::SelectMenu()
{
	SelectFunctions[CurrentSelectCursor]();
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
}

void PokemonUI::SelectUp()
{
	if (SelectSize <= CurrentSelectCursor)
	{
		return;
	}
	CurrentSelectCursor++;
	SelectMove();
}

void PokemonUI::SelectDown()
{
	if (0 >= CurrentSelectCursor)
	{
		return;
	}
	CurrentSelectCursor--;
	SelectMove();
}

void PokemonUI::SelectMove()
{
	SelectCursorRender->SetPosition({ 712, 580.0f - 68 * CurrentSelectCursor });
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
}

void PokemonUI::Summary()
{
	LevelChangeFade::MainLevelFade->LevelChangeFadeOut("SummaryLevel");
	IsStop = true;
}

void PokemonUI::Switch()
{
	SelectOff();
	SwitchCursor = CurrentCursor;
	CursorRender[CurrentCursor]->SetFrame(3);
	StateValue = PokemonUIState::Switch;	

	SetBarText();
}

void PokemonUI::SwitchCancel()
{
	StateValue = PokemonUIState::Normal;

	SetBarText();
	CursorMove();
}

void PokemonUI::SwitchSelect()
{
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
	if (CurrentCursor == CursorRender.size() - 1)
	{
		SwitchCancel();
		return;
	}
	PokeDataBase _Pokemon = Pokemons[SwitchCursor];
	Pokemons[SwitchCursor] = Pokemons[CurrentCursor];
	Pokemons[CurrentCursor] = _Pokemon;
	Player::MainPlayer->GetPlayerPokemon()->Pokemons = Pokemons;
	PokeDataSetting();
	SwitchCancel();
}

void PokemonUI::Item()
{
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.5f);
	MenuSound.LoopCount(1);

	BarText->SetText(std::string("Take the ") + Item::GetItem(Pokemons[CurrentCursor].GetPossession()).GetItemName().data() + ".", true);
	PlayerBag::MainBag->AddItem(Pokemons[CurrentCursor].GetPossession());
	Pokemons[CurrentCursor].SetPossession(ItemCode::Cancel);
	Player::MainPlayer->GetPlayerPokemon()->Pokemons = Pokemons;
	PokeDataSetting();
	SelectOff();
	IsStop = true;
	std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> Resume = [&](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
	{
		IsStop = false;
		SetBarText();
	};
	TimeEvent.AddEvent(1.0f, Resume, false);
	
}

void PokemonUI::Shift()
{
	PokeDataBase _Pokemon = Pokemons[0];
	Pokemons[0] = Pokemons[CurrentCursor];
	Pokemons[CurrentCursor] = _Pokemon;
	Player::MainPlayer->GetPlayerPokemon()->Pokemons = Pokemons;
	LevelChangeFade::MainLevelFade->LevelChangeFadeOut("BattleLevel");
	BattleLevel::BattleLevelPtr->ChangePlayerMonster(Pokemons[0].GetPokeNumber_enum());
	IsStop = true;
}

void PokemonUI::PotionUse()
{
	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("Potion.wav");
	MenuSound.Volume(1.0f);
	MenuSound.LoopCount(1);

	PlayerBag::MainBag->RemoveItem(CurrentItemCode);

	if (ItemCode::Potion == CurrentItemCode)
	{
		BeforeHP = Pokemons[CurrentCursor].GetMonsterCurrentHP();
		Pokemons[CurrentCursor].ForInven_UsePotion();
		CurrentHP = Pokemons[CurrentCursor].GetMonsterCurrentHP();
		BarText->SetText(Pokemons[CurrentCursor].ForUI_GetMonsterName() + " HP was restored.", true);
		PokemonHPBars[CurrentCursor]->SetTargetValue(Pokemons[CurrentCursor].GetMonsterCurrentHP() / Pokemons[CurrentCursor].GetMonsterMaxHP_float());
		IsPotion = true;
		FriendlyHPBackground::FriendlyPtr->IsPosionCheck(true);
		IsStop = true;
		if (true == IsBattle)
		{
			BattleLevel::BattleLevelPtr->UsePortionItem();
			std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> LevelChange = [](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
			{
				LevelChangeFade::MainLevelFade->LevelChangeFadeOut("BattleLevel");
			};
			TimeEvent.AddEvent(1.5f, LevelChange, false);
		}
		else
		{
			std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> LevelChange = [](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
			{
				LevelChangeFade::MainLevelFade->LevelChangeFadeOut("BagLevel");
			};
			TimeEvent.AddEvent(1.5f, LevelChange, false);
		}
	}
	else if (ItemCode::RareCandy == CurrentItemCode)
	{
		Pokemons[CurrentCursor].RareCandy_PlusLevel();
		BarText->SetText(Pokemons[CurrentCursor].ForUI_GetMonsterName() + " Level Up.", true);
		Player::MainPlayer->GetPlayerPokemon()->Pokemons[CurrentCursor] = Pokemons[CurrentCursor];
		PokeDataSetting();
		//PokemonLevelText[CurrentCursor]->SetText(Pokemons[CurrentCursor].ForUI_GetMonsterLevel(), "Font_Dialog_White.bmp", 3, false);
		IsStop = true;
		std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> LevelChange = [](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
		{
			LevelChangeFade::MainLevelFade->LevelChangeFadeOut("BagLevel");
		};
		TimeEvent.AddEvent(1.5f, LevelChange, false);
	}
	else if (ItemCode::Ether == CurrentItemCode)
	{
		Pokemons[CurrentCursor].PPAid_Use();
		BarText->SetText(Pokemons[CurrentCursor].ForUI_GetMonsterName() + " PP was restored.", true);
		IsStop = true;
		std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> LevelChange = [](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
		{
			LevelChangeFade::MainLevelFade->LevelChangeFadeOut("BagLevel");
		};
		TimeEvent.AddEvent(1.5f, LevelChange, false);
	}
}

void PokemonUI::SetBarText()
{

	switch (StateValue)
	{
	case PokemonUIState::Normal:
		BarText->SetText("Choose a POK@MON.", "Font_Dialog.bmp", 2);
		break;
	case PokemonUIState::Switch:
		BarText->SetText("Move to where?", "Font_Dialog.bmp", 2);
		break;
	case PokemonUIState::Shift:
		BarText->SetText("Choose a POK@MON.", "Font_Dialog.bmp", 2);
		break;
	case PokemonUIState::Potion:
		BarText->SetText("Use on which POK@MON.", "Font_Dialog.bmp", 2);
		break;
	case PokemonUIState::Give:
		BarText->SetText("Give to which POK@MON?", "Font_Dialog.bmp", 2);
		break;
	default:
		break;
	}
}

void PokemonUI::GiveItem()
{
	if (ItemCode::Cancel != Pokemons[CurrentCursor].GetPossession())
	{
		PlayerBag::MainBag->AddItem(Pokemons[CurrentCursor].GetPossession());
	}
	Pokemons[CurrentCursor].SetPossession(CurrentItemCode);
	PlayerBag::MainBag->RemoveItem(CurrentItemCode);

	BarText->SetText(std::string("Give the ") + Item::GetItem(CurrentItemCode).GetItemName().data() + ".", true);
	IsStop = true;
	Player::MainPlayer->GetPlayerPokemon()->Pokemons = Pokemons;
	PokeDataSetting();

	std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> LevelChange = [](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
	{
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut("BagLevel");
	};
	TimeEvent.AddEvent(1.5f, LevelChange, false);

	MenuSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuSound.Volume(0.7f);
	MenuSound.LoopCount(1);
}

void PokemonUI::AnimUpdate(float _DeltaTime)
{
	if (AnimTimer > 2)
	{
		AnimTimer = 0;
	}
	else if (AnimTimer > 1)
	{
		for (int i = 0; i < Pokemons.size(); i++)
		{
			if (CurrentCursor == i)
			{
				if (i == 0)
				{
					PokemonRender[i]->SetPosition({ 52, 172 });
				}
				else
				{
					PokemonRender[i]->SetPosition({ 408, 2.0f + 96 * i });
				}
				continue;
			}
			else
			{
				if (i == 0)
				{
					PokemonRender[i]->SetPosition({ 52, 172 });
				}
				else
				{
					PokemonRender[i]->SetPosition({ 408, 2.0f + 96 * i });
				}
			}
			PokemonRender[i]->SetFrame(1);
		}
	}
	else
	{
		for (int i = 0; i < Pokemons.size(); i++)
		{
			if (CurrentCursor == i)
			{
				if (i == 0)
				{
					PokemonRender[i]->SetPosition({ 52, 172 - 24 });
				}
				else
				{
					PokemonRender[i]->SetPosition({ 408, -22.0f + 96 * i });
				}
				continue;
			}
			else
			{
				if (i == 0)
				{
					PokemonRender[i]->SetPosition({ 52, 172  });
				}
				else
				{
					PokemonRender[i]->SetPosition({ 408, 2.0f + 96 * i });
				}
			}
			PokemonRender[i]->SetFrame(0);
		}
	}
	AnimTimer += AnimSpeed * _DeltaTime;
}
