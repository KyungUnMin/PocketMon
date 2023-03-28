#include "Logo_Charizard_White.h"

#include <GameEngineCore/GameEngineRender.h>

#include "OpeningLevel.h"
#include "EffectBlackBox.h"

Logo_Charizard_White* Logo_Charizard_White::ZardWhitePtr = nullptr;
bool Logo_Charizard_White::OriginBlink = false;
int Logo_Charizard_White::OffCount1 = 1;

Logo_Charizard_White::Logo_Charizard_White() 
{
}

Logo_Charizard_White::~Logo_Charizard_White() 
{
}

void Logo_Charizard_White::Start()
{
	ZardWhitePtr = this;
	RenderPtr = CreateRender("Logo_Charizard_White.bmp", 2);
	SetPos({ 680, 360 });
	RenderPtr->SetScale({444, 396});
}

void Logo_Charizard_White::Update(float _Deltatime)
{
	if (1 == OffCount1 && true == OpeningLevel::GetOpeningLevelPtr()->GetEffectBlackBox2()->IsEnd())
	{
		OffCount1 = 0;
		RenderPtr->SetAlpha(0);
	}

	if (false == BlinkDown)
	{
		BlinkAnimation(_Deltatime);
	}

	if (true == IsBlink)
	{
		OriginBlinkAnimation(_Deltatime);
	}
}

void Logo_Charizard_White::BlinkAnimation(float _Deltatime)
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
			}
		}
	}

	if (false == BlinkDown && true == BlinkUp && 0.01f <= BlinkTime)
	{
		BlinkTime = 0.0f;

		if (25 <= BlinkValue)
		{
			BlinkValue -= 25;
			RenderPtr->SetAlpha(BlinkValue);

			if (0 == BlinkValue)
			{
				BlinkDown = true;
				BlinkUp = false;
			}
		}
	}
}

void Logo_Charizard_White::OriginBlinkAnimation(float _Deltatime)
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
				OriginBlink = true;
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