#include "TestActor.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

TestActor::TestActor()
{

}

TestActor::~TestActor()
{

}

void TestActor::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());

	GameEngineRender* RenderPtr = CreateRender("Test.bmp", 0);
	RenderPtr->SetScale(float4{ 200.f, 200.f });
}
