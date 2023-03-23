#include "BuyWindow.h"
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
		ItemNameRenders[i]->SetPos(NameRenderFirstPos + float4{ 0, 64 } *static_cast<float>(i));
	}

	for (size_t i = 0; i < 6; i++)
	{
		ItemPriceRenders[i].SetOwner(this);
		ItemPriceRenders[i].SetImage("SmallNum.bmp", ItemPriceRenderScale, static_cast<int>(RenderOrder::Shop_Text), RGB(255, 0, 255));
		ItemPriceRenders[i].SetAlign(Align::Right);
		ItemPriceRenders[i].SetValue(1000);
		ItemPriceRenders[i].SetRenderPos(FirstItemPriceRenderPos + float4{ 0, 64 } *static_cast<float>(i));
	}
}
