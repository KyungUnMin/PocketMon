#include "FieldmapLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>

#include "FieldmapRender.h"

FieldmapLevel::FieldmapLevel()
{
}

FieldmapLevel::~FieldmapLevel()
{
}

void FieldmapLevel::Loading()
{
	MainFieldRender = CreateActor<FieldmapRender>();
}

void FieldmapLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("FreeCamera"))
	{
		IsCameraDebug = !IsCameraDebug;
	}

	if (true == IsCameraDebug)
	{
		DebugTextPush("FREE CAMERA MODE");

		if (true == GameEngineInput::IsPress("FreeCameraMoveUp"))
		{
			FreeCameraPos += float4::Down * 200.0f * _DeltaTime;
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveDown"))
		{
			FreeCameraPos += float4::Up * 200.0f * _DeltaTime;
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveLeft"))
		{
			FreeCameraPos += float4::Right * 200.0f * _DeltaTime;
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveRight"))
		{
			FreeCameraPos += float4::Left * 200.0f * _DeltaTime;
		}

		MainFieldRender->RenderPosUpdate(FreeCameraPos);
	}
	else
	{
		// Todo : Player 위치로 변경
		MainFieldRender->RenderPosUpdate(FreeCameraPos);
	}

}
