#include "Opening_Text.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

//GameEngineRender* Opening_Text::RenderPtr = nullptr;
//int Opening_Text::Alphavalue = 255;

Opening_Text::Opening_Text() 
{
}

Opening_Text::~Opening_Text() 
{
}

void Opening_Text::Start()
{
	RenderPtr = CreateRender("Opening_Text.bmp", 0);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}

void Opening_Text::Update(float _Deltatime)
{
	AlphaTime += _Deltatime;

	AlphaControl(AlphaTime);
}

void Opening_Text::AlphaControl(float _Deltatime)
{
	if (1 <= Alphavalue && AlphaTime <= 0.1f)
	{
		AlphaTime = 0.0f;
		--Alphavalue;
		RenderPtr->SetAlpha(Alphavalue);
	}
}