#include "CountItemMenu.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "BuyWindow.h"
#include "BuyYesNoMenu.h"
#include "BuyLevelDialog.h"
#include "BuyUIManager.h"
#include "Item.h"
#include "InputControll.h"
#include "PlayerBag.h"
//CountItemMenu* CountItemMenu::AcCountItemMenu = nullptr;

CountItemMenu::CountItemMenu()
{
	//AcCountItemMenu = this;
}

CountItemMenu::~CountItemMenu()
{

}

void CountItemMenu::CountStart(Item& _Item)
{
	On();
	UpdateStart(_Item);
}

void CountItemMenu::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void CountItemMenu::Start()
{
	AcParent = BuyUIManager::GetBuyUIManager();

	SetPos(ActorPos);
	CountItemMenuRender = CreateRender("CountSelectItem.bmp", RenderOrder::Shop_CountItemMenu);
	CountItemMenuRender->EffectCameraOff();
	CountItemMenuRender->SetScaleToImage();

	CountNum.SetOwner(this);
	CountNum.SetNumOfDigits(2);
	CountNum.SetImage("SmallNum.bmp", NumRenderScale, static_cast<int>(RenderOrder::Shop_Dialog_Text), RGB(255,0,255));
	CountNum.SetAlign(Align::Left);
	CountNum.SetValue(Count);
	CountNum.SetRenderPos(CountNumRenderPos);

	PriceNum.SetOwner(this);
	PriceNum.SetImage("SmallNum.bmp", NumRenderScale, static_cast<int>(RenderOrder::Shop_Dialog_Text), RGB(255, 0, 255));
	PriceNum.SetAlign(Align::Right);
	PriceNum.SetValue(Price);
	PriceNum.SetRenderPos(PriceNumRenderPos);

	Up_ArrowRender = CreateRender(RenderOrder::Shop_CountItemMenu_Arrow);
	Up_ArrowRender->EffectCameraOff();
	Up_ArrowRender->CreateAnimation({ .AnimationName = "Arrow", .ImageName = "Arrow_CountItem_Up.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });
	Up_ArrowRender->SetScale(ArrowRenderScale);
	Up_ArrowRender->SetPosition(Up_Pos);
	Up_ArrowRender->ChangeAnimation("Arrow");

	Down_ArrowRender = CreateRender(RenderOrder::Shop_CountItemMenu_Arrow);
	Down_ArrowRender->EffectCameraOff();
	Down_ArrowRender->CreateAnimation({ .AnimationName = "Arrow", .ImageName = "Arrow_CountItem_Down.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });
	Down_ArrowRender->SetScale(ArrowRenderScale);
	Down_ArrowRender->SetPosition(Down_Pos);
	Down_ArrowRender->ChangeAnimation("Arrow");

	MoneySignRender = CreateRender("Money.bmp", RenderOrder::Shop_Dialog_Text);
	MoneySignRender->EffectCameraOff();
	MoneySignRender->SetScale(MoneySignRenderScale);

	Script = "Defalt Script";
	
	Off();
}

void CountItemMenu::MenuBeepSoundPlay()
{
	MenuBeepSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	MenuBeepSound.Volume(0.8f);
	MenuBeepSound.LoopCount(1);
}

void CountItemMenu::UpdateStart(Item& _Item)
{
	SetCount(1);
	SelectItem = &_Item;
	SetPrice(_Item.GetPrice());
	PriceNum.SetValue(Price * Count);
	BuyLevelDialog::GetBuyLevelDialog()->IsValid = false;
}

void CountItemMenu::Update(float _DeltaTime)
{
	MoneySignRender->SetPosition(PriceNumRenderPos + float4::Left * NumRenderScale * static_cast<float>(GameEngineMath::GetLenth(Price * Count)) + float4{ -8,0 });
	if (GameEngineInput::IsDown("Menu_Up"))
	{
		AddCount();
	}

	if (GameEngineInput::IsDown("Menu_Down"))
	{
		SubCount();
	}

	if (GameEngineInput::IsDown("Menu_Right"))
	{
		AddCount10();
	}

	if (GameEngineInput::IsDown("Menu_Left"))
	{
		SubCount10();
	}

	if (GameEngineInput::IsDown("B"))
	{
		AcParent->Off();
		Off();
		BuyWindow::GetBuyWindow()->InputControlHandle = InputControll::UseControll();
	}

	if (GameEngineInput::IsDown("A"))
	{
		AcParent->Off();
		Off();
		BuyYesNoMenu::GetBuyYesNoMenu()->On();
		BuyYesNoMenu::GetBuyYesNoMenu()->SetItemAndCount(*SelectItem, Count);
		Script = std::string(SelectItem->GetItemName().data() + std::string(", and you want ") + std::to_string(Count) + ".\nThat will be $" + std::to_string(Count * Price) + ". Okay?");
		Scripts.push_back(Script);
		BuyLevelDialog::GetBuyLevelDialog()->ConversationStart(&Scripts);
		BuyLevelDialog::GetBuyLevelDialog()->IsValid = false;
		
		//BuyWindow::GetBuyWindow()->IsValid = false;
	}
}

void CountItemMenu::UpdateEnd()
{
	if (nullptr == BuyWindow::GetBuyWindow())
	{
		return;
	}
	//BuyWindow::GetBuyWindow()->IsValid = true;
	if (Scripts.size() != 0)
	{
		Scripts.pop_back();
	}
}

void CountItemMenu::AddCount()
{
	Count++;
	if (Count > 99 || Price * Count > PlayerBag::MainBag->GetMoney())
	{
		Count = 1;
	}
	CountNum.SetValue(Count);
	PriceNum.SetValue(Price* Count);
	MenuBeepSoundPlay();
}

void CountItemMenu::AddCount10()
{
	int CountSave = Count;
	CountSave +=10;
	if (CountSave > 99 || CountSave*Price > PlayerBag::MainBag->GetMoney())
	{
		return;
	}
	Count = CountSave;
	CountNum.SetValue(Count);
	PriceNum.SetValue(Price * Count);
	MenuBeepSoundPlay();
}

void CountItemMenu::SubCount()
{
	Count--;
	if (Count < 1)
	{
		if (99*Price <= PlayerBag::MainBag->GetMoney())
		{
			Count = 99;
		}
		else
		{
			int i = 98;
			while (i* Price > PlayerBag::MainBag->GetMoney())
			{
				i--;
			}
			Count = i;
		}
	}
	CountNum.SetValue(Count);
	PriceNum.SetValue(Price * Count);
	MenuBeepSoundPlay();
}

void CountItemMenu::SubCount10()
{
	int CountSave = Count;
	CountSave -= 10;
	if (CountSave < 1)
	{
		return;
	}
	Count = CountSave;
	CountNum.SetValue(Count);
	PriceNum.SetValue(Price * Count);
	MenuBeepSoundPlay();
}

void CountItemMenu::SetCount(int _ItemCount)
{
	Count = _ItemCount;
	CountNum.SetValue(Count);
	PriceNum.SetValue(Price * Count);
	MenuBeepSoundPlay();
}

void CountItemMenu::SetPrice(int _ItemPrice)
{
	Price = _ItemPrice;
}




