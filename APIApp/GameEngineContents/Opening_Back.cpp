#include "Opening_Back.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Opening_Back::Opening_Back() 
{
}

Opening_Back::~Opening_Back() 
{
}

void Opening_Back::Start()
{
	float XPos = GameEngineWindow::GetScreenSize().half().x;
	float YPos = GameEngineWindow::GetScreenSize().half().y;

	RenderPtr = CreateRender("Logo_Back1.bmp", 1);
	SetPos({ XPos, YPos });
	RenderPtr->SetScale({XPos, 0.0f});
}

void Opening_Back::Update(float _Deltatime)
{
}