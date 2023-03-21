#include "FieldMainMenu.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

#include "Player.h"

FieldMainMenu* FieldMainMenu::MainFieldMainMenu = nullptr;

FieldMainMenu::FieldMainMenu()
{
	MainFieldMainMenu = this;
}

FieldMainMenu::~FieldMainMenu()
{

}

void FieldMainMenu::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void FieldMainMenu::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void FieldMainMenu::OnOffSwtich()
{
	if (IsUpdate())
	{
		Off();
	}
	else
	{
		On();
	}
}

void FieldMainMenu::Start()
{
	SetPos(ActorPos);
	FieldMainMenuRender.reserve(6);
	for (size_t i = 0; i < FieldMainMenuRender.capacity(); i++)
	{
		FieldMainMenuRender.emplace_back(CreateRender("MenuUI_" + std::to_string(i) + ".bmp", RenderOrder::Field_MainMenu));
		FieldMainMenuRender[i]->EffectCameraOff();
		FieldMainMenuRender[i]->SetScaleToImage();
	}

	Off();
}


void FieldMainMenu::MenuStateToRender()
{
	Player::MainPlayer->SetPlayerMoveBool(false);
	for (size_t i = 0; i < FieldMainMenuRender.size(); i++)
	{
		if (i != static_cast<int>(State))
		{
			FieldMainMenuRender[i]->Off();
		}
		else
		{
			FieldMainMenuRender[i]->On();
		}
	}
}

void FieldMainMenu::ChangeStatePrev()
{
	int CurState = static_cast<int>(State);
	CurState--;
	if (CurState < 0)
	{
		CurState = 5;
	}
	State = static_cast<MainMenuState>(CurState);
	MenuStateToRender();
}

void FieldMainMenu::ChangeStateNext()
{
	int CurState = static_cast<int>(State);
	CurState++;
	if (CurState > 5)
	{
		CurState = 0;
	}
	State = static_cast<MainMenuState>(CurState);
	MenuStateToRender();
}


void FieldMainMenu::UpdateStart()
{
	State = MainMenuState::Pokemon;
	MenuStateToRender();
}

void FieldMainMenu::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("Menu_Up"))
	{
		ChangeStatePrev();
	}

	if (GameEngineInput::IsDown("Menu_Down"))
	{
		ChangeStateNext();
	}

	if (GameEngineInput::IsDown("A"))
	{
		switch (State)
		{
		case MainMenuState::Pokemon:
			break;
		case MainMenuState::Bag:
			GameEngineCore::GetInst()->ChangeLevel("BagLevel");
			break;
		case MainMenuState::Red:
			break;
		case MainMenuState::Save:
			break;
		case MainMenuState::Option:
			break;
		case MainMenuState::Exit:
			break;
		default:
			break;
		}
	}
}

void FieldMainMenu::UpdateEnd()
{
	Player::MainPlayer->SetPlayerMoveBool(true);
}

