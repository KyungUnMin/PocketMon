#include "CenterActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

CenterActor::CenterActor() 
{
}

CenterActor::~CenterActor() 
{
}

void CenterActor::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	GameEngineRender* RenderPtr = CreateRender("CenterActor.bmp", 0);
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}