#include "BlackBox.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

BlackBox::BlackBox() 
{
}

BlackBox::~BlackBox() 
{
}

void BlackBox::Start()
{
	GameEngineRender* RenderPtr = CreateRender("CenterActor.bmp", 0);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}

void BlackBox::Update(float _Deltatime)
{

}