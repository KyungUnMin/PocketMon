#include "FieldmapLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "Fieldmap.h"
#include "FieldmapCity.h"
#include "Player.h"
#include "FieldDialog.h"
#include "int2.h"
#include "FieldmapRender.h"

float4 FieldmapLevel::PlayerPos = float4::Zero;

FieldmapLevel::FieldmapLevel()
{
}

FieldmapLevel::~FieldmapLevel()
{
}

void FieldmapLevel::Loading()
{
	{
		CreateFieldmapCity("PalletTown", "PalletTown", float4::Zero);
		CreateFieldmapCity("Route1", "Route1", float4(0.0f, -2240.0f));
		CreateFieldmapCity("ViridianCity", "ViridianCity", float4(224.0f, -4800.0f));
		CreateFieldmapCity("Route22", "Route22", float4(-3360.0f, -4640.0f));
		CreateFieldmapCity("Route2_Down", "Route2_Down", float4(0.0f, -7808.0f));
		CreateFieldmapCity("Route2_Up", "Route2_Up",float4(0.0f, -10368.0f));
		CreateFieldmapCity("PewterCity", "PewterCity", float4(0.0f, -12480.0f));
	}

	Fieldmap::ChangeCity("PalletTown");

	MainFieldRender = CreateActor<FieldmapRender>();
	MainFieldRender->Off();
		
	ImageLoad();
	
	MainPlayer = CreateActor<Player>();
	MainPlayer->SetPos(Fieldmap::GetPos(21, 8));
	MainPlayer->SetPlayerSpeed(500.0f);
	MainFieldDialog = CreateActor<FieldDialog>();
}

void FieldmapLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("WalkableDebug"))
	{
		if (FieldmapRender::RenderType::Walkable == MainFieldRender->GetRenderType())
		{
			MainFieldRender->OnOffSwtich();
		}
		else
		{
			MainFieldRender->SetRenderType(FieldmapRender::RenderType::Walkable);
			MainFieldRender->On();
		}
	}

	if (true == GameEngineInput::IsDown("FieldmapTypeDebug"))
	{
		if (FieldmapRender::RenderType::GroundType == MainFieldRender->GetRenderType())
		{
			MainFieldRender->OnOffSwtich();
		}
		else
		{
			MainFieldRender->SetRenderType(FieldmapRender::RenderType::GroundType);
			MainFieldRender->On();
		}
	}
	
	if (true == GameEngineInput::IsDown("FreeCamera"))
	{
		IsCameraDebug = !IsCameraDebug;
	}
	
	if (true == IsCameraDebug)
	{
		DebugTextPush("FREE CAMERA MODE");
	
		if (true == GameEngineInput::IsPress("FreeCameraMoveUp"))
		{
			SetCameraMove(float4::Up * 2000.0f * _DeltaTime);
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveDown"))
		{
			SetCameraMove(float4::Down * 2000.0f * _DeltaTime);
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveLeft"))
		{
			SetCameraMove(float4::Left * 2000.0f * _DeltaTime);
		}
		else if (true == GameEngineInput::IsPress("FreeCameraMoveRight"))
		{
			SetCameraMove(float4::Right * 2000.0f * _DeltaTime);
		}
	
		int2 PlayerIndex = Fieldmap::GetIndex(MainPlayer->GetPos());
	
		DebugTextPush("PlayerIndex : " + PlayerIndex.ToString());
		MainPlayer->SetPos(GetCameraPos() + GameEngineWindow::GetScreenSize().half());
		MainPlayer->Off();
	}
	else
	{
		PlayerPos = MainPlayer->GetPos();
	
		SetCameraPos(PlayerPos - GameEngineWindow::GetScreenSize().half());
		
		if (true == MainFieldRender->IsUpdate())
		{
			MainFieldRender->RenderPosUpdate(PlayerPos);
		}
	
		MainPlayer->On();
	}
	
	if (GameEngineInput::IsDown("FieldDialogSwitch"))
	{
		MainFieldDialog->OnOffSwtich();
	}
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

void FieldmapLevel::CreateFieldmapCity(const std::string_view& _CityName, const std::string_view& _ImageName, const float4& _Pos)
{
	FieldmapCity* PalletTownPtr = CreateActor<FieldmapCity>();

	PalletTownPtr->InitFieldRender(_CityName, _ImageName);
	PalletTownPtr->InitPos(_Pos);
}