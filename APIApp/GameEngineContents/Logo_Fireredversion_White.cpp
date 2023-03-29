#include "Logo_Fireredversion_White.h"

#include <GameEngineCore/GameEngineRender.h>

Logo_Fireredversion_White* Logo_Fireredversion_White::FireWhitePtr = nullptr;
bool Logo_Fireredversion_White::FireBlink = false;

Logo_Fireredversion_White::Logo_Fireredversion_White() 
{
}

Logo_Fireredversion_White::~Logo_Fireredversion_White() 
{
}

void Logo_Fireredversion_White::Start()
{
	FireWhitePtr = this;

	RenderPtr = CreateRender("Logo_Fireredversion_White.bmp", 1);
	SetPos({ 350, 315 });
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
	RenderPtr->SetAlpha(0);
}

void Logo_Fireredversion_White::Update(float _Deltatime)
{
	if (true == IsBlink)
	{
		BlinkAnimation(_Deltatime);
	}
}

void Logo_Fireredversion_White::BlinkAnimation(float _Deltatime)
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
				FireBlink = true;
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