#include "Logo_Pokemon.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

Logo_Pokemon::Logo_Pokemon() 
{
}

Logo_Pokemon::~Logo_Pokemon() 
{
}

void Logo_Pokemon::Start()
{
	RenderPtr = CreateRender(RenderOrder::FieldBack);
	RenderPtr->CreateAnimation({ .AnimationName = "Stop",  .ImageName = "Logo_Pokemon.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	RenderPtr->CreateAnimation({ .AnimationName = "Blink",  .ImageName = "Logo_Pokemon.bmp", .Start = 0, .End = 5, .InterTime = 0.1f });
	SetPos({ 350, 130 });
	RenderPtr->SetScale({ 664, 236 }); // { 166, 59 } x 4

	RenderPtr->ChangeAnimation("Stop");
}

void Logo_Pokemon::Update(float _Deltatime)
{

}