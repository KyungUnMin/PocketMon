#include "Logo_Charizard_White.h"

#include <GameEngineCore/GameEngineRender.h>

#include "OpeningLevel.h"
#include "EffectBlackBox.h"

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
	if (true == OpeningLevel::GetOpeningLevelPtr()->GetEffectBlackBox2()->IsEnd())
	{
		RenderPtr->Death();
	}
}