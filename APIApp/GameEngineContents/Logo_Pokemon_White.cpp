#include "Logo_Pokemon_White.h"

#include <GameEngineCore/GameEngineRender.h>

Logo_Pokemon_White* Logo_Pokemon_White::PokeWhitePtr = nullptr;
bool Logo_Pokemon_White::PokeBlink = false;

Logo_Pokemon_White::Logo_Pokemon_White() 
{
}

Logo_Pokemon_White::~Logo_Pokemon_White() 
{
}

void Logo_Pokemon_White::Start()
{
	RenderPtr = CreateRender("Logo_Pokemon_White.bmp", 2);
	SetPos({ 350, 130 });
	RenderPtr->SetScale({ 664, 236 });
	RenderPtr->SetAlpha(0);
}

void Logo_Pokemon_White::Update(float _Deltatime)
{
	if (true == IsBlink)
	{
		BlinkAnimation(_Deltatime);
	}
}

void Logo_Pokemon_White::BlinkAnimation(float _Deltatime)
{
	BlinkTime += _Deltatime;

	if (false == BlinkUp && 0.01f <= BlinkTime)
	{
		BlinkTime = 0.0f;

		if (225 >= BlinkValue)
		{
			BlinkValue += 25;
			RenderPtr->SetAlpha(BlinkValue);

			if (250 == BlinkValue)
			{
				BlinkUp = true;
				PokeBlink = true;
			}
		}
	}

	if (true == BlinkUp && 0.05f <= BlinkTime)
	{
		BlinkTime = 0.0f;

		if (10 <= BlinkValue)
		{
			BlinkValue -= 10;
			RenderPtr->SetAlpha(BlinkValue);

			if (0 == BlinkValue)
			{
				BlinkUp = false;
				IsBlink = false;
			}
		}
	}
}