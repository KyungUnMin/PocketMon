#include "Logo_Fireredversion.h"

#include <GameEngineCore/GameEngineRender.h>

#include "Logo_Fireredversion_White.h"

Logo_Fireredversion::Logo_Fireredversion() 
{
}

Logo_Fireredversion::~Logo_Fireredversion() 
{
}

void Logo_Fireredversion::Start()
{
	RenderPtr = CreateRender("Logo_Fireredversion.bmp", 1);
	SetPos({350, 315});
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
	RenderPtr->Off();
}

void Logo_Fireredversion::Update(float _Deltatime)
{
	if (true == Logo_Fireredversion_White::FireWhitePtr->FireBlink)
	{
		RenderPtr->On();
	}
}