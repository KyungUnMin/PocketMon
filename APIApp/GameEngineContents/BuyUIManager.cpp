#include "BuyUIManager.h"
#include "BuyLevel.h"
#include "BuyLevelDialog.h"
#include "CountItemMenu.h"
#include "BuyWindow.h"
#include "Item.h"
#include "InputControll.h"

BuyUIManager* BuyUIManager::AcBuyUIManager = nullptr;

BuyUIManager::BuyUIManager()
{
	AcBuyUIManager = this;
}

BuyUIManager::~BuyUIManager()
{

}

void BuyUIManager::On(Item& _Item)
{
	GameEngineObject::On();
	UpdateStart(_Item);
}

void BuyUIManager::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void BuyUIManager::Start()
{
	Parent = dynamic_cast<BuyLevel*>(GetLevel());
	AcBuyLevelDialog = BuyLevelDialog::GetBuyLevelDialog();
	AcCountItemMenu = Parent->CreateActor<CountItemMenu>();
	Script = "Default Script";
	Off();
}

void BuyUIManager::UpdateStart(Item& _Item)
{
	SelectItem = &_Item;
	Script = std::string(SelectItem->GetItemName().data() + std::string("? Certainly.\nHow many would you like?"));
	Scripts.push_back(Script);
	AcBuyLevelDialog->ConversationStart(&Scripts);
	InputControllHandle = InputControll::UseControll();
}

void BuyUIManager::Update(float _DeltaTime)
{
	if (AcBuyLevelDialog->IsAllScriptPrintEnd() && !AcCountItemMenu->IsUpdate())
	{
		AcCountItemMenu->CountStart(*SelectItem);
	}
}

void BuyUIManager::UpdateEnd()
{
	AcBuyLevelDialog->Off();
	AcCountItemMenu->Off();
	if (Scripts.size() != 0)
	{
		Scripts.pop_back();
	}
	InputControllHandle = InputControll::ResetControll(InputControllHandle);
}
