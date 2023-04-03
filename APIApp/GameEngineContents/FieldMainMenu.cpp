#include "FieldMainMenu.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

#include "InputControll.h"
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
	ChangeStateSoundPlay();
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
	ChangeStateSoundPlay();
}

void FieldMainMenu::ChangeStateSoundPlay()
{
	ChangeStateSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	ChangeStateSound.Volume(1.0f);
	ChangeStateSound.LoopCount(1);
}

void FieldMainMenu::MainMenuOpenSoundPlay()
{
	MainMenuOpenSound = GameEngineResources::GetInst().SoundPlayToControl("MainMenuOpen.wav");
	MainMenuOpenSound.Volume(0.8f);
	MainMenuOpenSound.LoopCount(1);
}

void FieldMainMenu::UpdateStart()
{
	//if (!InputControll::CanControll())
	//{
	//	return;
	//}

	InputControlHandle = InputControll::UseControll();
	Player::MainPlayer->SetPlayerMoveBool(false);
	State = MainMenuState::Pokemon;
	MenuStateToRender();
	MainMenuOpenSoundPlay();
}

void FieldMainMenu::Update(float _DeltaTime)
{
	bool a = InputControll::CanControll(InputControlHandle);
	
	if (false == InputControll::CanControll(InputControlHandle))
	{
		return;
	}

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
			GameEngineCore::GetInst()->ChangeLevel("PokemonLevel");
			ChangeStateSoundPlay();
			break;
		case MainMenuState::Bag:
			GameEngineCore::GetInst()->ChangeLevel("BagLevel");
			ChangeStateSoundPlay();
			break;
		case MainMenuState::Red:
			GameEngineCore::GetInst()->ChangeLevel("TrainerCardLevel");
			ChangeStateSoundPlay();
			break;
		case MainMenuState::Save:
			break;
		case MainMenuState::Option:
			break;
		case MainMenuState::Exit:
			Off();
			break;
		default:
			break;
		}
	}

	if (GameEngineInput::IsDown("B"))
	{
		Off();
	}
}

void FieldMainMenu::UpdateEnd()
{
	InputControlHandle = InputControll::ResetControll(InputControlHandle);
	Player::MainPlayer->SetPlayerMoveBool(true);
	ChangeStateSoundPlay();
}

