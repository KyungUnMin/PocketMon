#include "FieldmapLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

#include "Fieldmap.h"
#include "FieldmapCity.h"
#include "FieldmapWoodDoor.h"
#include "FieldmapSingleDoor.h"
#include "FieldmapDoubleDoor.h"
#include "FieldmapEmptyDoor.h"
#include "FieldDialog.h"
#include "int2.h"
#include "PokeDataBase.h"
#include "PocketMonCore.h"
#include "FieldmapCutableTree.h"
#include "FieldmapRender.h"
#include "TileDebugRender.h"
#include "FieldMainMenu.h"
#include "MoveMapFadeEffect.h"
#include "BackgroundUI.h"
#include "FieldmapFlower.h"
#include "FieldmapBattleZone.h"
#include "ShopUIManager.h"

//Game Actor
#include "Player.h"
#include "NPC1.h"
#include "EndingPlayActor.h"

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
		CreateActor<BackgroundUI>();

		CreateFieldmapCity("PalletTown", "PalletTown", float4::Zero);
		{
			CreateDoor<FieldmapWoodDoor>("PalletTownToHouse", "PalletTown", int2(21, 7), "MoveHouse001");
			CreateDoor<FieldmapWoodDoor>("PalletTownToHome", "PalletTown", int2(12, 7), "MoveHome");
			CreateDoor<FieldmapWoodDoor>("PalletTownToOffice", "PalletTown", int2(22, 13), "MoveOffice");
		}

		{
			Fieldmap::AddFlowerActors("PalletTown", "PalletTown_Flower.bmp");
		}

		CreateFieldmapCity("Route1", "Route1", float4(0.0f, -2240.0f));

		{
			Fieldmap::AddFlowerActors("Route1", "Route1_Flower.bmp");
		}
		{
			CreateBattlezone_Route1(int2(16, 6), int2(12, 5));
			CreateBattlezone_Route1(int2(22, 13), int2(6, 5));
			CreateBattlezone_Route1(int2(18, 24), int2(6, 5));
			CreateBattlezone_Route1(int2(10, 32), int2(7, 2));
			CreateBattlezone_Route1(int2(8, 34), int2(7, 2));
			CreateBattlezone_Route1(int2(23, 32), int2(5, 2));
			CreateBattlezone_Route1(int2(21, 34), int2(5, 2));
			CreateBattlezone_Route1(int2(18, 35), int2(2, 5));
		}
		{
			AddJumpEvent("Route1", int2(8, 30), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("Route1", int2(16, 30), int2::Right, 12, PlayerDir::Down);
			AddJumpEvent("Route1", int2(24, 25), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("Route1", int2(8, 19), int2::Right, 2, PlayerDir::Down);
			AddJumpEvent("Route1", int2(11, 19), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("Route1", int2(17, 19), int2::Right, 11, PlayerDir::Down);
			AddJumpEvent("Route1", int2(10, 14), int2::Right, 6, PlayerDir::Down);
			AddJumpEvent("Route1", int2(8, 9), int2::Right, 6, PlayerDir::Down);
			AddJumpEvent("Route1", int2(8, 4), int2::Right, 6, PlayerDir::Down);
			AddJumpEvent("Route1", int2(16, 4), int2::Right, 6, PlayerDir::Down);
		}

		CreateFieldmapCity("ViridianCity", "ViridianCity", float4(224.0f, -4800.0f));
		{
			CreateDoor<FieldmapWoodDoor>("ViridianCityToHouse001", "ViridianCity", int2(19, 11), "MoveHouse001");
			CreateDoor<FieldmapWoodDoor>("ViridianCityToHouse002", "ViridianCity", int2(19, 18), "MoveHouse002");
			CreateDoor<FieldmapSingleDoor>("ViridianCityToMarket", "ViridianCity", int2(30, 19), "MoveMarket");
			CreateDoor<FieldmapSingleDoor>("ViridianCityToPokemonCenter", "ViridianCity", int2(20, 26), "MovePokemonCenter");
		}

		{
			Fieldmap::AddFlowerActors("ViridianCity", "ViridianCity_Flower.bmp");
		}

		{
			AddJumpEvent("ViridianCity", int2(1, 29), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("ViridianCity", int2(11, 29), int2::Right, 3, PlayerDir::Down);
			AddJumpEvent("ViridianCity", int2(17, 29), int2::Right, 19, PlayerDir::Down);
			AddJumpEvent("ViridianCity", int2(23, 11), int2::Right, 13, PlayerDir::Down);
		}

		CreateFieldmapCity("Route22", "Route22", float4(-3360.0f, -4640.0f));
		{
			CreateBattlezone_Route22(int2(30, 19), int2(7, 5));
			CreateBattlezone_Route22(int2(49, 19), int2(6, 5));
		}
		{
			AddJumpEvent("Route22", int2(19, 24), int2::Right, 35, PlayerDir::Down);
			AddJumpEvent("Route22", int2(56, 24), int2::Right, 5, PlayerDir::Down);
			AddJumpEvent("Route22", int2(18, 18), int2::Right, 7, PlayerDir::Down);
			AddJumpEvent("Route22", int2(27, 18), int2::Right, 2, PlayerDir::Down);
			AddJumpEvent("Route22", int2(27, 11), int2::Right, 2, PlayerDir::Down);
			AddJumpEvent("Route22", int2(30, 17), int2::Right, 7, PlayerDir::Down);
			AddJumpEvent("Route22", int2(49, 17), int2::Right, 2, PlayerDir::Down);
			AddJumpEvent("Route22", int2(53, 17), int2::Right, 2, PlayerDir::Down);
			AddJumpEvent("Route22", int2(49, 12), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("Route22", int2(54, 12), int2::Right, 3, PlayerDir::Down);
		}

		CreateFieldmapCity("Route2_Down", "Route2_Down", float4(0.0f, -7808.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("Route2DownToViridianForest001", "Route2_Down", int2(11, 25), "MoveRoute2_Up");
			CreateDoor<FieldmapEmptyDoor>("Route2DownToViridianForest002", "Route2_Down", int2(12, 25), "MoveRoute2_Up");
		}

		{
			Fieldmap::AddActor("Route2_Down", int2(21, 36), CreateActor<FieldmapCutableTree>(), false);
			Fieldmap::AddActor("Route2_Down", int2(21, 43), CreateActor<FieldmapCutableTree>(), false);

			Fieldmap::AddFlowerActors("Route2_Down", "Route2_Down_Flower.bmp");
		}
		{
			CreateBattlezone_Route2_Down(int2(12, 30), int2(7, 5));
		}
		{
			AddJumpEvent("Route2_Down", int2(8, 43), int2::Right, 7, PlayerDir::Down);
			AddJumpEvent("Route2_Down", int2(17, 43), int2::Right, 3, PlayerDir::Down);
			AddJumpEvent("Route2_Down", int2(8, 28), int2::Right, 9, PlayerDir::Down);
		}


		CreateFieldmapCity("Route2_Up", "Route2_Up",float4(0.0f, -10368.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("Route2UpToViridianForest001", "Route2_Up", int2(11, 13), "MoveRoute2_Down");
			CreateDoor<FieldmapEmptyDoor>("Route2UpToViridianForest002", "Route2_Up", int2(12, 13), "MoveRoute2_Down");
		}
		{
			Fieldmap::AddActor("Route2_Up", int2(17, 13), CreateActor<FieldmapCutableTree>(), false);
		}
		{
			CreateBattlezone_Route2_Up(int2(8, 2), int2(7, 7));
		}

		CreateFieldmapCity("PewterCity", "PewterCity", float4(0.0f, -12480.0f));
		{
			CreateDoor<FieldmapDoubleDoor>("PewterCityToGym", "PewterCity", int2(15, 16), "MoveGym");
			CreateDoor<FieldmapSingleDoor>("PewterCityToMarket", "PewterCity", int2(28, 18), "MoveMarket");
			CreateDoor<FieldmapEmptyDoor>("PewterCityToMuseum", "PewterCity", int2(17, 7), "MoveMuseum");
			CreateDoor<FieldmapWoodDoor>("PewterCityToHouse001", "PewterCity", int2(33, 11), "MoveHouse001");
			CreateDoor<FieldmapWoodDoor>("PewterCityToHouser002", "PewterCity", int2(9, 30), "MoveHouse002");
			CreateDoor<FieldmapSingleDoor>("PewterCityToPoketmonCenter", "PewterCity", int2(17, 25), "MovePokemonCenter");
		}
		{
			Fieldmap::AddFlowerActors("PewterCity", "PewterCity_Flower.bmp");
		}

		{
			AddJumpEvent("PewterCity", int2(27, 29), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("PewterCity", int2(32, 29), int2::Right, 4, PlayerDir::Down);
			AddJumpEvent("PewterCity", int2(9, 6), int2::Right, 7, PlayerDir::Down);
			AddJumpEvent("PewterCity", int2(20, 6), int2::Right, 17, PlayerDir::Down);
		}

		CreateFieldmapCity("PalletTown_Home1F", "Myroom_1F", float4(0.0f, 2000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("HomeToPalletTown", "PalletTown_Home1F", int2(4, 9), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("HomeToSecond", "PalletTown_Home1F", int2(11, 3), "MoveSecondFloor");
		}

		CreateFieldmapCity("PalletTown_Home2F", "Myroom_2F", float4(0.0f, 4000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("HomeSecondToFirst", "PalletTown_Home2F", int2(9, 3), "MoveFirstFloor");
		}

		CreateFieldmapCity("PalletTown_Office", "Office", float4(0.0f, 6000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("OfficeToPalletTown", "PalletTown_Office", int2(7, 13), "MoveOut");
		}

		CreateFieldmapCity("PalletTown_House1", "Rivalroom", float4(0.0f, 8000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House001ToPalletTown", "PalletTown_House1", int2(5, 9), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_PokemonCenter", "Center_1F", float4(2000.0f, 2000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("PokemonCenterToViridianCity", "ViridianCity_PokemonCenter", int2(8, 10), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_Market", "Market", float4(2000.0f, 4000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("MarketToViridianCity", "ViridianCity_Market", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_House1", "GreyCityHouse", float4(2000.0f, 6000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House001ToViridianCity", "ViridianCity_House1", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_House2", "GreyCityHouse", float4(2000.0f, 8000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House002ToViridianCity", "ViridianCity_House2", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("ViridianForest", "ViridianForest", float4(2000.0f, 13000.0f));
		{
			CreateBattlezone_VaridianForest(int2(9, 13), int2(5, 15));
			CreateBattlezone_VaridianForest(int2(17, 12), int2(5, 14));
			CreateBattlezone_VaridianForest(int2(17, 26), int2(7, 2));
			CreateBattlezone_VaridianForest(int2(25, 12), int2(5, 10)); 

			CreateBattlezone_VaridianForest(int2(33, 12), int2(3, 9));
			CreateBattlezone_VaridianForest(int2(36, 12), int2(2, 10));
			CreateBattlezone_VaridianForest(int2(38, 15), int2(1, 7));
			CreateBattlezone_VaridianForest(int2(39, 15), int2(4, 5));
			CreateBattlezone_VaridianForest(int2(43, 15), int2(1, 4));

			CreateBattlezone_VaridianForest(int2(45, 29), int2(3, 26));
			CreateBattlezone_VaridianForest(int2(48, 29), int2(1, 15));
			CreateBattlezone_VaridianForest(int2(49, 30), int2(1, 13));
			CreateBattlezone_VaridianForest(int2(37, 55), int2(11, 2));
			CreateBattlezone_VaridianForest(int2(38, 57), int2(9, 1));
			CreateBattlezone_VaridianForest(int2(39, 58), int2(7, 1));
			CreateBattlezone_VaridianForest(int2(37, 43), int2(2, 12));
			CreateBattlezone_VaridianForest(int2(9, 39), int2(15, 4));
			CreateBattlezone_VaridianForest(int2(9, 43), int2(28, 1));

			CreateBattlezone_VaridianForest(int2(18,44), int2(16,2));
			CreateBattlezone_VaridianForest(int2(20,46), int2(3,9));
			CreateBattlezone_VaridianForest(int2(32,46), int2(2,9));
			CreateBattlezone_VaridianForest(int2(20,55), int2(14,2));
			CreateBattlezone_VaridianForest(int2(21,57), int2(12,1));
			CreateBattlezone_VaridianForest(int2(22,58), int2(10,1));

			CreateBattlezone_VaridianForest(int2(9,55), int2(9,4));
			CreateBattlezone_VaridianForest(int2(9,59), int2(8,3));

			CreateBattlezone_VaridianForest(int2(51,55), int2(6,2));
			CreateBattlezone_VaridianForest(int2(50,57), int2(7,3));
			CreateBattlezone_VaridianForest(int2(49,60), int2(8,2));

		}
		{
			CreateDoor<FieldmapEmptyDoor>("ViridianForestToRoute2Up001", "ViridianForest", int2(10, 9), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("ViridianForestToRoute2Up002", "ViridianForest", int2(11, 9), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("ViridianForestToRoute2Up003", "ViridianForest", int2(12, 9), "MoveOut");

			CreateDoor<FieldmapEmptyDoor>("ViridianForestToRoute2Down001", "ViridianForest", int2(34, 62), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("ViridianForestToRoute2Down002", "ViridianForest", int2(35, 62), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("ViridianForestToRoute2Down003", "ViridianForest", int2(36, 62), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_Gym", "GreyCityGym", float4(6000.0f, 2000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("GymToPewterCity", "PewterCity_Gym", int2(6, 14), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_Market", "Market", float4(6000.0f, 4000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("MarketToPewterCity", "PewterCity_Market", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_Museum1F", "GreyCityMuseum_1F", float4(6000.0f, 6000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("Museum1FToPewterCity", "PewterCity_Museum1F", int2(15, 10), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("Museum1FToMuseum2F", "PewterCity_Museum1F", int2(10, 9), "MoveSecondFloor");
		}

		CreateFieldmapCity("PewterCity_Museum2F", "GreyCityMuseum_2F", float4(6000.0f, 8000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("Museum2FToMuseum1F", "PewterCity_Museum2F", int2(11, 9), "MoveFirstFloor");
		}

		CreateFieldmapCity("PewterCity_House1", "GreyCityHouse", float4(6000.0f, 10000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House001ToPewterCity", "PewterCity_House1", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_House2", "GreyCityHouse", float4(6000.0f, 12000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House002ToPewterCity", "PewterCity_House2", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_PokemonCenter", "Center_1F", float4(6000.0f, 14000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("PokemonCenterToPewterCity", "PewterCity_PokemonCenter", int2(8, 10), "MoveOut");
		}

		{
			LinkDoor("PalletTownToHouse", "House001ToPalletTown");
			LinkDoor("PalletTownToHome", "HomeToPalletTown");
			LinkDoor("PalletTownToOffice", "OfficeToPalletTown");
			
			LinkDoor("ViridianCityToHouse001", "House001ToViridianCity");
			LinkDoor("ViridianCityToHouse002", "House002ToViridianCity");
			LinkDoor("ViridianCityToMarket", "MarketToViridianCity");
			LinkDoor("ViridianCityToPokemonCenter", "PokemonCenterToViridianCity");
			
			LinkDoor("Route2DownToViridianForest001", "ViridianForestToRoute2Down002");
			LinkDoor("Route2DownToViridianForest002", "ViridianForestToRoute2Down002");
			LinkDoor("Route2UpToViridianForest001", "ViridianForestToRoute2Up002");
			LinkDoor("Route2UpToViridianForest002", "ViridianForestToRoute2Up002");
			
			LinkDoor("PewterCityToGym", "GymToPewterCity");
			LinkDoor("PewterCityToMarket", "MarketToPewterCity");
			LinkDoor("PewterCityToMuseum", "Museum1FToPewterCity");
			LinkDoor("PewterCityToHouse001", "House001ToPewterCity");
			LinkDoor("PewterCityToHouser002", "House002ToPewterCity");
			LinkDoor("PewterCityToPoketmonCenter", "PokemonCenterToPewterCity");
			
			LinkDoor("HomeToPalletTown", "PalletTownToHome");
			LinkDoor("HomeToSecond", "HomeSecondToFirst");
			LinkDoor("HomeSecondToFirst", "HomeToSecond");
			
			LinkDoor("OfficeToPalletTown", "PalletTownToOffice");
			
			LinkDoor("House001ToPalletTown", "PalletTownToHouse");
			
			LinkDoor("PokemonCenterToViridianCity", "ViridianCityToPokemonCenter");
			LinkDoor("MarketToViridianCity", "ViridianCityToMarket");
			LinkDoor("House001ToViridianCity", "ViridianCityToHouse001");
			LinkDoor("House002ToViridianCity", "ViridianCityToHouse002");
			
			LinkDoor("ViridianForestToRoute2Up001", "Route2UpToViridianForest002");
			LinkDoor("ViridianForestToRoute2Up002", "Route2UpToViridianForest002");
			LinkDoor("ViridianForestToRoute2Up003", "Route2UpToViridianForest002");
			
			LinkDoor("ViridianForestToRoute2Down001", "Route2DownToViridianForest002");
			LinkDoor("ViridianForestToRoute2Down002", "Route2DownToViridianForest002");
			LinkDoor("ViridianForestToRoute2Down003", "Route2DownToViridianForest002");
			
			LinkDoor("GymToPewterCity", "PewterCityToGym");
			LinkDoor("MarketToPewterCity", "PewterCityToMarket");
			LinkDoor("Museum1FToPewterCity", "PewterCityToMuseum");
			
			LinkDoor("Museum1FToMuseum2F", "Museum2FToMuseum1F");
			LinkDoor("Museum2FToMuseum1F", "Museum1FToMuseum2F");
			
			LinkDoor("House001ToPewterCity", "PewterCityToHouse001");
			LinkDoor("House002ToPewterCity", "PewterCityToHouser002");
			LinkDoor("PokemonCenterToPewterCity", "PewterCityToPoketmonCenter");
		}

		{
			Fieldmap::LinkNeighbor("PalletTown", "Route1");
			Fieldmap::LinkNeighbor("ViridianCity", "Route1");
			Fieldmap::LinkNeighbor("ViridianCity", "Route22");
			Fieldmap::LinkNeighbor("ViridianCity", "Route2_Down");
			Fieldmap::LinkNeighbor("Route2_Down", "Route2_Up");
			Fieldmap::LinkNeighbor("Route2_Up", "PewterCity");
		}
	}

	EndingPlayActor* EndActor = CreateActor<EndingPlayActor>();
	EndActor->Off();

	Fieldmap::ChangeCity("PalletTown");

	// Debug용 랜더
	MainFieldRender = CreateActor<FieldmapRender>();
	MainFieldRender->On();
		
	UIImageLoad();
	
	MainPlayer = CreateActor<Player>();

	//TestNpc=CreateActor<NPC1>();
	//TestNpc->SetPos(Fieldmap::GetPos(16, 8));

	TestNpc=CreateActor<NPC1>(); 
	Fieldmap::AddActor("PalletTown", int2(16, 8), TestNpc);

	MainPlayer->SetPos(Fieldmap::GetPos(21, 8));
	MainPlayer->SetPlayerSpeed(500.0f);
	MainFieldDialog = CreateActor<FieldDialog>();
	MainFieldMainMenu = CreateActor<FieldMainMenu>();
	MainMoveMapFadeEffect = CreateActor<MoveMapFadeEffect>();
	MainShopUIManager = CreateActor<ShopUIManager>();
}

void FieldmapLevel::Update(float _DeltaTime)
{
	if (true == EndingPlayActor::IsEndingPlay)
	{
		return;
	}

	Fieldmap::FieldUpdate();

	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}
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

	if (true == GameEngineInput::IsDown("PlayEnding"))
	{
		EndingPlayActor::MainEndingPlayActor->PlayEnding();
		return;
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
	
	if (true == GameEngineInput::IsDown("FieldUITestSwitch"))
	{
		MainShopUIManager->OnOffSwtich();
		//GameEngineCore::GetInst()->ChangeLevel("BuyLevel");
	}

	if (true == GameEngineInput::IsDown("StartEventCheck"))
	{
		Fieldmap::StartEventCheck(Fieldmap::GetIndex(MainPlayer->GetPos()));
	}
	if (true == GameEngineInput::IsDown("UpdateEventCheck"))
	{
		Fieldmap::UpdateEventCheck(Fieldmap::GetIndex(MainPlayer->GetPos()));
	}
	if (true == GameEngineInput::IsDown("EndEventCheck"))
	{
		Fieldmap::EndEventCheck(Fieldmap::GetIndex(MainPlayer->GetPos()));
	}
}

void FieldmapLevel::UIImageLoad()
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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MoveMapFade1.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MoveMapFade2.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_MainMenu.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MenuArrow.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Arrow_CountItem_Up.bmp"))->Cut(4, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Arrow_CountItem_Down.bmp"))->Cut(4, 1);
}

void FieldmapLevel::CreateFlower(const std::string_view& _CityName, const int2& _Index)
{
}

void FieldmapLevel::CreateFieldmapCity(const std::string_view& _CityName, const std::string_view& _ImageName, const float4& _Pos)
{
	FieldmapCity* PalletTownPtr = CreateActor<FieldmapCity>(-9999);

	PalletTownPtr->InitFieldRender(_CityName, _ImageName);
	PalletTownPtr->InitPos(_Pos);
}

void FieldmapLevel::AddJumpEvent(const std::string_view& _CityName, const int2& _Start, const int2& _Add, int _Count, PlayerDir _Dir)
{
	int2 CurIndex = _Start;

	for (int i = 0; i < _Count; i++)
	{
		AddJumpEvent(_CityName, CurIndex, _Dir);
		CurIndex += _Add;
	}
}

void FieldmapLevel::AddJumpEvent(const std::string_view& _CityName, const int2& _Index, PlayerDir _Dir)
{
	switch (_Dir)
	{
	case PlayerDir::Up:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpUp",
			.VaildFunc = std::bind(&FieldmapLevel::PlayerUpCheck, this),
			.EventFunc = &FieldmapLevel::TempFunc,
			.Loop = true
			});
		break;
	case PlayerDir::Down:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpDown",
			.VaildFunc = std::bind(&FieldmapLevel::PlayerDownCheck, this),
			.EventFunc = &FieldmapLevel::TempFunc,
			.Loop = true
			});
		break;
	case PlayerDir::Left:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpLeft",
			.VaildFunc = std::bind(&FieldmapLevel::PlayerLeftCheck, this),
			.EventFunc = &FieldmapLevel::TempFunc,
			.Loop = true
			});
		break;
	case PlayerDir::Right:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpRight",
			.VaildFunc = std::bind(&FieldmapLevel::PlayerRightCheck, this),
			.EventFunc = &FieldmapLevel::TempFunc,
			.Loop = true
			});
		break;
	default:
		break;
	}
}

void FieldmapLevel::LinkDoor(const std::string_view& _LinkDoorName, const std::string_view& _TargetDoorName)
{
	std::string LinkDoorUpperName = GameEngineString::ToUpper(_LinkDoorName);
	std::string TargetDoorUpperName = GameEngineString::ToUpper(_TargetDoorName);

	DoorActorBase* LinkDoor = AllDoors[LinkDoorUpperName];
	DoorActorBase* TargetDoor = AllDoors[TargetDoorUpperName];

	if (nullptr == LinkDoor)
	{
		MsgAssert("Link Door가 존재하지 않습니다");
		return;
	}

	if (nullptr == TargetDoor)
	{
		MsgAssert("Target Door가 존재하지 않습니다");
		return;
	}
 
	LinkDoor->SetLinkDoor(TargetDoor);
}

void FieldmapLevel::CreateBattlezone_Route1(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route1", _Start, _Size, 2, 5);
	BattleZone->AddPokemon(PokeNumber::Rattata);
}

void FieldmapLevel::CreateBattlezone_Route2_Down(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route2_Down", _Start, _Size, 5, 7);
	BattleZone->AddPokemon(PokeNumber::Venusaur);
}

void FieldmapLevel::CreateBattlezone_Route2_Up(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route2_Up", _Start, _Size, 9, 12);
	BattleZone->AddPokemon(PokeNumber::Blastoise);
}

void FieldmapLevel::CreateBattlezone_Route22(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route22", _Start, _Size, 12, 15);
	BattleZone->AddPokemon(PokeNumber::Geodude);
}

void FieldmapLevel::CreateBattlezone_VaridianForest(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("ViridianForest", _Start, _Size, 5, 10);
	BattleZone->AddPokemon(PokeNumber::Charmeleon);
}