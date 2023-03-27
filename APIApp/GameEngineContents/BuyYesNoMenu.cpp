#include "BuyYesNoMenu.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BuyLevelDialog.h"
#include "BuyWindow.h"


BuyYesNoMenu* BuyYesNoMenu::AcBuyYesNoMenu = nullptr;

BuyYesNoMenu::BuyYesNoMenu()
{
	AcBuyYesNoMenu = this;
}

BuyYesNoMenu::~BuyYesNoMenu()
{

}

void BuyYesNoMenu::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void BuyYesNoMenu::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void BuyYesNoMenu::Start()
{
	SetPos(ActorPos);

	MenuRenders.reserve(2);
	MenuRenders.emplace_back(CreateRender("Shop_Yes.bmp", RenderOrder::YesNoMenu));
	MenuRenders.emplace_back(CreateRender("Shop_No.bmp", RenderOrder::YesNoMenu));

	for (size_t i = 0; i < MenuRenders.size(); i++)
	{
		MenuRenders[i]->EffectCameraOff();
		MenuRenders[i]->SetScaleToImage();
	}

	Off();
}

void BuyYesNoMenu::UpdateStart()
{
	State = MenuState::Yes;
	StateToRender();
}


void BuyYesNoMenu::Update(float _DeltaTime)
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

			break;
		case MenuState::No:
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

void BuyYesNoMenu::UpdateEnd()
{
	BuyLevelDialog::GetBuyLevelDialog()->Off();
	BuyLevelDialog::GetBuyLevelDialog()->IsValid = true;
	BuyWindow::GetBuyWindow()->IsValid = true;
}

void BuyYesNoMenu::StateToRender()
{
	for (size_t i = 0; i < MenuRenders.size(); i++)
	{
		if (i == static_cast<int>(State))
		{
			MenuRenders[i]->On();
		}
		else
		{
			MenuRenders[i]->Off();
		}
	}
}

void BuyYesNoMenu::ChangeState()
{
	if (State == MenuState::Yes)
	{
		State = MenuState::No;
	}
	else
	{
		State = MenuState::Yes;
	}
	StateToRender();
}

