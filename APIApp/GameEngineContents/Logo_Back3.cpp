#include "Logo_Back3.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Logo_Back3::Logo_Back3() 
{
}

Logo_Back3::~Logo_Back3() 
{
}

void Logo_Back3::Start()
{
	RenderPtr = CreateRender("Logo_Back3.bmp", 1);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
}

void Logo_Back3::Update(float _Deltatime)
{

}