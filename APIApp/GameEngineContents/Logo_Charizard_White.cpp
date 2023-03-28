#include "Logo_Charizard_White.h"

#include <GameEngineCore/GameEngineRender.h>

Logo_Charizard_White::Logo_Charizard_White() 
{
}

Logo_Charizard_White::~Logo_Charizard_White() 
{
}

void Logo_Charizard_White::Start()
{
	RenderPtr = CreateRender("Logo_Charizard_White.bmp", 2);
	SetPos({ 680, 360 });
	RenderPtr->SetScale({444, 396});
}

void Logo_Charizard_White::Update(float _Deltatime)
{

}