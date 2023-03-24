#include "BuyWindow.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BuyLevel.h"

BuyWindow::BuyWindow()
{

}

BuyWindow::~BuyWindow()
{

}

void BuyWindow::Start()
{
	ParentLevel = dynamic_cast<BuyLevel*>(GetLevel());
	
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
			ItemNameRenders[i]->SetText("ITEM" + std::to_string(i), "Font_Dialog.bmp", static_cast<int>(RenderOrder::Shop_Text));
		}
		else
		{
			ItemNameRenders[i]->SetText("CANCLE");
		}
		ItemNameRenders[i]->SetPos(NameRenderFirstPos + LineInterval *static_cast<float>(i));
	}

	for (size_t i = 0; i < 6; i++)
	{
		ItemPriceRenders[i].SetOwner(this);
		ItemPriceRenders[i].SetImage("SmallNum.bmp", ItemPriceRenderScale, static_cast<int>(RenderOrder::Shop_Text), RGB(255, 0, 255));
		ItemPriceRenders[i].SetAlign(Align::Right);
		ItemPriceRenders[i].SetValue(1000);
		ItemPriceRenders[i].SetRenderPos(FirstItemPriceRenderPos + LineInterval *static_cast<float>(i));
	}

	ArrowRender = CreateRender("MenuArrow.bmp", RenderOrder::Shop_Text);
	ArrowRender->SetScaleToImage();
	ArrowRender->EffectCameraOff();
	ArrowRender->SetPosition(FirstArrowRenderPos);
}

void BuyWindow::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("Menu_Up"))
	{
		ChangeStatePrev();
	}

	if (GameEngineInput::IsDown("Menu_Down"))
	{
		ChangeStateNext();
	}
}

void BuyWindow::StateToRender()
{
	ArrowRender->SetPosition(FirstArrowRenderPos + LineInterval * State);
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
