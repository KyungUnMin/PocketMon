#include "YesNoMenu.h"
#include <GameEngineCore/GameEngineRender.h>

YesNoMenu* YesNoMenu::MainYesNoMenu = nullptr;

YesNoMenu::YesNoMenu()
{
	MainYesNoMenu = this;
}

YesNoMenu::~YesNoMenu()
{

}

void YesNoMenu::Start()
{
	SetPos(ActorPos);

	MenuRender = CreateRender("YesNoMenu.bmp", RenderOrder::YesNoMenu);
	MenuRender->EffectCameraOff();
	MenuRender->SetScaleToImage();

	ArrowRender = CreateRender("MenuArrow.bmp", RenderOrder::YesNoMenu_Arrow);
	ArrowRender->EffectCameraOff();
	ArrowRender->SetScaleToImage();

	Off();
}

void YesNoMenu::Update(float _DeltaTime)
{
}
