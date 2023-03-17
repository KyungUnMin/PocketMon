#include "FieldmapLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "Fieldmap.h"
#include "FieldmapRender.h"
#include "Player.h"
#include "int2.h"

FieldmapLevel::FieldmapLevel()
{
}

FieldmapLevel::~FieldmapLevel()
{
}

void FieldmapLevel::Loading()
{
	MainFieldRender = CreateActor<FieldmapRender>();
	MainPlayer = CreateActor<Player>();
	MainPlayer->SetPos(float4::Zero);

	Fieldmap::AddFieldData("TempMap", "Test.data");
	Fieldmap::ChangeField("TempMap");
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
			SetCameraMove(float4::Down * 200.0f * _DeltaTime);
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveDown"))
		{
			SetCameraMove(float4::Up * 200.0f * _DeltaTime);
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveLeft"))
		{
			SetCameraMove(float4::Right * 200.0f * _DeltaTime);
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveRight"))
		{
			SetCameraMove(float4::Left * 200.0f * _DeltaTime);
		}

		int2 PlayerIndex = Fieldmap::GetIndex(MainPlayer->GetPos());

		DebugTextPush("PlayerIndex : " + PlayerIndex.ToString());
	}
	else
	{
		SetCameraPos(MainPlayer->GetPos() - GameEngineWindow::GetScreenSize().half());
	}

	MainFieldRender->RenderPosUpdate(MainPlayer->GetPos());
}
