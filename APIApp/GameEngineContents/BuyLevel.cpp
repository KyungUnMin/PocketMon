#include "BuyLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BuyWindow.h"
#include "ShopUIManager.h"
#include "BuyYesNoMenu.h"
#include "BuyLevelDialog.h"
#include "BuyUIManager.h"

BuyLevel::BuyLevel()
{

}

BuyLevel::~BuyLevel()
{

}

void BuyLevel::Loading()
{
	ImageLoad();
	AcBuyLevelDialog = CreateActor<BuyLevelDialog>();
	AcBuyWindow = CreateActor<BuyWindow>();
	AcBuyYesNoMenu = CreateActor<BuyYesNoMenu>();
	AcBuyUIManager = CreateActor<BuyUIManager>();
}

void BuyLevel::Update(float _DeltaTime)
{
}

void BuyLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	ShopUIManager::GetShopUIManager()->ReturnMainStart();
	AcBuyWindow->Off();
}

void BuyLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	AcBuyWindow->On();
	AcBuyWindow->ChangeState(0);
}

void BuyLevel::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("FieldUI_HSM");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_Buy.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PressMenuArrow.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CountSelectItem.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SmallNum.bmp"))->Cut(10, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_Yes.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_No.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_Dialog_Back.bmp"));
}