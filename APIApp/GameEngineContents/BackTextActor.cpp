#include "BackTextActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

BackTextActor::BackTextActor()
{
}

BackTextActor::~BackTextActor()
{
}

void BackTextActor::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().Bottom());
	GameEngineRender* RenderPtr = CreateRender("Combat_TextFrame.bmp", 0);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale())*4);
}