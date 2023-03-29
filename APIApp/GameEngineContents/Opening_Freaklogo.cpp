#include "Opening_Freaklogo.h"

#include <GameEngineCore/GameEngineRender.h>

Opening_Freaklogo::Opening_Freaklogo() 
{
}

Opening_Freaklogo::~Opening_Freaklogo() 
{
}

void Opening_Freaklogo::Start()
{
	RenderPtr = CreateRender("Opening_Freaklogo.bmp", 1);
	SetPos({ 0, 0 });
	RenderPtr->SetScale({ 0, 0.0f });
}

void Opening_Freaklogo::Update(float _Deltatime)
{

}