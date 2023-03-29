#include "Logo_Back2.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Logo_Back2::Logo_Back2() 
{
}

Logo_Back2::~Logo_Back2() 
{
}

void Logo_Back2::Start()
{
	RenderPtr = CreateRender("Logo_Back2.bmp", 0);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
}

void Logo_Back2::Update(float _Deltatime)
{

}