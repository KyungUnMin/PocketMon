#include "Opening_smallST.h"

#include <GameEngineCore/GameEngineRender.h>

Opening_smallST::Opening_smallST() 
{
}

Opening_smallST::~Opening_smallST() 
{
}

void Opening_smallST::Start()
{
	RenderPtr = CreateRender("Opening_smallST.bmp", 1);
	SetPos({ 0, 0 });
	RenderPtr->SetScale({ 0, 0.0f });
}

void Opening_smallST::Update(float _Deltatime)
{

}