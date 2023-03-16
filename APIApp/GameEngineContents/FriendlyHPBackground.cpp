#include "BackTextActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
BackTextActor::BackTextActor()
{
}

BackTextActor::~BackTextActor()
{
}

void BackTextActor::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().Bottom());
	GameEngineRender* RenderPtr = CreateRender("Combat_TextFrame.bmp", RenderOrder::BackGround);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
}