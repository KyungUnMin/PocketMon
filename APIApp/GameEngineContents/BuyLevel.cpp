#include "BuyLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BuyWindow.h"
#include "ShopUIManager.h"

BuyLevel::BuyLevel()
{

}

BuyLevel::~BuyLevel()
{

}

void BuyLevel::Loading()
{
	ImageLoad();
	AcBuyWindow = CreateActor<BuyWindow>();
}

void BuyLevel::Update(float _DeltaTime)
{
}

void BuyLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	ShopUIManager::GetShopUIManager()->ReturnMainStart();
}

void BuyLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SmallNum.bmp"))->Cut(10,1);
}