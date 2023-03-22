#include "ShopUIManager.h"
#include "FieldmapLevel.h"
#include "ShopMainMenu.h"
#include "FieldDialog.h"

ShopUIManager* ShopUIManager::AcShopUIManager = nullptr;

ShopUIManager::ShopUIManager()
{
	AcShopUIManager = this;
}

ShopUIManager::~ShopUIManager()
{

}

void ShopUIManager::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void ShopUIManager::Off()
{
	GameEngineObject::Off();
	AcShopMainMenu->Off();
}

void ShopUIManager::LeaveShop()
{
	GameEngineObject::Off();
	AcShopMainMenu->Off();
	UpdateEnd();
}

void ShopUIManager::OnOffSwtich()
{
	if (IsUpdate())
	{
		LeaveShop();
	}
	else
	{
		On();
	}
}

void ShopUIManager::Start()
{
	ParentLevel = dynamic_cast<FieldmapLevel*>(GetLevel());
	AcShopMainMenu = ParentLevel->CreateActor<ShopMainMenu>();
	AcFielDialog = FieldDialog::GetFieldDialog();

	WelcomeScript.emplace_back("Hi, there!\nMay I help you?");

	GoodbyeScript.emplace_back("Please come again!");
	Off();
}

void ShopUIManager::UpdateStart()
{
	AcFielDialog->ConversationStart(&WelcomeScript);
}


void ShopUIManager::Update(float _DeltaTime)
{
	if (AcFielDialog->IsScriptPrintEnd() && !AcShopMainMenu->IsUpdate())
	{
		AcShopMainMenu->On();
	}
}

void ShopUIManager::UpdateEnd()
{
	AcFielDialog->ConversationStart(&GoodbyeScript);
}

