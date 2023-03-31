#include "SelectStartingUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "FieldDialog.h"
#include "InputControll.h"
#include "Player.h"

SelectStartingUI* SelectStartingUI::MainSelectStartingUI = nullptr;

SelectStartingUI::SelectStartingUI()
{
	MainSelectStartingUI = this;
}

SelectStartingUI::~SelectStartingUI()
{

}

void SelectStartingUI::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void SelectStartingUI::SelectMonster(PokeNumber _Pokemon, std::function<void()> _DeletBall)
{
	if (!IsGetPokemon)
	{
		On();
		UpdateStart(_Pokemon, _DeletBall);
	}
	else
	{
		AcFieldDialog->ConversationStart(&AlreadyGetMonsterScript);
	}
}

void SelectStartingUI::Start()
{
	AcFieldDialog = FieldDialog::GetFieldDialog();
	BulbasaurScript.emplace_back("I see! BULBASAUR is your choice.\nIt`s very easy to raise.");
	BulbasaurScript.emplace_back("So, RED, you want to go with\nthe GRASS POK@MON BULBASAUR?");

	SquirtleScript.emplace_back("Hm! SQUIRTLE is your choice.\nIt`s one worth raising.");
	SquirtleScript.emplace_back("So, RED, you`ve decided on the\nWATER POK@MON SQUIRTLE?");

	CharmanderScript.emplace_back("Ah! CHARMANDER is your choice.\nYou should raise it patiently.");
	CharmanderScript.emplace_back("So, RED, you`re claiming the\nFIRE POK@MON CHARMANDER?");
	
	SelectScript.emplace_back("This POK@MON is really quite\nenergetic!");

	AlreadyGetMonsterScript.emplace_back("That`s PROF. OAK`s last POK@MON.");

	MenuRenders.reserve(2);
	MenuRenders.emplace_back(CreateRender("Shop_Yes.bmp", RenderOrder::YesNoMenu));
	MenuRenders.emplace_back(CreateRender("Shop_No.bmp", RenderOrder::YesNoMenu));

	for (size_t i = 0; i < MenuRenders.size(); i++)
	{
		MenuRenders[i]->SetPosition(MenuRenderPos);
		MenuRenders[i]->SetScaleToImage();
		MenuRenders[i]->EffectCameraOff();
		MenuRenders[i]->Off();
	}

	BulbasaurRender = CreateRender("Select_Bulbasaur.bmp", RenderOrder::YesNoMenu);
	BulbasaurRender->SetScaleToImage();
	BulbasaurRender->EffectCameraOff();
	BulbasaurRender->SetPosition(SetRednerPos);

	CharmanderRender = CreateRender("Select_Charmander.bmp", RenderOrder::YesNoMenu);
	CharmanderRender->SetScaleToImage();
	CharmanderRender->EffectCameraOff();
	CharmanderRender->SetPosition(SetRednerPos);

	SquirtleRender = CreateRender("Select_Squirtle.bmp", RenderOrder::YesNoMenu);
	SquirtleRender->SetScaleToImage();
	SquirtleRender->EffectCameraOff();
	SquirtleRender->SetPosition(SetRednerPos);

	Off();
}

void SelectStartingUI::Update(float _DeltaTime)
{
	if (!IsGetPokemon)
	{
		if (State == MenuState::Null && AcFieldDialog->IsAllScriptPrintEnd() && (AcFieldDialog->GetCurScriptPtr() == &BulbasaurScript || AcFieldDialog->GetCurScriptPtr() == &SquirtleScript || AcFieldDialog->GetCurScriptPtr() == &CharmanderScript))
		{
			State = MenuState::Yes;
			StateToRender();
		}
		else if (State != MenuState::Null)
		{
			if (GameEngineInput::IsDown("Menu_Up") || GameEngineInput::IsDown("Menu_Down"))
			{
				ChangeState();
			}

			if (GameEngineInput::IsDown("A"))
			{
				switch (State)
				{
				case MenuState::Yes:
					Player::MainPlayer->GetPlayerPokemon()->AddPokemon(PokeDataBase::PokeCreate(Select, 5));
					DeleteBallFunction();
					AcFieldDialog->ConversationStart(&SelectScript);
					State = MenuState::Null;
					StateToRender();
					Off();
					IsGetPokemon = true;
					break;
				case MenuState::No:
					AcFieldDialog->IsValid = true;
					State = MenuState::Null;
					StateToRender();
					Off();
					AcFieldDialog->Off();
					IsGetPokemon = false;
					break;
				default:
					break;
				}
			}
		}
	}
}

void SelectStartingUI::UpdateStart(PokeNumber _Pokemon, std::function<void()> _DeleteBall)
{
	if (!IsGetPokemon)
	{
		InputControllHandle = InputControll::UseControll();
		Select = _Pokemon;
		AcFieldDialog->IsValid = false;
		DeleteBallFunction = _DeleteBall;
		switch (Select)
		{
		case PokeNumber::Bulbasaur:
			AcFieldDialog->ConversationStart(&BulbasaurScript);
			BulbasaurRender->On();
			CharmanderRender->Off();
			SquirtleRender->Off();
			break;
		case PokeNumber::Charmander:
			AcFieldDialog->ConversationStart(&CharmanderScript);
			BulbasaurRender->Off();
			CharmanderRender->On();
			SquirtleRender->Off();
			break;
		case PokeNumber::Squirtle:
			AcFieldDialog->ConversationStart(&SquirtleScript);
			BulbasaurRender->Off();
			CharmanderRender->Off();
			SquirtleRender->On();
			break;
		default:
			break;
		}
	}
}

void SelectStartingUI::UpdateEnd()
{
	InputControllHandle = InputControll::ResetControll(InputControllHandle);
}

void SelectStartingUI::StateToRender()
{
	if (State == MenuState::Null)
	{
		MenuRenders[0]->Off();
		MenuRenders[1]->Off();
	}
	else
	{
		for (size_t i = 0; i < MenuRenders.size(); i++)
		{
			if (static_cast<int>(State) == i)
			{
				MenuRenders[i]->On();
			}
			else
			{
				MenuRenders[i]->Off();
			}
		}
	}
}

void SelectStartingUI::ChangeState()
{
	if (State == MenuState::Yes)
	{
		State = MenuState::No;
		StateToRender();
	}
	else if (State == MenuState::No)
	{
		State = MenuState::Yes;
		StateToRender();
	}
}
