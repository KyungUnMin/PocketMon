#include "EffectBlackBox.h"

#include <GameEngineBase/GameEngineMath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

EffectBlackBox::EffectBlackBox() 
{
}

EffectBlackBox::~EffectBlackBox() 
{
}

void EffectBlackBox::Start()
{
	Winsize_h = GameEngineWindow::GetScreenSize().half();

	StartPos = float4::Zero;
	EndPos = Winsize_h;

	RenderPtr = CreateRender("MoveMapFade1.bmp", 3);
	SetPos(Winsize_h);
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}

void EffectBlackBox::Update(float _Deltatime)
{

}

void EffectBlackBox::MoveUp()
{
	GameEngineMath::Lerp(Winsize_h.x, Winsize_h.x - Winsize_h.x, 1.0f);
	// float4 Pos = float4::LerpClamp(Start, End, Time);
	//SetMove();
}


// float4 DownPosTitle = float4::Zero;

//void EffectBlackBox::Update(float _DeltaTime)
//{
//
//	if (true == GameEngineInput::IsDown("TitleScrollLeft"))
//	{
//		End = Start + float4(-GameEngineWindow::GetScreenSize().half().x, 0.0f);
//	}
//
//	// 시작에서 끝까지 이동하는데 1초가 걸리는 함수
//	Time += _DeltaTime * 0.5f;
//	float4 Pos = float4::LerpClamp(Start, End, Time);
//	SetCameraPos(Pos);
//
//	if (Time >= 1.0f)
//	{
//		ScrollStart = false;
//		Time = 0.0f;
//	}
//}
