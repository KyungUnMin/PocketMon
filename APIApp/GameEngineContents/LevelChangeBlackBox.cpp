#include "LevelChangeBlackBox.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

LevelChangeBlackBox::LevelChangeBlackBox() 
{
}

LevelChangeBlackBox::~LevelChangeBlackBox() 
{
}

void LevelChangeBlackBox::Start()
{
	RenderPtr = CreateRender("BlackBox.bmp", 5);
	SetPos(GameEngineWindow::GetScreenSize().half());
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
	RenderPtr->SetAlpha(0);
}

void LevelChangeBlackBox::Update(float _Deltatime)
{
	if (true == IsStart)
	{
		AlphaSet(_Deltatime);
	}
}

void LevelChangeBlackBox::AlphaSet(float _Deltatime)
{
	AlphaTime += _Deltatime;

	if (0.0005f <= AlphaTime)
	{
		AlphaTime = 0.0f;

		if (254 >= AlphaValue)
		{
			++AlphaValue;
			RenderPtr->SetAlpha(AlphaValue);
		}

		if (255 == AlphaValue)
		{
			IsEnd = true;
		}
	}
}