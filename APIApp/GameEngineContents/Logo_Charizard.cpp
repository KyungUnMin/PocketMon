#include "Logo_Charizard.h"

#include <GameEngineCore/GameEngineRender.h>

#include "Logo_Charizard_White.h"
#include "ContentsEnum.h"

void Logo_Charizard::ChangeColor(ZardColor _Color)
{
	ColorSelect = _Color;

	switch (ColorSelect)
	{
	case ZardColor::Gray:
		RenderPtr->ChangeAnimation("Gray");
		break;
	case ZardColor::Origin:
		RenderPtr->ChangeAnimation("Origin");
		break;
	default:
		break;
	}
}

Logo_Charizard::Logo_Charizard() 
{
}

Logo_Charizard::~Logo_Charizard() 
{
}

void Logo_Charizard::Start()
{
	RenderPtr = CreateRender(RenderOrder::FieldBack);
	RenderPtr->CreateAnimation({ .AnimationName = "Gray",  .ImageName = "Logo_Charizard.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	RenderPtr->CreateAnimation({ .AnimationName = "Origin",  .ImageName = "Logo_Charizard.bmp", .Start = 1, .End = 1, .InterTime = 0.1f });
	SetPos({ 680, 360 });
	RenderPtr->SetScale({ 444, 396 });

	RenderPtr->ChangeAnimation("Gray");
	RenderPtr->SetAlpha(0);
}

void Logo_Charizard::Update(float _Deltatime)
{
	if (true == IsGrayStart)
	{
		GaryAnimaion(_Deltatime);
	}

	if (true == Logo_Charizard_White::ZardWhitePtr->OriginBlink)
	{
		RenderPtr->ChangeAnimation("Origin");
	}
}

// 8´Ü°è
void Logo_Charizard::GaryAnimaion(float _Deltatime)
{
	GrayTime += _Deltatime;

	if (GrayTime >= 1.6f)
	{
		RenderPtr->SetAlpha(255);
	}
	else if (GrayTime >= 1.4f)
	{
		RenderPtr->SetAlpha(230);
	}
	else if (GrayTime >= 1.2f)
	{
		RenderPtr->SetAlpha(200);
	}
	else if (GrayTime >= 1.0f)
	{
		RenderPtr->SetAlpha(150);
	}
	else if (GrayTime >= 0.8f)
	{
		RenderPtr->SetAlpha(120);
	}
	else if (GrayTime >= 0.6f)
	{
		RenderPtr->SetAlpha(90);
	}
	else if (GrayTime >= 0.4f)
	{
		RenderPtr->SetAlpha(60);
	}
	else if (GrayTime >= 0.2f)
	{
		RenderPtr->SetAlpha(30);
	}
	
}