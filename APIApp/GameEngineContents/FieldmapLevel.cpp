#include "FieldmapLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

#include "Fieldmap.h"
#include "FieldmapCity.h"
#include "Player.h"
#include "FieldDialog.h"
#include "int2.h"
#include "FieldmapRender.h"
#include "TileDebugRender.h"
#include "FieldMainMenu.h"

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

		CreateFieldmapCity("PalletTown_Home1F", "Myroom_1F", float4(0.0f, 2000.0f));
		CreateFieldmapCity("PalletTown_Home2F", "Myroom_2F", float4(0.0f, 4000.0f));
		CreateFieldmapCity("PalletTown_Office", "Office", float4(0.0f, 6000.0f));
		CreateFieldmapCity("PalletTown_House1", "GreyCityHouse", float4(0.0f, 8000.0f));

		CreateFieldmapCity("ViridianCity_PokemonCenter", "Center_1F", float4(2000.0f, 2000.0f));
		CreateFieldmapCity("ViridianCity_Market", "Market", float4(2000.0f, 4000.0f));
		CreateFieldmapCity("ViridianCity_Office", "Office", float4(2000.0f, 6000.0f));
		CreateFieldmapCity("ViridianCity_House1", "GreyCityHouse", float4(2000.0f, 8000.0f));
		CreateFieldmapCity("ViridianCity_House2", "GreyCityHouse", float4(2000.0f, 10000.0f));
		CreateFieldmapCity("ViridianForest", "ViridianForest", float4(2000.0f, 15000.0f));

		CreateFieldmapCity("PewterCity_Gym", "GreyCityGym", float4(6000.0f, 2000.0f));
		CreateFieldmapCity("PewterCity_Market", "Market", float4(6000.0f, 4000.0f));
		CreateFieldmapCity("PewterCity_Museum1F", "GreyCityMuseum_1F", float4(6000.0f, 6000.0f));
		CreateFieldmapCity("PewterCity_Museum2F", "GreyCityMuseum_2F", float4(6000.0f, 8000.0f));
		CreateFieldmapCity("PewterCity_House1", "GreyCityHouse", float4(6000.0f, 10000.0f));
		CreateFieldmapCity("PewterCity_House2", "GreyCityHouse", float4(6000.0f, 12000.0f));
		CreateFieldmapCity("PewterCity_PokemonCenter", "Center_1F", float4(6000.0f, 14000.0f));
	}

	{
		Fieldmap::AddEvent("PalletTown", int2(21, 9), {
			.Name = "TestEvent 001",
			.Order = 0,
			.VaildFunc = std::bind(&FieldmapLevel::VaileTest, this),
			.EventFunc = std::bind(&FieldmapLevel::EventTest1, this),
			.Loop = false
			});

		Fieldmap::AddEvent("PalletTown", int2(21, 9), {
			.Name = "TestEvent 002",
			.Order = -1,
			.VaildFunc = std::bind(&FieldmapLevel::VaileTest, this),
			.EventFunc = std::bind(&FieldmapLevel::EventTest2, this),
			.Loop = false
			});
	}

	Fieldmap::ChangeCity("PalletTown");

	MainFieldRender = CreateActor<FieldmapRender>();
	MainFieldRender->On();
		
	ImageLoad();
	
	MainPlayer = CreateActor<Player>();
	MainPlayer->SetPos(Fieldmap::GetPos(21, 8));
	MainPlayer->SetPlayerSpeed(500.0f);
	MainFieldDialog = CreateActor<FieldDialog>();
	MainFieldMainMenu = CreateActor<FieldMainMenu>();
}

void FieldmapLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("WalkableDebug"))
	{
		MainFieldRender->RenderTypeSwitch(TileDebugRender::RenderType::Walkable);
	}

	if (true == GameEngineInput::IsDown("FieldmapTypeDebug"))
	{
		MainFieldRender->RenderTypeSwitch(TileDebugRender::RenderType::GroundType);
	}

	if (true == GameEngineInput::IsDown("EventDebug"))
	{
		MainFieldRender->RenderTypeSwitch(TileDebugRender::RenderType::Event);
	}
	
	if (true == GameEngineInput::IsDown("EventLog"))
	{
		Fieldmap::ShowEventLog(Fieldmap::GetIndex(MainPlayer->GetPos()));
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
	
	if (true == GameEngineInput::IsDown("FieldDialogSwitch"))
	{
		MainFieldDialog->OnOffSwtich();
	}

	if (true == GameEngineInput::IsDown("EventCheck"))
	{
		Fieldmap::EventCheck(Fieldmap::GetIndex(MainPlayer->GetPos()));
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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuUI_0.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuUI_1.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuUI_2.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuUI_3.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuUI_4.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuUI_5.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_Dialog.bmp"))->Cut(27, 4);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Arrow_Dialog.bmp"))->Cut(4, 1);
}

void FieldmapLevel::CreateFieldmapCity(const std::string_view& _CityName, const std::string_view& _ImageName, const float4& _Pos)
{
	FieldmapCity* PalletTownPtr = CreateActor<FieldmapCity>();

	PalletTownPtr->InitFieldRender(_CityName, _ImageName);
	PalletTownPtr->InitPos(_Pos);
}