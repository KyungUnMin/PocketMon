#include "BackgroundUI.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include <GameEnginePlatform/GameEngineWindow.h>

BackgroundUI::BackgroundUI()
{
}

BackgroundUI::~BackgroundUI()
{
}

void BackgroundUI::Start()
{
	float4 WindowSize = GameEngineWindow::GetScreenSize();

	GameEngineRender* RenderPtr = CreateRender("Background.bmp", RenderOrder::BackGround);
	RenderPtr->SetScale(WindowSize);
	RenderPtr->EffectCameraOff();

	SetPos(WindowSize.half());
}
