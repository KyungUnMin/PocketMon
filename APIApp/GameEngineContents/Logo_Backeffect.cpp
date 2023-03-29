#include "Logo_Backeffect.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

Logo_Backeffect::Logo_Backeffect() 
{
}

Logo_Backeffect::~Logo_Backeffect() 
{
}

void Logo_Backeffect::Start()
{
	RenderPtr = CreateRender(RenderOrder::BackGround);
	RenderPtr->CreateAnimation({ .AnimationName = "Burnning",  .ImageName = "Logo_Backeffect.bmp", .Start = 0, .End = 5, .InterTime = 0.15f });
	SetPos({ 470, 380 });
	RenderPtr->SetScale({ 1024, 1024 });

	RenderPtr->ChangeAnimation("Burnning");
}

void Logo_Backeffect::Update(float _Deltatime)
{

}