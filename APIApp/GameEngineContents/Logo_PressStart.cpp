#include "Logo_PressStart.h"

#include <GameEngineCore/GameEngineRender.h>

Logo_PressStart::Logo_PressStart() 
{
}

Logo_PressStart::~Logo_PressStart() 
{
}

void Logo_PressStart::Start()
{
	RenderPtr = CreateRender("Logo_PressStart.bmp", 2);
	SetPos({350, 520});
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
}

void Logo_PressStart::Update(float _Deltatime)
{

}