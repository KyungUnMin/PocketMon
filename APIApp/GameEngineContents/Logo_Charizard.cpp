#include "Logo_Charizard.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

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
}

void Logo_Charizard::Update(float _Deltatime)
{

}

void Logo_Charizard::ColorChange()
{
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