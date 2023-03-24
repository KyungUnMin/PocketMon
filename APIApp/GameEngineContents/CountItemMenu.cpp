#include "CountItemMenu.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "BuyWindow.h"

CountItemMenu* CountItemMenu::AcCountItemMenu = nullptr;

CountItemMenu::CountItemMenu()
{
	AcCountItemMenu = this;
}

CountItemMenu::~CountItemMenu()
{

}

void CountItemMenu::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void CountItemMenu::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void CountItemMenu::OnOffSwtich()
{
	if (IsUpdate())
	{
		Off();
	}
	else
	{
		On();
	}
}

void CountItemMenu::Start()
{
	SetPos(ActorPos);
	CountItemMenuRender = CreateRender("CountSelectItem.bmp", RenderOrder::Shop_CountItemMenu);
	CountItemMenuRender->EffectCameraOff();
	CountItemMenuRender->SetScaleToImage();

	CountNum.SetOwner(this);
	CountNum.SetNumOfDigits(2);
	CountNum.SetImage("SmallNum.bmp", CountNumRenderScale, static_cast<int>(RenderOrder::Shop_Dialog_Text), RGB(255,0,255));
	CountNum.SetAlign(Align::Left);
	CountNum.SetValue(Count);
	CountNum.SetRenderPos(CountNumRenderPos);

	Off();
}

void CountItemMenu::UpdateStart()
{
	CountNum.SetValue(1);
	BuyWindow::GetBuyWindow()->IsValid = false;
}

void CountItemMenu::Update(float _DeltaTime)
{
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
		Off();
	}
}

void CountItemMenu::UpdateEnd()
{
	if (nullptr == BuyWindow::GetBuyWindow())
	{
		return;
	}
	BuyWindow::GetBuyWindow()->IsValid = true;
}

void CountItemMenu::AddCount()
{
	Count++;
	if (Count > 99)
	{
		Count = 1;
	}
	CountNum.SetValue(Count);
}

void CountItemMenu::AddCount10()
{
	int CountSave = Count;
	CountSave +=10;
	if (CountSave > 99)
	{
		return;
	}
	Count = CountSave;
	CountNum.SetValue(Count);
}

void CountItemMenu::SubCount()
{
	Count--;
	if (Count < 1)
	{
		Count = 99;
	}
	CountNum.SetValue(Count);
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
}




