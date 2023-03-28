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
	EndPos = StartPos + (float4::Up * Winsize_h.y);

	DownStartPos = float4::Down * Winsize_h.y * 2;
	DownEndPos = -DownStartPos + (float4::Up * Winsize_h.y);

	RenderPtr = CreateRender("MoveMapFade1.bmp", 3);
	SetPos(Winsize_h);
	RenderPtr->SetScale(GameEngineWindow::GetScreenSize());
}

void EffectBlackBox::Update(float _Deltatime)
{
	if (true == IsStart)
	{
		MoveUp(_Deltatime);
	}

	if (true == IsDownStart)
	{
		MoveUp_Down(_Deltatime);
	}
}

void EffectBlackBox::MoveUp(float _Deltatime)
{
	MoveTime += _Deltatime * 0.005f;

	float4 Pos = float4::LerpClamp(StartPos, EndPos, MoveTime);
	SetMove(Pos);
}

void EffectBlackBox::MoveUp_Down(float _Deltatime)
{
	MoveTime += _Deltatime * 0.005f;

	float4 Pos = float4::LerpClamp(DownStartPos, DownEndPos, MoveTime);
	SetMove(Pos);
}