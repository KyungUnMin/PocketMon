#include "PokemonUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "PokeDataBase.h"
#include "PocketMonCore.h"
PokemonUI::PokemonUI() 
{
}

PokemonUI::~PokemonUI() 
{
}

void PokemonUI::Start()
{
	CurrentLevel = GetLevel();
	//_______테스트용 포켓몬 생성
	Pokemons.resize(5);
	Pokemons[0] = PokeDataBase::PokeCreate(1, 5);
	Pokemons[1] = PokeDataBase::PokeCreate(4, 5);
	Pokemons[2] = PokeDataBase::PokeCreate(7, 5);
	Pokemons[3] = PokeDataBase::PokeCreate(10, 2);
	Pokemons[4] = PokeDataBase::PokeCreate(11, 3);
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

		for (int i = 1; i < 6; i++)
		{
			// 포켓몬 뒷 배경
			PokemonBack[i] = CreateRender("SubPokemon.bmp", 1);
			PokemonBack[i]->SetScale({ 600, 96 });
			PokemonBack[i]->SetPosition({ 652, -12.0f + 96 * i });
			// 포켓몬 이미지
			PokemonRender[i] = CreateRender(2);
			PokemonRender[i]->SetPosition({ 408, 2.0f + 96 * i });

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


		SelectRender = CreateRender("SelectMenu.bmp", 4);
		SelectRender->SetScale({ 280, 376 });
		SelectRender->SetPosition({ 814, 444 });
		SelectRender->Off();

		SelectCursorRender = CreateRender("Bag_CurrentArrow.bmp", 5);
		SelectCursorRender->SetScale({ 24, 40 });
		SelectCursorRender->SetFrame(0);
		SelectCursorRender->SetPosition({ 712, 580 });
		SelectCursorRender->Off();

		SelectText = CurrentLevel->CreateActor<TextActor>();
		SelectText->SetInterver({ 0, 20 });
		SelectText->SetLine(4);
		SelectText->Off();


	}
	PokeDataSetting();
}

void PokemonUI::Update(float _DeltaTime)
{
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
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		return;
	}

}

void PokemonUI::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
}

void PokemonUI::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	if (_PrevLevel->GetName() == "SummaryLevel")
	{
		return;
	}
	PrevLevel = _PrevLevel;
	CurrentCursor = 0;
	CursorMove();
	SelectOff();
}

void PokemonUI::PokeDataSetting()
{
	// ____________렌더 생성______________
	{
		CursorRender.resize(Pokemons.size() + 1);
		for (int i = 0; i < Pokemons.size(); i++)
		{
			CursorRender[i] = PokemonBack[i];
			// 포켓몬 이미지
			std::string ImageStr = Pokemons[i]->ForUI_GetMonsterName().data();
			ImageStr += "_mini.bmp";
			PokemonRender[i]->SetImage(ImageStr);
			float4 _RenderScale = PokemonRender[i]->GetImage()->GetImageScale();
			_RenderScale.x /= 2;
			PokemonRender[i]->SetScale(_RenderScale);
			// 포켓몬 이름
			PokemonNameText[i]->SetText(Pokemons[i]->ForUI_GetMonsterName(), "Font_Dialog_White.bmp", 3, false);
			// 포켓몬 레벨
			PokemonLevelText[i]->SetText(Pokemons[i]->ForUI_GetMonsterLevel(), "Font_Dialog_White.bmp", 3, false);
			// 포켓몬 HP
			PokemonCurrentHPText[i]->SetText(Pokemons[i]->ForUI_GetMonsterCurrentHP(), "Font_Dialog_White.bmp", 3, false);
			// 포켓몬 최대 HP
			PokemonMaxHPText[i]->SetText(Pokemons[i]->ForUI_GetMonsterMaxHP(), "Font_Dialog_White.bmp", 3, false);
		}
		for (size_t i = Pokemons.size(); i < 6; i++)
		{
			// 포켓몬 뒷 배경
			PokemonBack[i]->SetFrame(4);
			PokemonRender[i]->Off();
			PokemonNameText[i]->Off();
			PokemonLevelText[i]->Off();
			PokemonCurrentHPText[i]->Off();
			PokemonMaxHPText[i]->Off();
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
	if (StateValue != PokemonUIState::Switch)
	{
		for (int i = 0; i < CursorRender.size(); i++)
		{
			CursorRender[i]->SetFrame(0);
		}
		CursorRender[CurrentCursor]->SetFrame(1);
		return;
	}
	for (int i = 0; i < CursorRender.size(); i++)
	{
		CursorRender[i]->SetFrame(0);
	}
	CursorRender[SwitchCursor]->SetFrame(2);
	if (CurrentCursor == CursorRender.size() - 1)
	{
		CursorRender[CurrentCursor]->SetFrame(1);
		return;
	}
	CursorRender[CurrentCursor]->SetFrame(3);
}

void PokemonUI::SelectOn()
{
	if (CurrentCursor == CursorRender.size() - 1)
	{
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		return;
	}
	IsSelect = true;
	SelectRender->On();
	SelectCursorRender->On();
	TextBarRender->SetFrame(1);
	SelectRender->SetFrame(3);


	// 여기서 상황을 판단
	switch (StateValue)
	{
	case PokemonUIState::Normal:
		SelectSize = 3;
		SelectText->SetText("SUMMARY\nSWITCH\nITEM\nCANCEL");
		SelectFunctions[0] = std::bind(&PokemonUI::SelectOff, this);
		SelectFunctions[1] = std::bind(&PokemonUI::Item, this);
		SelectFunctions[2] = std::bind(&PokemonUI::Switch, this);
		SelectFunctions[3] = std::bind(&PokemonUI::Summary, this);
		break;
	case PokemonUIState::Shift:
		SelectSize = 2;
		SelectText->SetText("SHIFT\nSUMMARY\nCANCEL");
		SelectFunctions[0] = std::bind(&PokemonUI::SelectOff, this);
		SelectFunctions[1] = std::bind(&PokemonUI::Summary, this);
		SelectFunctions[2] = std::bind(&PokemonUI::Shift, this);
		break;
	case PokemonUIState::Potion:
		break;
	case PokemonUIState::Give:
		break;
	default:
		break;
	}
	

	CurrentSelectCursor = SelectSize;
	SelectText->SetPos({ 744, 580.0f - 68 * SelectSize });
	SelectText->On();
	SelectCursorRender->SetPosition({ 712, 580.0f - 68 * SelectSize });
}

void PokemonUI::SelectOff()
{
	IsSelect = false;
	SelectRender->Off();
	SelectCursorRender->Off();
	TextBarRender->SetFrame(0);
	SelectText->Off();
}

void PokemonUI::SelectMenu()
{
	SelectFunctions[CurrentSelectCursor]();
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
}

void PokemonUI::Summary()
{
	PocketMonCore::GetInst().ChangeLevel("SummaryLevel");
}

void PokemonUI::Switch()
{
	SelectOff();
	SwitchCursor = CurrentCursor;
	CursorRender[CurrentCursor]->SetFrame(3);
	StateValue = PokemonUIState::Switch;	
}

void PokemonUI::SwitchCancel()
{
	StateValue = PokemonUIState::Normal;
	CursorMove();
}

void PokemonUI::SwitchSelect()
{
	if (CurrentCursor == CursorRender.size() - 1)
	{
		SwitchCancel();
		return;
	}
	PokeDataBase* _Pokemon = Pokemons[SwitchCursor];
	Pokemons[SwitchCursor] = Pokemons[CurrentCursor];
	Pokemons[CurrentCursor] = _Pokemon;
	PokeDataSetting();
	SwitchCancel();
}

void PokemonUI::Item()
{
	SelectOff();
}

void PokemonUI::Shift()
{
	SelectOff();
}
