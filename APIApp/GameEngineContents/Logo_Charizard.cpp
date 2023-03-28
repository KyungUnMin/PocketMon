#include "Logo_Charizard.h"

#include <GameEngineCore/GameEngineRender.h>

Logo_Charizard::Logo_Charizard() 
{
}

Logo_Charizard::~Logo_Charizard() 
{
}

void Logo_Charizard::Start()
{
	RenderPtr = CreateRender("Opening_Text.bmp", 0);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}

void Logo_Charizard::Update(float _Deltatime)
{

}