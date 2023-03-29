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
	if (true == IsBlinkStart)
	{
		Blink(_Deltatime);
	}
}

void Logo_PressStart::Blink(float _Deltatime)
{
	BlinkTime += _Deltatime;

	if (3.0f <= BlinkTime)
	{
		BlinkTime = 0.0f;
		RenderOff = false;
	}
	else if (2.0f <= BlinkTime)
	{
		RenderOff = true;
	}

	if (false == RenderOff)
	{
		RenderPtr->On();
	}
	else
	{
		RenderPtr->Off();
	}
}