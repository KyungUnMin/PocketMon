#include "BuyLevelDialog.h"
#include "BuyWindow.h"

BuyLevelDialog* BuyLevelDialog::AcBuyLevelDialog = nullptr;

BuyLevelDialog::BuyLevelDialog()
{
	AcBuyLevelDialog = this;
}

BuyLevelDialog::~BuyLevelDialog()
{

}
//
//void BuyLevelDialog::Off()
//{
//	if (BuyWindow::GetBuyWindow() == nullptr)
//	{
//		return;
//	}
//	FieldDialog::Off();
//	//BuyWindow::GetBuyWindow()->IsValid = true;
//}

void BuyLevelDialog::Start()
{
	SetPos(ActorPos);
	FieldDialog::Start();
	FieldDialog::ChangeRenderOrder(RenderOrder::Shop_Dialog);
	DialogBack = CreateRender("Shop_Dialog_Back.bmp", RenderOrder::Shop_Dialog_Back);
	DialogBack->EffectCameraOff();
	DialogBack->SetScale(DialogBackScale);
}

void BuyLevelDialog::Update(float _DeltaTime)
{
	FieldDialog::Update(_DeltaTime);
}
