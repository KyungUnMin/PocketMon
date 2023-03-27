#include "BuyUIManager.h"
#include "BuyLevel.h"
#include "BuyLevelDialog.h"
#include "CountItemMenu.h"

BuyUIManager* BuyUIManager::AcBuyUIManager = nullptr;

BuyUIManager::BuyUIManager()
{
	AcBuyUIManager = this;
}

BuyUIManager::~BuyUIManager()
{

}

void BuyUIManager::On(TestItem& _Item)
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
	CountMenuScript.push_back("asdasdasdasdsa");
	Off();
}

void BuyUIManager::UpdateStart(TestItem& _Item)
{
	Item = &_Item;
	AcBuyLevelDialog->ConversationStart(&CountMenuScript);
}

void BuyUIManager::Update(float _DeltaTime)
{
	if (AcBuyLevelDialog->IsScriptPrintEnd() && !AcCountItemMenu->IsUpdate())
	{
		AcCountItemMenu->CountStart(*Item);
	}
}

void BuyUIManager::UpdateEnd()
{
	AcBuyLevelDialog->Off();
	AcCountItemMenu->Off();
}
