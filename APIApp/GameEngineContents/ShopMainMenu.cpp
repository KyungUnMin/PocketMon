#include "ShopMainMenu.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "FieldDialog.h"
#include "ShopUIManager.h"

ShopMainMenu* ShopMainMenu::AcShopMainMenu = nullptr;

ShopMainMenu::ShopMainMenu()
{
	AcShopMainMenu = this;
}

ShopMainMenu::~ShopMainMenu()
{

}

void ShopMainMenu::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void ShopMainMenu::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void ShopMainMenu::Start()
{
	SetPos(ActorPos);
	ShopMainMenuRender = CreateRender("Shop_MainMenu.bmp", RenderOrder::Shop_MainMenu);
	ShopMainMenuRender->EffectCameraOff();
	ShopMainMenuRender->SetScaleToImage();

	MenuArrowRender = CreateRender("MenuArrow.bmp", RenderOrder::Shop_MainMenu);
	MenuArrowRender->EffectCameraOff();
	MenuArrowRender->SetScaleToImage();
	MenuArrowRender->SetPosition(FirstArrowRenderPos);

	AcParent = ShopUIManager::GetShopUIManager();
}


void ShopMainMenu::UpdateStart()
{
	State = ShopMianMenuState::Buy;
	MenuStateToRender();
	FieldDialog::GetFieldDialog()->IsValid = false;
}

void ShopMainMenu::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("Menu_Up"))
	{
		ChangeState();
		//ChangeStatePrev();
	}

	if (GameEngineInput::IsDown("Menu_Down"))
	{
		ChangeState();
		//ChangeStateNext();
	}

	if (GameEngineInput::IsDown("A"))
	{
		switch (State)
		{
		case ShopMianMenuState::Buy:
			GameEngineCore::GetInst()->ChangeLevel("BuyLevel");
			break;
		case ShopMianMenuState::Sell:
			break;
		case ShopMianMenuState::SeeYa:
			AcParent->LeaveShop();
			break;
		default:
			break;
		}
	}
}

void ShopMainMenu::UpdateEnd()
{
	FieldDialog::GetFieldDialog()->IsValid = true;
}

void ShopMainMenu::MenuStateToRender()
{
	switch (State)
	{
	case ShopMianMenuState::Buy:
		MenuArrowRender->SetPosition(FirstArrowRenderPos);
		break;
	case ShopMianMenuState::Sell:
		MenuArrowRender->SetPosition(SecondArrowRenderPos);
		break;
	case ShopMianMenuState::SeeYa:
		MenuArrowRender->SetPosition(ThirdArrowRenderPos);
		break;
	default:
		break;
	}
}

void ShopMainMenu::ChangeStatePrev()
{
	int CurState = static_cast<int>(State);
	CurState--;
	if (CurState < 0)
	{
		CurState = 2;
	}
	State = static_cast<ShopMianMenuState>(CurState);
	MenuStateToRender();
}

void ShopMainMenu::ChangeStateNext()
{
	int CurState = static_cast<int>(State);
	CurState++;
	if (CurState > 2)
	{
		CurState = 0;
	}
	State = static_cast<ShopMianMenuState>(CurState);
	MenuStateToRender();
}

void ShopMainMenu::ChangeState()
{
	if (State == ShopMianMenuState::Buy)
	{
		State = ShopMianMenuState::SeeYa;
		MenuStateToRender();
	}
	else
	{
		State = ShopMianMenuState::Buy;
		MenuStateToRender();
	}
}
