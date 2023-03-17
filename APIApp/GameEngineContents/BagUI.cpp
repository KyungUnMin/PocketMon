#include "BagUI.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
BagUI::BagUI() {

}

BagUI::~BagUI() {

}

void BagUI::Start()
{
	GameEngineRender* BackUI = CreateRender("Bag_Back.bmp", RenderOrder::BackGround);
	BackUI->SetScaleToImage();
	BackUI->SetPosition(BackUI->GetScale().half());

	GameEngineRender* BagRender = CreateRender("Bag_LeftOpen.bmp", RenderOrder::Player);
	BagRender->SetScaleToImage();
	BagRender->SetPosition({160, 276});
}

void BagUI::Update(float _DeltaTime)
{
}
