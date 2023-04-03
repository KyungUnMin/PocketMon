#include "BuyYesNoMenu.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BuyLevelDialog.h"
#include "BuyWindow.h"
#include "PlayerBag.h"
#include "InputControll.h"


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

	Script.push_back("Here you are!\nThank you!");

	Off();
}

void BuyYesNoMenu::MenuBeepSoundPlay()
{
	MenuBeepSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuBeepSound.Volume(0.8f);
	MenuBeepSound.LoopCount(1);
}

void BuyYesNoMenu::BuySoundPlay()
{
	BuySound = GameEngineResources::GetInst().SoundPlayToControl("BuySound.wav");
	BuySound.Volume(0.8f);
	BuySound.LoopCount(1);
}

void BuyYesNoMenu::UpdateStart()
{
	InputControlHandle = InputControll::UseControll();
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
			BuyItem();
			Off();
			BuyLevelDialog::GetBuyLevelDialog()->ConversationStart(&Script);
			BuyLevelDialog::GetBuyLevelDialog()->IsValid = true;
			BuySoundPlay();
			break;
		case MenuState::No:
			Off();
			//BuyWindow::GetBuyWindow()->IsValid = true;
			BuyLevelDialog::GetBuyLevelDialog()->Off();
			MenuBeepSoundPlay();
			break;
		default:
			break;
		}
	}

	if (GameEngineInput::IsDown("B"))
	{
		Off();
		//BuyWindow::GetBuyWindow()->IsValid = true;
		BuyLevelDialog::GetBuyLevelDialog()->Off();
		BuyWindow::GetBuyWindow()->InputControlHandle = InputControll::UseControll();
	}
}

void BuyYesNoMenu::UpdateEnd()
{
	InputControlHandle = InputControll::ResetControll(InputControlHandle);
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
	MenuBeepSoundPlay();
}

void BuyYesNoMenu::BuyItem()
{
	PlayerBag::MainBag->AddItem(SelectItem->GetItemCode(), Count);
	PlayerBag::MainBag->MinusMoney(SelectItem->GetPrice() * Count);
}

