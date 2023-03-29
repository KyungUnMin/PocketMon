#include "Logo_Back1.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Logo_Back1::Logo_Back1() 
{
}

Logo_Back1::~Logo_Back1() 
{
}

void Logo_Back1::Start()
{
	float XPos = GameEngineWindow::GetScreenSize().half().x;
	float YPos = GameEngineWindow::GetScreenSize().half().y;

	RenderPtr = CreateRender("Logo_Back1.bmp", 1);
	SetPos({ XPos * 3 , YPos });
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());

	StartPos = GetPos();
	EndPos = StartPos + float4{ -GameEngineWindow::GetScreenSize().half().x * 2, 0 };
}

void Logo_Back1::Update(float _Deltatime)
{
	if (true == IsStart)
	{
		MoveTime += _Deltatime * 3.0f;

		float4 Pos = float4::LerpClamp(StartPos, EndPos, MoveTime);
		SetPos(Pos);

		if (MoveTime >= 1.0f)
		{
			IsStart = false;
			MoveTime = 0.0f;
		}
	}
}