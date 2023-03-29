#include "EffectBlackBox.h"

#include <GameEngineBase/GameEngineMath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "Logo_Charizard_White.h"

bool EffectBlackBox::IsDownEnd = false;

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

	DownStartPos = float4::Zero;
	DownEndPos = DownStartPos + (float4::Up * Winsize_h.y);

	RenderPtr = CreateRender("BlackBox.bmp", 4);
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

	if (true == IsStart_Alpha)
	{
		RenderPtr->SetAlpha(150);
		MoveUp(_Deltatime);
	}

	if (true == IsDownStart_Alpha)
	{
		RenderPtr->SetAlpha(150);
		MoveUp_Down(_Deltatime);
	}

	if (true == IsStart_Alpha2)
	{
		RenderPtr->SetAlpha(100);
		MoveUp(_Deltatime);
	}

	if (true == IsDownStart_Alpha2)
	{
		RenderPtr->SetAlpha(100);
		MoveUp_Down(_Deltatime);
	}

	if (0 == Logo_Charizard_White::ZardWhitePtr->OffCount1)
	{
		RenderPtr->Off();
	}
}

void EffectBlackBox::MoveUp(float _Deltatime)
{
	MoveTime += _Deltatime * 0.01f;

	float4 Pos = float4::LerpClamp(StartPos, EndPos, MoveTime);
	SetMove(Pos);
}

void EffectBlackBox::MoveUp_Down(float _Deltatime)
{
	MoveTime += _Deltatime * 0.01f;

	float4 Pos = float4::LerpClamp(DownStartPos, DownEndPos, MoveTime);

	if (360.0f <= GetPos().y)
	{
		SetMove(Pos);
	}
	else
	{
		IsDownEnd = true;
	}
}