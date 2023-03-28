#include "BuyWindow.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BuyLevel.h"
#include "BuyWindow.h"
#include "BuyUIManager.h"
#include "BuyLevelDialog.h"
#include "InputControll.h"

BuyWindow* BuyWindow::AcBuyWindow = nullptr;

BuyWindow::BuyWindow()
{
	AcBuyWindow = this;
}

BuyWindow::~BuyWindow()
{

}

void BuyWindow::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void BuyWindow::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void BuyWindow::Start()
{
	ParentLevel = dynamic_cast<BuyLevel*>(GetLevel());
	
	ItemPushBack();
	auto Iter = ItemList.begin();

	SetPos(ActorPos);
	Background = CreateRender("Shop_Buy.bmp", RenderOrder::BackGround);
	Background->SetScaleToImage();
	Background->EffectCameraOff();

	ItemNameRenders.resize(6);
	//ItemPriceRenders.resize(6);
	
	for (size_t i = 0; i < ItemNameRenders.size(); i++)
	{
		ItemNameRenders[i] = ParentLevel->CreateActor<TextActor>();
		if (i < ItemNameRenders.size() - 1)
		{
			ItemNameRenders[i]->SetText(Iter->GetItemName(), "Font_Dialog.bmp", static_cast<int>(RenderOrder::Shop_Text));

			ItemPriceRenders[i].SetOwner(this);
			ItemPriceRenders[i].SetImage("SmallNum.bmp", ItemPriceRenderScale, static_cast<int>(RenderOrder::Shop_Text), RGB(255, 0, 255));
			ItemPriceRenders[i].SetAlign(Align::Right);
			ItemPriceRenders[i].SetValue(Iter->GetPrice());
			ItemPriceRenders[i].SetRenderPos(FirstItemPriceRenderPos + LineInterval * static_cast<float>(i));
			
			Iter++;
			//ItemNameRenders[i]->SetText("ITEM" + std::to_string(i), "Font_Dialog.bmp", static_cast<int>(RenderOrder::Shop_Text));
		}
		else
		{
			ItemNameRenders[i]->SetText("CANCLE");
		}
		ItemNameRenders[i]->SetPos(NameRenderFirstPos + LineInterval *static_cast<float>(i));
	}


	//for (size_t i = 0; i < 5; i++)
	//{
	//	ItemPriceRenders[i].SetOwner(this);
	//	ItemPriceRenders[i].SetImage("SmallNum.bmp", ItemPriceRenderScale, static_cast<int>(RenderOrder::Shop_Text), RGB(255, 0, 255));
	//	ItemPriceRenders[i].SetAlign(Align::Right);
	//	ItemPriceRenders[i].SetValue(1000);
	//	ItemPriceRenders[i].SetRenderPos(FirstItemPriceRenderPos + LineInterval *static_cast<float>(i));
	//}

	ArrowRender = CreateRender("MenuArrow.bmp", RenderOrder::Shop_Text);
	ArrowRender->SetScaleToImage();
	ArrowRender->EffectCameraOff();
	ArrowRender->SetPosition(FirstArrowRenderPos);
}

void BuyWindow::Update(float _DeltaTime)
{
	if (false == InputControll::CanControll(InputControlHandle) || BuyLevelDialog::GetBuyLevelDialog()->IsUpdate())
	{
		ArrowRender->SetImage("PressMenuArrow.bmp");
		return;
	}
	else
	{
		ArrowRender->SetImage("MenuArrow.bmp");
	}
	
	if (InputControlHandle == -1)
	{
		InputControlHandle = InputControll::UseControll();
		return;
	}

	//if (!IsValid)
	//{
	//	ArrowRender->SetImage("PressMenuArrow.bmp");
	//	return;
	//}
	//else
	//{
	//	ArrowRender->SetImage("MenuArrow.bmp");
	//}

	if (GameEngineInput::IsDown("Menu_Up"))
	{
		ChangeStatePrev();
	}

	if (GameEngineInput::IsDown("Menu_Down"))
	{
		ChangeStateNext();
	}

	if (false == InputControll::IsCurFrameUsedKey() && GameEngineInput::IsDown("A"))
	{
		switch (State)
		{
		case 0:
			InputControlHandle = InputControll::ResetControll(InputControlHandle);
			BuyUIManager::GetBuyUIManager()->On(ItemList[0]);
			break;
		case 1:
			InputControlHandle = InputControll::ResetControll(InputControlHandle);
			BuyUIManager::GetBuyUIManager()->On(ItemList[1]);
			break;
		case 2:
			InputControlHandle = InputControll::ResetControll(InputControlHandle);
			BuyUIManager::GetBuyUIManager()->On(ItemList[2]);
			break;
		case 3:
			InputControlHandle = InputControll::ResetControll(InputControlHandle);
			BuyUIManager::GetBuyUIManager()->On(ItemList[3]);
			break;
		case 4:
			InputControlHandle = InputControll::ResetControll(InputControlHandle);
			BuyUIManager::GetBuyUIManager()->On(ItemList[4]);
			break;
		case 5:
			Cancle();
			break;
		default:
			break;
		}
	}
}

void BuyWindow::UpdateStart()
{
	InputControlHandle = InputControll::UseControll();
}

void BuyWindow::UpdateEnd()
{
	InputControlHandle = InputControll::ResetControll(InputControlHandle);
}

void BuyWindow::StateToRender()
{
	ArrowRender->SetPosition(FirstArrowRenderPos + LineInterval * static_cast<const float>(State));
}

void BuyWindow::ChangeStatePrev()
{
	State--;
	if (State < 0)
	{
		State = 5;
	}
	StateToRender();
}

void BuyWindow::ChangeStateNext()
{
	State++;
	if (State > 5)
	{
		State = 0;
	}
	StateToRender();
}

void BuyWindow::ChangeState(int _State)
{
	if (_State < 0 || _State > 5)
	{
		MsgAssert("BuyWindow에서 잘못된 State값을 넣었습니다")
	}
	State = _State;
	StateToRender();
}

void BuyWindow::Cancle()
{
	GameEngineCore::GetInst()->ChangeLevel("FieldmapLevel");
}

void BuyWindow::ItemPushBack()
{
	ItemList.reserve(5);
	ItemList.push_back(Item::GetItem(ItemCode::MonsterBall));
	ItemList.push_back(Item::GetItem(ItemCode::Potion));
	ItemList.push_back(Item::GetItem(ItemCode::Repel));
	ItemList.push_back(Item::GetItem(ItemCode::MasterBall));
	ItemList.push_back(Item::GetItem(ItemCode::RareCandy));
}
