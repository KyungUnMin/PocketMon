#include "BuyLevelDialog.h"

BuyLevelDialog* BuyLevelDialog::AcBuyLevelDialog = nullptr;

BuyLevelDialog::BuyLevelDialog()
{
	AcBuyLevelDialog = this;
}

BuyLevelDialog::~BuyLevelDialog()
{

}

void BuyLevelDialog::Start()
{
	FieldDialog::Start();
}

void BuyLevelDialog::Update(float _DeltaTime)
{
	FieldDialog::Update(_DeltaTime);
}
