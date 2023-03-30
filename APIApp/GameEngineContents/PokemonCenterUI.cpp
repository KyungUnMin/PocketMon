#include "PokemonCenterUI.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "FieldDialog.h"

PokemonCenterUI::PokemonCenterUI()
{

}

PokemonCenterUI::~PokemonCenterUI()
{

}

void PokemonCenterUI::CenterStart()
{
	Process = CenterProcess::Welcome;
	AcFieldDialog->ConversationStart(&WelcomeScript);
	On();
}

void PokemonCenterUI::Start()
{
	AcFieldDialog = FieldDialog::GetFieldDialog();
	if (AcFieldDialog == nullptr)
	{
		MsgAssert("FieldDialog가 nullptr입니다.")
	}
	WelcomeScript.emplace_back("Welcome to our POK@MON CENTER!");
	WelcomeScript.emplace_back("Would you like me to heal your\nPOK@MON back to perfect health?");
	HealScript.emplace_back("Okay, I`ll take your POK@MON for a\nfew seconds.");
	GoodbyeScript1.emplace_back("We hope to see you again!");

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

void PokemonCenterUI::Update(float _DeltaTime)
{
	switch (Process)
	{
	case CenterProcess::Welcome:
		if (AcFieldDialog->IsAllScriptPrintEnd() && State == PokemonMenuState::Null)
		{
			State = PokemonMenuState::Yes;
			StateToRender();
		}
		else if (AcFieldDialog->IsAllScriptPrintEnd() && State != PokemonMenuState::Null)
		{
			AcFieldDialog->IsValid = false;
			if (GameEngineInput::IsDown("Menu_Up") || GameEngineInput::IsDown("Menu_Down"))
			{
				ChangeState();
			}

			if (GameEngineInput::IsDown("A"))
			{
				switch (State)
				{
				case PokemonMenuState::Yes:
					Process = CenterProcess::Heal;
					AcFieldDialog->ConversationStart(&HealScript);
					State = PokemonMenuState::Null;
					StateToRender();
					//HealPokemon();
					break;
				case PokemonMenuState::No:
					AcFieldDialog->ConversationStart(&GoodbyeScript1);
					State = PokemonMenuState::Null;
					StateToRender();
					Off();
					break;
				default:
					break;
				}
			}
		}
		break;
	case CenterProcess::Heal:
		if (AcFieldDialog->IsAllScriptPrintEnd())
		{
			//AnimationStart();
		}
		//else if (AcFieldDialog->IsAllScriptPrintEnd() && IsAnimationEnd())
		//{
		//		Process = CenterProcess::Goodbye;
		//		AcFieldDialog -> ConversationStart(&GoodbyeScript2);
		//}
	
		break;
	case CenterProcess::Goodbye:
		if (!AcFieldDialog->IsUpdate())
		{
			Off();
		}
		break;
	default:
		break;
	}
}

void PokemonCenterUI::StateToRender()
{
	switch (State)
	{
	case PokemonMenuState::Null:
		MenuRenders[0]->Off();
		MenuRenders[1]->Off();
		break;
	case PokemonMenuState::Yes:
		MenuRenders[0]->On();
		MenuRenders[1]->Off();
		break;
	case PokemonMenuState::No:
		MenuRenders[0]->Off();
		MenuRenders[1]->On();
		break;
	default:
		break;
	}
}

void PokemonCenterUI::ChangeState()
{
	if (State == PokemonMenuState::Yes)
	{
		State = PokemonMenuState::No;
	}
	else if (State == PokemonMenuState::No)
	{
		State = PokemonMenuState::Yes;
	}
	StateToRender();
}


