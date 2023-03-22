#include "ShopUIManager.h"
#include "FieldmapLevel.h"
#include "ShopMainMenu.h"
#include "FieldDialog.h"

ShopUIManager::ShopUIManager()
{

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

void ShopUIManager::OnOffSwtich()
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

void ShopUIManager::Start()
{
	ParentLevel = dynamic_cast<FieldmapLevel*>(GetLevel());
	AcShopMainMenu = ParentLevel->CreateActor<ShopMainMenu>();
	AcFielDialog = FieldDialog::GetFieldDialog();

	WelcomeScript.emplace_back("Hi, there!\nMay I help you?");
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


