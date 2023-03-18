#include "FieldmapLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "Fieldmap.h"
#include "FieldmapCity.h"
#include "Player.h"
#include "FieldDialog.h"
#include "int2.h"

FieldmapLevel::FieldmapLevel()
{
}

FieldmapLevel::~FieldmapLevel()
{
}

void FieldmapLevel::Loading()
{
	{
		FieldmapCity* PalletTownPtr = CreateActor<FieldmapCity>();

		PalletTownPtr->InitFieldRender("PalletTown.bmp");
		PalletTownPtr->InitPos(float4::Zero);

		Fieldmap::AddCity("PalletTown", PalletTownPtr);
	}

	Fieldmap::ChangeCity("PalletTown");

	ImageLoad();

	MainFieldRender = CreateActor<FieldmapRender>();
	MainPlayer = CreateActor<Player>();
	MainPlayer->SetPos(Fieldmap::GetPos(0, 0));
	MainFieldDialog = CreateActor<FieldDialog>();
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

	if (GameEngineInput::IsDown("FieldDialogSwitch"))
	{
		MainFieldDialog->OnOffSwtich();
	}

	MainFieldRender->RenderPosUpdate(MainPlayer->GetPos());
}

void FieldmapLevel::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("FieldUI_HSM");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Npc_TextFrame.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_Dialog.bmp"))->Cut(27, 4);
}
