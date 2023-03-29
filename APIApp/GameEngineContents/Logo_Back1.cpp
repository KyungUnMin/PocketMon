#include "Logo_Back1.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Logo_Back1::Logo_Back1() 
{
}

Logo_Back1::~Logo_Back1() 
{
}

void Logo_Back1::Start()
{
	RenderPtr = CreateRender("Logo_Back1.bmp", 1);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
}

void Logo_Back1::Update(float _Deltatime)
{

}