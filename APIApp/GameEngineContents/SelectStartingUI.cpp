#include "SelectStartingUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "FieldDialog.h"

SelectStartingUI::SelectStartingUI()
{

}

SelectStartingUI::~SelectStartingUI()
{

}

void SelectStartingUI::SelectMonster(PokeNumber _Pokemon)
{
	On();
	UpdateStart(_Pokemon);
}

void SelectStartingUI::TestSelectMonster()
{
	SelectMonster(PokeNumber::Bulbasaur);
}

void SelectStartingUI::Start()
{
	AcFieldDialog = FieldDialog::GetFieldDialog();
	BulbasaurScript.emplace_back("I see! BULBASAUR is your choice.\nIts very easy to raise.");
	BulbasaurScript.emplace_back("So, RED, you want to go with\nthe GRASS POK@MON BULBASAUR?");

	SquirtleScript.emplace_back("Hm! SQUIRTLE is your choice.\nIt's one worth raising.");
	SquirtleScript.emplace_back("So, RED, you've decided on the\nWATER POK@MON SQUIRTLE?");

	CharmanderScript.emplace_back("Ah! CHARMANDER is your choice.\nYou should raise it patiently.");
	CharmanderScript.emplace_back("So, RED, you're claiming the\nFIRE POK@MON CHARMANDER?");
	
	SelectScript.emplace_back("This POK@MON is really\nquite energetic!");

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

	Off();
}

void SelectStartingUI::Update(float _DeltaTime)
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
				//GivePoke(Select);
				AcFieldDialog->ConversationStart(&SelectScript);
				State = MenuState::Null;
				StateToRender();
				Off();
				break;
			case MenuState::No:
				AcFieldDialog->IsValid = true;
				State = MenuState::Null;
				StateToRender();
				Off();
				AcFieldDialog->Off();
				break;
			default:
				break;
			}
		}
	}
	else
	{
		AcFieldDialog->IsValid = true;
	}
}

void SelectStartingUI::UpdateStart(PokeNumber _Pokemon)
{
	Select = _Pokemon;
	AcFieldDialog->IsValid = false;
	switch (Select)
	{
	case PokeNumber::Bulbasaur:
		AcFieldDialog->ConversationStart(&BulbasaurScript);
		break;
	case PokeNumber::Charmander:
		AcFieldDialog->ConversationStart(&CharmanderScript);
		break;
	case PokeNumber::Squirtle:
		AcFieldDialog->ConversationStart(&SquirtleScript);
		break;
	default:
		break;
	}
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
