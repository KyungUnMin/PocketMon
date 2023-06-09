#include "BackGround.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

BackGround::BackGround() 
{
}

BackGround::~BackGround() 
{
}

void BackGround::Start() 
{
	{
		GameEngineRender* AnimationRender = CreateRender(RenderOrder::BackGround);
		AnimationRender->SetPosition(GameEngineWindow::GetScreenSize().half());
		AnimationRender->SetScale(GameEngineWindow::GetScreenSize());
		AnimationRender->CreateAnimation({ .AnimationName = "Loop",  .ImageName = "BackGround.bmp", .Start = 0, .End = 2, .InterTime = 0.5f });
		AnimationRender->ChangeAnimation("Loop");
	}

}