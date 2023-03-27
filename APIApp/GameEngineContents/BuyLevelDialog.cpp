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
	FieldDialog::Start();
}

void BuyLevelDialog::Update(float _DeltaTime)
{
	FieldDialog::Update(_DeltaTime);
}
