#include "Logo_Fireredversion.h"

#include <GameEngineCore/GameEngineRender.h>

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
}

void Logo_Fireredversion::Update(float _Deltatime)
{

}