#include "BuyWindow.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BuyLevel.h"
#include "CountItemMenu.h"

BuyWindow* BuyWindow::AcBuyWindow = nullptr;

BuyWindow::BuyWindow()
{
	AcBuyWindow = this;
}

BuyWindow::~BuyWindow()
{

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
			ItemNameRenders[i]->SetText(Iter->Name, "Font_Dialog.bmp", static_cast<int>(RenderOrder::Shop_Text));

			ItemPriceRenders[i].SetOwner(this);
			ItemPriceRenders[i].SetImage("SmallNum.bmp", ItemPriceRenderScale, static_cast<int>(RenderOrder::Shop_Text), RGB(255, 0, 255));
			ItemPriceRenders[i].SetAlign(Align::Right);
			ItemPriceRenders[i].SetValue(Iter->Price);
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
	if (!IsValid)
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
		case 0:
			ParentLevel->GetCountItemMenu()->On();
			//CountItemMenu::GetCountItemMenu()->On();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			Cancle();
			break;
		default:
			break;
		}
	}
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
	ItemList.push_back({"POK@ BALL", 200, "EXPLANE"});
	ItemList.push_back({"POTION", 200, "EXPLANE"});
	ItemList.push_back({"REPEL", 350, "EXPLANE"});
	ItemList.push_back({"MASTER BALL", 10, "EXPLANE"});
	ItemList.push_back({"RARE CANDY", 10, "EXPLANE"});
}
