#include "Opening_Star.h"

#include <GameEngineCore/GameEngineRender.h>

Opening_Star::Opening_Star() 
{
}

Opening_Star::~Opening_Star() 
{
}

void Opening_Star::Start()
{
	RenderPtr = CreateRender("Opening_Star.bmp", 1);
	SetPos({ 0, 0 });
	RenderPtr->SetScale({ 0, 0.0f });
}

void Opening_Star::Update(float _Deltatime)
{

}