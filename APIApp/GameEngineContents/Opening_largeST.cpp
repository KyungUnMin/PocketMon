#include "Opening_largeST.h"

#include <GameEngineCore/GameEngineRender.h>

Opening_largeST::Opening_largeST() 
{
}

Opening_largeST::~Opening_largeST() 
{
}

void Opening_largeST::Start()
{
	RenderPtr = CreateRender("Opening_largeST.bmp", 1);
	SetPos({ 0, 0 });
	RenderPtr->SetScale({ 0, 0.0f });
}

void Opening_largeST::Update(float _Deltatime)
{

}