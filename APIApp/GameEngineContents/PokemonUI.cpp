#include "PokemonUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "PocketMonCore.h"
PokemonUI::PokemonUI() 
{
}

PokemonUI::~PokemonUI() 
{
}

void PokemonUI::Start()
{
	// ____________렌더 생성______________
	{
		GameEngineRender* BackUI = CreateRender("PokemonUI_Back.bmp", 0);
		BackUI->SetScaleToImage();
		BackUI->SetPosition(BackUI->GetScale().half());

		// 포켓몬 뒷 배경
		MainPokemonBack = CreateRender("MainPokemon.bmp", 1);
		MainPokemonBack->SetScale({ 336, 228 });
		MainPokemonBack->SetPosition({ 172, 196 });

		// 포켓몬 이미지
		MainPokemonRender = CreateRender("Bulbasaur_mini.bmp", 2);
		float4 _RenderScale = MainPokemonRender->GetImage()->GetImageScale();
		_RenderScale.x /= 2;
		MainPokemonRender->SetScale(_RenderScale);
		MainPokemonRender->SetPosition({ 52, 172 });

		// 포켓몬 이름
		GameEngineLevel* CurrentLevel = GetLevel();
		MainPokemonNameText = CurrentLevel->CreateActor<TextActor>();
		MainPokemonNameText->SetPos({ 108, 172 });
		MainPokemonNameText->SetText("Bulbasaur", "Font_Dialog_White.bmp", false);

		// 포켓몬 레벨
		MainPokemonLevelText = CurrentLevel->CreateActor<TextActor>();
		MainPokemonLevelText->SetPos({ 212, 212 });
		MainPokemonLevelText->SetText("10", "Font_Dialog_White.bmp", false);

		// 포켓몬 HP
		MainPokemonHPText = CurrentLevel->CreateActor<TextActor>();
		MainPokemonHPText->SetPos({ 218, 282 });
		MainPokemonHPText->SetAligned(true);
		MainPokemonHPText->SetText("255", "Font_Dialog_White.bmp", false);
		// 포켓몬 최대 HP
		MainPokemonMaxHPText = CurrentLevel->CreateActor<TextActor>();
		MainPokemonMaxHPText->SetPos({ 326, 282 });
		MainPokemonMaxHPText->SetAligned(true);
		MainPokemonMaxHPText->SetText("255", "Font_Dialog_White.bmp", false);

		for (int i = 0; i < 5; i++)
		{
			// 포켓몬 뒷 배경
			SubPokemonBack[i] = CreateRender("SubPokemon.bmp", 1);
			SubPokemonBack[i]->SetScale({ 600, 96 });
			SubPokemonBack[i]->SetPosition({ 652, 84.0f + 96 * i });

			// 포켓몬 이미지
			SubPokemonRender[i] = CreateRender("Bulbasaur_mini.bmp", 2);
			_RenderScale = SubPokemonRender[i]->GetImage()->GetImageScale();
			_RenderScale.x /= 2;
			SubPokemonRender[i]->SetScale(_RenderScale);
			SubPokemonRender[i]->SetPosition({ 408, 98.0f + 96 * i });

			// 포켓몬 이름
			SubPokemonNameText[i] = CurrentLevel->CreateActor<TextActor>();
			SubPokemonNameText[i]->SetPos({ 468, 76.0f + 96 * i });
			SubPokemonNameText[i]->SetText("Bulbasaur", "Font_Dialog_White.bmp", 3, false);

			// 포켓몬 레벨
			SubPokemonLevelText[i] = CurrentLevel->CreateActor<TextActor>();
			SubPokemonLevelText[i]->SetPos({ 570, 115.0f + 96 * i });
			SubPokemonLevelText[i]->SetText("5", "Font_Dialog_White.bmp", 3, false);

			// 포켓몬 HP
			SubPokemonHPText[i] = CurrentLevel->CreateActor<TextActor>();
			SubPokemonHPText[i]->SetPos({ 824, 112.0f + 96 * i });
			SubPokemonHPText[i]->SetAligned(true);
			SubPokemonHPText[i]->SetText("25", "Font_Dialog_White.bmp", 3, false);
			// 포켓몬 최대 HP
			SubPokemonMaxHPText[i] = CurrentLevel->CreateActor<TextActor>();
			SubPokemonMaxHPText[i]->SetPos({ 924, 112.0f + 96 * i });
			SubPokemonMaxHPText[i]->SetAligned(true);
			SubPokemonMaxHPText[i]->SetText("25", "Font_Dialog_White.bmp", 3, false);
		}

		TextBarRender = CreateRender("TextBar.bmp", 1);
		TextBarRender->SetScale({ 720, 112 });
		TextBarRender->SetPosition({ 370, 580 });
		TextBarRender->SetFrame(0);

		CancelButtonRender = CreateRender("CancelButton.bmp", 1);
		CancelButtonRender->SetScale({ 216, 96 });
		CancelButtonRender->SetPosition({ 848, 580 });
		CancelButtonRender->SetFrame(0);

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

		CursorRender[0] = MainPokemonBack;
		CursorRender[1] = SubPokemonBack[0];
		CursorRender[2] = SubPokemonBack[1];
		CursorRender[3] = SubPokemonBack[2];
		CursorRender[4] = SubPokemonBack[3];
		CursorRender[5] = SubPokemonBack[4];
		CursorRender[6] = CancelButtonRender;

		SubPokemonBack[4]->Off();
		SubPokemonRender[4]->Off();
		SubPokemonHPText[4]->Off();
		SubPokemonLevelText[4]->Off();
		SubPokemonMaxHPText[4]->Off();
		SubPokemonNameText[4]->Off();

		SubPokemonBack[3]->Off();
		SubPokemonRender[3]->Off();
		SubPokemonHPText[3]->Off();
		SubPokemonLevelText[3]->Off();
		SubPokemonMaxHPText[3]->Off();
		SubPokemonNameText[3]->Off();
	}
}

void PokemonUI::Update(float _DeltaTime)
{

	if (true == IsSelect)
	{
		if (GameEngineInput::IsDown("A"))
		{
			return;
		}
		if (GameEngineInput::IsDown("B"))
		{
			SelectOff();
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
	PrevLevel = _PrevLevel;
	CurrentCursor = 0;
	CursorMove();
}

void PokemonUI::CursorUp()
{
	if (0 >= CurrentCursor)
	{
		CurrentCursor = 7;
	}
	CurrentCursor--;
	if (false == CursorRender[CurrentCursor]->IsUpdate())
	{
		CursorUp();
		return;
	}
	CursorMove();
}

void PokemonUI::CursorDown()
{
	if (6 <= CurrentCursor)
	{
		CurrentCursor = -1;
	}
	CurrentCursor++;
	if (false == CursorRender[CurrentCursor]->IsUpdate())
	{
		CursorDown();
		return;
	}
	CursorMove();
}

void PokemonUI::CursorMove()
{
	for (int i = 0; i < CursorRender.size(); i++)
	{
		CursorRender[i]->SetFrame(0);
	}
	CursorRender[CurrentCursor]->SetFrame(1);
}

void PokemonUI::SelectOn()
{
	if (CurrentCursor == 6)
	{
		PocketMonCore::GetInst().ChangeLevel(PrevLevel->GetName());
		return;
	}
	IsSelect = true;
	SelectRender->On();
	SelectCursorRender->On();
	TextBarRender->SetFrame(1);
	SelectRender->SetFrame(3);

	SelectSize = 3;

	CurrentSelectCursor = SelectSize;
	SelectText->SetPos({ 744, 580.0f - 68 * SelectSize });
	SelectText->SetText("SUMMARY\nSWITCH\nITEM\nCANCEL");
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
