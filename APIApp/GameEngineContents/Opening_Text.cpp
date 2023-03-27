#include "Opening_Text.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Opening_Text::Opening_Text() 
{
}

Opening_Text::~Opening_Text() 
{
}

void Opening_Text::Start()
{
	GameEngineRender* RenderPtr = CreateRender("Opening_Text.bmp", 0);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}

void Opening_Text::Update(float _Deltatime)
{

}

void Opening_Text::AlphaControl()
{

}