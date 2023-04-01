#include "FieldmapLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

// Base
#include "int2.h"
#include "PokeDataBase.h"
#include "PokemonScript.h"
#include "PocketMonCore.h"
#include "PokemonScript.h"

// Map
#include "Fieldmap.h"
#include "FieldmapCity.h"
#include "FieldmapWoodDoor.h"
#include "FieldmapSingleDoor.h"
#include "FieldmapDoubleDoor.h"
#include "FieldmapEmptyDoor.h"
#include "FieldmapCutableTree.h"
#include "FieldmapFlower.h"
#include "FieldmapBattleZone.h"
#include "StartingPokeball.h"

// Debug
#include "FieldmapRender.h"
#include "TileDebugRender.h"
#include "FieldMainMenu.h"
#include "MoveMapFadeEffect.h"
#include "BackgroundUI.h"
#include "FieldmapFlower.h"
#include "FieldmapBattleZone.h"
#include "ShopUIManager.h"
#include "CityNameUI.h"
#include "SelectStartingUI.h"
#include "PokemonCenterUI.h"

//Level
#include "BattleLevel.h"

//NPC
#include "BaseNPC.h"
#include "StaticNPC.h"
#include "TurnNPC.h"
#include "MotherNPC.h"
#include "OakNPC.h"
#include "GreenNPC.h"
#include "ShopNpc.h"
#include "StopOakNPC.h"
#include "LeafNPC.h"

// Player
#include "Player.h"

// Ending
#include "EndingPlayActor.h"

// UI
#include "BackgroundUI.h"
#include "ShopUIManager.h"
#include "CityNameUI.h"
#include "FieldMainMenu.h"
#include "FieldDialog.h"
#include "SelectStartingUI.h"
#include "MoveMapFadeEffect.h"

float4 FieldmapLevel::PlayerPos = float4::Zero;
std::vector<std::function<void()>> FieldmapLevel::LevelStartCallFuncs;

FieldmapLevel::FieldmapLevel()
{
}

FieldmapLevel::~FieldmapLevel()
{
}

void FieldmapLevel::Loading()
{
	{
		PokemonScript::AddScript(0);   // 태초마을 나가기 이벤트
		PokemonScript::AddScript(100); // 스타팅 포켓몬 획득
		PokemonScript::AddScript(150); // 라이벌 포켓몬 획득
		PokemonScript::AddScript(200); // 라이벌 전투
		PokemonScript::AddScript(300); // 22번 도로 전투
		PokemonScript::AddScript(400); // 회색시티 체육관 전투
	}

	MainPlayer = CreateActor<Player>();

	{
		CreateActor<BackgroundUI>();

		CreateFieldmapCity("PalletTown", "Pallet Town", "PalletTown", float4::Zero);
		{
			CreateDoor<FieldmapWoodDoor>("PalletTownToHouse", "PalletTown", int2(21, 7), "MoveHouse001");
			CreateDoor<FieldmapWoodDoor>("PalletTownToHome", "PalletTown", int2(12, 7), "MoveHome");
			CreateDoor<FieldmapWoodDoor>("PalletTownToOffice", "PalletTown", int2(22, 13), "MoveOffice");
		}

		{
			Fieldmap::AddFlowerActors("PalletTown", "PalletTown_Flower.bmp");
		}

		CreateFieldmapCity("Route1","Route 1", "Route1", float4(0.0f, -2240.0f));

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
			AddJumpEvent("Route1", int2(8, 30), int2::Right, 4, LookDir::Down);
			AddJumpEvent("Route1", int2(16, 30), int2::Right, 12, LookDir::Down);
			AddJumpEvent("Route1", int2(24, 25), int2::Right, 4, LookDir::Down);
			AddJumpEvent("Route1", int2(8, 19), int2::Right, 2, LookDir::Down);
			AddJumpEvent("Route1", int2(11, 19), int2::Right, 4, LookDir::Down);
			AddJumpEvent("Route1", int2(17, 19), int2::Right, 11, LookDir::Down);
			AddJumpEvent("Route1", int2(10, 14), int2::Right, 6, LookDir::Down);
			AddJumpEvent("Route1", int2(8, 9), int2::Right, 6, LookDir::Down);
			AddJumpEvent("Route1", int2(8, 4), int2::Right, 6, LookDir::Down);
			AddJumpEvent("Route1", int2(16, 4), int2::Right, 6, LookDir::Down);
		}

		CreateFieldmapCity("ViridianCity", "Viridian City", "ViridianCity", float4(224.0f, -4800.0f));
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
			AddJumpEvent("ViridianCity", int2(1, 29), int2::Right, 4, LookDir::Down);
			AddJumpEvent("ViridianCity", int2(11, 29), int2::Right, 3, LookDir::Down);
			AddJumpEvent("ViridianCity", int2(17, 29), int2::Right, 19, LookDir::Down);
			AddJumpEvent("ViridianCity", int2(23, 11), int2::Right, 13, LookDir::Down);
		}

		CreateFieldmapCity("Route22", "Route 22", "Route22", float4(-3360.0f, -4640.0f));
		{
			CreateBattlezone_Route22(int2(30, 19), int2(7, 5));
			CreateBattlezone_Route22(int2(49, 19), int2(6, 5));
		}
		{
			AddJumpEvent("Route22", int2(19, 24), int2::Right, 35, LookDir::Down);
			AddJumpEvent("Route22", int2(56, 24), int2::Right, 5, LookDir::Down);
			AddJumpEvent("Route22", int2(18, 18), int2::Right, 7, LookDir::Down);
			AddJumpEvent("Route22", int2(27, 18), int2::Right, 2, LookDir::Down);
			AddJumpEvent("Route22", int2(27, 11), int2::Right, 2, LookDir::Down);
			AddJumpEvent("Route22", int2(30, 17), int2::Right, 7, LookDir::Down);
			AddJumpEvent("Route22", int2(49, 17), int2::Right, 2, LookDir::Down);
			AddJumpEvent("Route22", int2(53, 17), int2::Right, 2, LookDir::Down);
			AddJumpEvent("Route22", int2(49, 12), int2::Right, 4, LookDir::Down);
			AddJumpEvent("Route22", int2(54, 12), int2::Right, 3, LookDir::Down);
		}

		CreateFieldmapCity("Route2_Down", "Route 2", "Route2_Down", float4(0.0f, -7808.0f));
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
			AddJumpEvent("Route2_Down", int2(8, 43), int2::Right, 7, LookDir::Down);
			AddJumpEvent("Route2_Down", int2(17, 43), int2::Right, 3, LookDir::Down);
			AddJumpEvent("Route2_Down", int2(8, 28), int2::Right, 9, LookDir::Down);
		}


		CreateFieldmapCity("Route2_Up", "Route 2", "Route2_Up",float4(0.0f, -10368.0f));
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

		CreateFieldmapCity("PewterCity", "Pewter CIty", "PewterCity", float4(0.0f, -12480.0f));
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
			AddJumpEvent("PewterCity", int2(27, 29), int2::Right, 4, LookDir::Down);
			AddJumpEvent("PewterCity", int2(32, 29), int2::Right, 4, LookDir::Down);
			AddJumpEvent("PewterCity", int2(9, 6), int2::Right, 7, LookDir::Down);
			AddJumpEvent("PewterCity", int2(20, 6), int2::Right, 17, LookDir::Down);
		}

		CreateFieldmapCity("PalletTown_Home1F", "Home 1F", "Myroom_1F", float4(0.0f, 2000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("HomeToPalletTown", "PalletTown_Home1F", int2(4, 9), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("HomeToSecond", "PalletTown_Home1F", int2(11, 3), "MoveSecondFloor");
		}

		CreateFieldmapCity("PalletTown_Home2F", "Home 2F", "Myroom_2F", float4(0.0f, 4000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("HomeSecondToFirst", "PalletTown_Home2F", int2(9, 3), "MoveFirstFloor");
		}

		CreateFieldmapCity("PalletTown_Office", "Oak Office", "Office", float4(0.0f, 6000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("OfficeToPalletTown", "PalletTown_Office", int2(7, 13), "MoveOut");
		}

		CreateFieldmapCity("PalletTown_House1", "House", "Rivalroom", float4(0.0f, 8000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House001ToPalletTown", "PalletTown_House1", int2(5, 9), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_PokemonCenter", "Pokemon Center", "Center_1F", float4(2000.0f, 2000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("PokemonCenterToViridianCity", "ViridianCity_PokemonCenter", int2(8, 10), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_Market", "Market", "Market", float4(2000.0f, 4000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("MarketToViridianCity", "ViridianCity_Market", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_House1", "House", "GreyCityHouse", float4(2000.0f, 6000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House001ToViridianCity", "ViridianCity_House1", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("ViridianCity_House2", "House", "GreyCityHouse", float4(2000.0f, 8000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House002ToViridianCity", "ViridianCity_House2", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("ViridianForest", "Viridian Forest", "ViridianForest", float4(2000.0f, 13000.0f));
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

		CreateFieldmapCity("PewterCity_Gym", "Gym", "GreyCityGym", float4(6000.0f, 2000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("GymToPewterCity", "PewterCity_Gym", int2(6, 14), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_Market", "Market", "Market", float4(6000.0f, 4000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("MarketToPewterCity", "PewterCity_Market", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_Museum1F", "Museum 1F", "GreyCityMuseum_1F", float4(6000.0f, 6000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("Museum1FToPewterCity", "PewterCity_Museum1F", int2(15, 10), "MoveOut");
			CreateDoor<FieldmapEmptyDoor>("Museum1FToMuseum2F", "PewterCity_Museum1F", int2(10, 9), "MoveSecondFloor");
		}

		CreateFieldmapCity("PewterCity_Museum2F", "Museum 2F", "GreyCityMuseum_2F", float4(6000.0f, 8000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("Museum2FToMuseum1F", "PewterCity_Museum2F", int2(11, 9), "MoveFirstFloor");
		}

		CreateFieldmapCity("PewterCity_House1", "House", "GreyCityHouse", float4(6000.0f, 10000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House001ToPewterCity", "PewterCity_House1", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_House2", "House", "GreyCityHouse", float4(6000.0f, 12000.0f));
		{
			CreateDoor<FieldmapEmptyDoor>("House002ToPewterCity", "PewterCity_House2", int2(5, 8), "MoveOut");
		}

		CreateFieldmapCity("PewterCity_PokemonCenter", "Pokemon Center", "Center_1F", float4(6000.0f, 14000.0f));
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

	{
		CityNameUI* CityNameUIPtr = CreateActor<CityNameUI>();
		
		float4 StartPos = float4(200, -40);
		float4 DestPos = float4(200, 35);

		CityNameUIPtr->SetPos(StartPos);
		CityNameUIPtr->Init(StartPos, DestPos);
		CityNameUIPtr->SetSpeed(3.0f);
	}

	EndingPlayActor* EndActor = CreateActor<EndingPlayActor>();
	EndActor->Off();

	
	/////// 스폰 마을
	///////
	///////
	///////
	///////
	///////
	//Fieldmap::ChangeCity("PalletTown_Office");
	Fieldmap::ChangeCity("Route2_Down");
	///////
	///////
	///////
	///////
	///////
	///////
	///////

	// Debug용 랜더
	MainFieldRender = CreateActor<FieldmapRender>();
	MainFieldRender->On();
		
	UIImageLoad();
	
	ShopNpcs = CreateActor<ShopNpc>();
	Fieldmap::AddActor("ViridianCity_Market", int2(3, 4), ShopNpcs);

	// 스타팅 포켓볼 생성
	{
		StartingPokeball* StartPokeball01 = CreateActor<StartingPokeball>();
		Fieldmap::AddActor("PalletTown_Office", int2(9, 5), StartPokeball01, false);

		StartingPokeball* StartPokeball02 = CreateActor<StartingPokeball>();
		Fieldmap::AddActor("PalletTown_Office", int2(10, 5), StartPokeball02, false);

		StartingPokeball* StartPokeball03 = CreateActor<StartingPokeball>();
		Fieldmap::AddActor("PalletTown_Office", int2(11, 5), StartPokeball03, false);

		StartPokeball01->Init(PokeNumber::Bulbasaur, int2(10, 6), StartPokeball02);
		StartPokeball02->Init(PokeNumber::Charmander, int2(11, 6), StartPokeball03);
		StartPokeball03->Init(PokeNumber::Squirtle, int2(9, 6), StartPokeball01);

		Fieldmap::AddUpdateEvent("PalletTown_Office", int2(9, 6), {
			.Name = "GetPokemon",
			.Order = -100,
			.VaildFunc = std::bind(&StartingPokeball::EventCheck, StartPokeball01),
			.EventFunc = std::bind(&StartingPokeball::EventFunc, StartPokeball01),
			.Loop = true
			});
		Fieldmap::AddUpdateEvent("PalletTown_Office", int2(10, 6), {
			.Name = "GetPokemon",
			.Order = -100,
			.VaildFunc = std::bind(&StartingPokeball::EventCheck, StartPokeball02),
			.EventFunc = std::bind(&StartingPokeball::EventFunc, StartPokeball02),
			.Loop = true
			});
		Fieldmap::AddUpdateEvent("PalletTown_Office", int2(11, 6), {
			.Name = "GetPokemon",
			.Order = -100,
			.VaildFunc = std::bind(&StartingPokeball::EventCheck, StartPokeball03),
			.EventFunc = std::bind(&StartingPokeball::EventFunc, StartPokeball03),
			.Loop = true
			});
	}

	// 태초 마을
	{
		MotherNPC* MotherNPCPtr = CreateActor<MotherNPC>();
		MotherNPCPtr->InitNPC("Mother", "Mother.bmp", BattleNpcType::Woong);
		MotherNPCPtr->AddNPC("PalletTown_Home1F", int2(7, 7));
		MotherNPCPtr->AddScript("Script 001");
		MotherNPCPtr->AddScript("Script 002");
		MotherNPCPtr->SetBaseDir(LookDir::Down);
		MotherNPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);
	}

	{
		OakNPC* OakNPCPtr = CreateActor<OakNPC>();
		OakNPCPtr->InitNPC("Oak", "Oak.bmp", BattleNpcType::Woong);
		OakNPCPtr->AddNPC("PalletTown_Office", int2(7, 4));
		OakNPCPtr->AddScript("Script 003");
		OakNPCPtr->AddScript("Script 004");
		OakNPCPtr->AddScript("CZCZ!", 1);
		OakNPCPtr->SetBaseDir(LookDir::Down);
		OakNPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);
	}

	{
		StaticNPC* ProfessorNPCPtr = CreateActor<StaticNPC>();
		ProfessorNPCPtr->InitNPC("Professor", "Professor.bmp", BattleNpcType::Woong);
		ProfessorNPCPtr->AddNPC("PalletTown_Office", int2(2, 10));
		ProfessorNPCPtr->AddScript("Script 005");
		ProfessorNPCPtr->AddScript("Script 006");
		ProfessorNPCPtr->SetBaseDir(LookDir::Up);
		ProfessorNPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);
	}

	{
		TurnNPC* ProfessorNPCPtr = CreateActor<TurnNPC>();
		ProfessorNPCPtr->InitNPC("Professor", "Professor.bmp", BattleNpcType::Woong);
		ProfessorNPCPtr->AddNPC("PalletTown_Office", int2(11, 11));
		ProfessorNPCPtr->AddScript("Script 007");
		ProfessorNPCPtr->AddScript("Script 008");
		ProfessorNPCPtr->SetTurnDir(TurnNPC::TurnDir::Right);
		ProfessorNPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);

	}
	{
		GreenNPC* GreenNPCPtr = CreateActor<GreenNPC>();
		GreenNPCPtr->InitNPC("Green", "Green.bmp", BattleNpcType::Rival);
		GreenNPCPtr->AddNPC("PalletTown_Office", int2(8, 9));
		GreenNPCPtr->AddScript("Script 020");
		GreenNPCPtr->AddScript("Script 021");
		GreenNPCPtr->AddScript("Battle 0101", 1);
		GreenNPCPtr->AddScript("Battle 0202", 1);
		GreenNPCPtr->AddScript("BYE", 2);

		GreenNPCPtr->SetBaseDir(LookDir::Down);
		GreenNPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);

		std::function<bool()> VaildEvent = std::bind(&GreenNPC::BattleEventCheck, GreenNPCPtr);
		std::function<void()> BattleEvent = std::bind(&GreenNPC::BattleStart, GreenNPCPtr);

		Fieldmap::AddStartEvent("PalletTown_Office", int2(8, 9),
			{
				.Name = "RivalBattle",
				.Order = -1,
				.VaildFunc = VaildEvent,
				.EventFunc = BattleEvent,
				.Loop = false
			});

		Fieldmap::AddStartEvent("PalletTown_Office", int2(7, 9),
			{
				.Name = "RivalBattle",
				.Order = -1,
				.VaildFunc = VaildEvent,
				.EventFunc = BattleEvent,
				.Loop = false
			});

		Fieldmap::AddStartEvent("PalletTown_Office", int2(6, 9),
			{
				.Name = "RivalBattle",
				.Order = -1,
				.VaildFunc = VaildEvent,
				.EventFunc = BattleEvent,
				.Loop = false
			});
	}

	{
		StaticNPC* NPCPtr = CreateActor<StaticNPC>();
		NPCPtr->InitNPC("Npc1", "NPC1.bmp", BattleNpcType::Woong);
		NPCPtr->AddNPC("PalletTown", int2(11, 15));
		NPCPtr->AddScript("Script 009");
		NPCPtr->AddScript("Script 010");
		NPCPtr->SetBaseDir(LookDir::Up);
		NPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);
	}

	// 2번도로 사망이벤트를 호출할 NPC
	{
		LeafNPC* LeafNPCptr = CreateActor<LeafNPC>();
		LeafNPCptr->InitNPC("Leaf", "Leaf.bmp", BattleNpcType::Woong);
		LeafNPCptr->AddNPC("Route2_Down", int2(11, 51));
		LeafNPCptr->SetBaseDir(LookDir::Right);
		LeafNPCptr->Look(LookDir::Right);
		LeafNPCptr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Look);
		LeafNPCptr->SetLookDis(20);
		LeafNPCptr->AddScript(".........");
		LeafNPCptr->AddPokeData(1, 99);
		LeafNPCptr->AddPokeData(4, 99);
		LeafNPCptr->AddPokeData(7, 99);
	}

	{
		TurnNPC* NPCPtr = CreateActor<TurnNPC>();
		NPCPtr->InitNPC("NPC4", "NPC4.bmp", BattleNpcType::Woong);
		NPCPtr->AddNPC("PalletTown", int2(20, 18));
		NPCPtr->AddScript("Script 011");
		NPCPtr->AddScript("Script 012");
		NPCPtr->SetTurnDir(TurnNPC::TurnDir::Right);
		NPCPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);
	}
	
	// 상록 숲

	// Battle1
	{
		TurnNPC* BaatleNpcPtr = CreateActor<TurnNPC>();
		BaatleNpcPtr->InitNPC("ViridianForestBattle1", "NPC3.bmp", BattleNpcType::Woong);
		BaatleNpcPtr->AddNPC("ViridianForest", int2(15, 27));
		BaatleNpcPtr->AddScript("Script 050");
		BaatleNpcPtr->AddPokeData(PokeDataBase::PokeCreate(static_cast<int>(PokeNumber::Charmander) + 1, 4));
		BaatleNpcPtr->SetTurnDir(TurnNPC::TurnDir::Left);
		BaatleNpcPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Look);
		BaatleNpcPtr->SetLookDis(10);
	}

	// Battle2
	{
		TurnNPC* BaatleNpcPtr = CreateActor<TurnNPC>();
		BaatleNpcPtr->InitNPC("ViridianForestBattle2", "NPC4.bmp", BattleNpcType::Woong);
		BaatleNpcPtr->AddNPC("ViridianForest", int2(31, 23));
		BaatleNpcPtr->AddScript("Script 051");
		BaatleNpcPtr->AddPokeData(PokeDataBase::PokeCreate(static_cast<int>(PokeNumber::Charmander) + 1, 4));
		BaatleNpcPtr->SetTurnDir(TurnNPC::TurnDir::Left);
		BaatleNpcPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Look);
		BaatleNpcPtr->SetLookDis(10);
	}

	// Battle3
	{
		StaticNPC* BaatleNpcPtr = CreateActor<StaticNPC>();
		BaatleNpcPtr->InitNPC("ViridianForestBattle2", "NPC3.bmp", BattleNpcType::Woong);
		BaatleNpcPtr->AddNPC("ViridianForest", int2(49, 41));
		BaatleNpcPtr->AddScript("Script 040");
		BaatleNpcPtr->AddScript("Script 041");
		BaatleNpcPtr->AddPokeData(PokeDataBase::PokeCreate(static_cast<int>(PokeNumber::Charmander) + 1, 4));
		BaatleNpcPtr->SetBaseDir(LookDir::Left);
		BaatleNpcPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Look);
		BaatleNpcPtr->SetLookDis(10);
	}

	// 회색시티
	{
		StaticNPC* WoongPtr = CreateActor<StaticNPC>();
		WoongPtr->InitNPC("Woong", "Ung.bmp", BattleNpcType::Woong);
		WoongPtr->AddNPC("PewterCity_Gym", int2(6, 5));
		WoongPtr->AddScript("Script 040");
		WoongPtr->AddScript("Script 041");
		WoongPtr->AddPokeData(PokeDataBase::PokeCreate(static_cast<int>(PokeNumber::Geodude) + 1, 8));
		WoongPtr->AddPokeData(PokeDataBase::PokeCreate(static_cast<int>(PokeNumber::Onix) + 1, 12));
		WoongPtr->SetBaseDir(LookDir::Down);
		WoongPtr->SetInteractionTrigger(BaseNPC::InteractionTriggerType::Talk);
	}

	{ // 태초마을 오박사 이벤트
	
		std::function<bool()> VaildRamda = []()
		{
			if (PokemonScript::IsScriptEnd(100))
			{
				return false;
			}
			else
			{
				return true;
			}
		};

		std::function<void()> EventRamda = std::bind(
			[](FieldmapLevel* _This)
			{
				StopOakNPC* NpcPtr =_This->CreateActor<StopOakNPC>();
				NpcPtr->InitNPC("StopOak", "Oak.bmp", BattleNpcType::None);
				NpcPtr->AddNPC("PalletTown", int2::Zero, false);

				NpcPtr->AddScript("0001");
				NpcPtr->AddScript("0002");
			}
		, this);

		Fieldmap::AddStartEvent("PalletTown", int2(18, 0),
			{
			 .Name = "StopEvent",
			 .Order = -9999,
			 .VaildFunc = VaildRamda,
			 .EventFunc = EventRamda,
			 .Loop = true
			});
		Fieldmap::AddStartEvent("PalletTown", int2(19, 0),
			{
			 .Name = "StopEvent",
			 .Order = -9999,
			 .VaildFunc = VaildRamda,
			 .EventFunc = EventRamda,
			 .Loop = true
			});
	}

	MainPlayer->SetPos(Fieldmap::GetPos(6, 7));
	MainPlayer->SetPlayerSpeed(500.0f);
	MainFieldDialog = CreateActor<FieldDialog>();
	MainFieldMainMenu = CreateActor<FieldMainMenu>();
	MainMoveMapFadeEffect = CreateActor<MoveMapFadeEffect>();
	MainShopUIManager = CreateActor<ShopUIManager>(); 
	MainSelectStartingUI = CreateActor<SelectStartingUI >();
	MainPokemonCenterUI = CreateActor<PokemonCenterUI>();
}

void FieldmapLevel::Update(float _DeltaTime)
{
	if (true == EndingPlayActor::IsEndingPlay)
	{
		return;
	}

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
		MainPokemonCenterUI->CenterStart();
		//MainSelectStartingUI->TestSelectMonster();
		//MainShopUIManager->OnOffSwtich();
		//GameEngineCore::GetInst()->ChangeLevel("BuyLevel");
		//MainFieldDialog->OnOffSwtich();
	}
	if (true == GameEngineInput::IsDown("MovePC"))
	{
		Fieldmap::ChangeCity("PewterCity_PokemonCenter");
		Player::MainPlayer->SetPos(Fieldmap::GetPos("PewterCity_PokemonCenter", int2(8, 6)));
		Fieldmap::FieldUpdate();
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

void FieldmapLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	for (size_t i = 0; i < LevelStartCallFuncs.size(); i++)
	{
		LevelStartCallFuncs[i]();
	}

	LevelStartCallFuncs.clear();
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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("YesNoMenu.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_Yes.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Shop_No.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Select_Bulbasaur.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Select_Charmander.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Select_Squirtle.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonCenterBallAnimation.bmp"))->Cut(6,1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonCenterBallAnimation2.bmp"))->Cut(4,1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonCenterTVAnimation.bmp"))->Cut(4,2);
}

void FieldmapLevel::UISountLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	Dir.Move("FieldUI");
	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("MainMenuOpen.wav"));
}

void FieldmapLevel::CreateFlower(const std::string_view& _CityName, const int2& _Index)
{
}

void FieldmapLevel::CreateFieldmapCity(const std::string_view& _CityName, const std::string_view _UIName, const std::string_view& _ImageName, const float4& _Pos)
{
	FieldmapCity* PalletTownPtr = CreateActor<FieldmapCity>(-9999);

	PalletTownPtr->InitFieldRender(_CityName, _UIName, _ImageName);
	PalletTownPtr->InitPos(_Pos);
}

void FieldmapLevel::AddJumpEvent(const std::string_view& _CityName, const int2& _Start, const int2& _Add, int _Count, LookDir _Dir)
{
	int2 CurIndex = _Start;

	for (int i = 0; i < _Count; i++)
	{
		AddJumpEvent(_CityName, CurIndex, _Dir);
		CurIndex += _Add;
	}
}

void FieldmapLevel::AddJumpEvent(const std::string_view& _CityName, const int2& _Index, LookDir _Dir)
{
	switch (_Dir)
	{
	case LookDir::Up:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpUp",
			.VaildFunc = std::bind(&Player::VaildJumpUp, Player::MainPlayer),
			.EventFunc = std::bind(&Player::JumpUp, Player::MainPlayer),
			.Loop = true
			});
		break;
	case LookDir::Down:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpDown",
			.VaildFunc = std::bind(&Player::VaildJumpDown, Player::MainPlayer),
			.EventFunc = std::bind(&Player::JumpDown, Player::MainPlayer),
			.Loop = true
			});
		break;
	case LookDir::Left:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpLeft",
			.VaildFunc = std::bind(&Player::VaildJumpLeft, Player::MainPlayer),
			.EventFunc = std::bind(&Player::JumpLeft, Player::MainPlayer),
			.Loop = true
			});
		break;
	case LookDir::Right:
		Fieldmap::AddUpdateEvent(_CityName, _Index, {
			.Name = "JumpRight",
			.VaildFunc = std::bind(&Player::VaildJumpRight, Player::MainPlayer),
			.EventFunc = std::bind(&Player::JumpRight, Player::MainPlayer),
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
	BattleZone->AddPokemon(PokeNumber::Pidgey);
}

void FieldmapLevel::CreateBattlezone_Route2_Down(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route2_Down", _Start, _Size, 5, 7);
	BattleZone->AddPokemon(PokeNumber::Rattata);
	BattleZone->AddPokemon(PokeNumber::Pidgey);
}

void FieldmapLevel::CreateBattlezone_Route2_Up(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route2_Up", _Start, _Size, 8, 10);
	BattleZone->AddPokemon(PokeNumber::Geodude);
	BattleZone->AddPokemon(PokeNumber::Spearow);
}

void FieldmapLevel::CreateBattlezone_Route22(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("Route22", _Start, _Size, 12, 15);
	BattleZone->AddPokemon(PokeNumber::Rattata);
	BattleZone->AddPokemon(PokeNumber::Pidgey);
}

void FieldmapLevel::CreateBattlezone_VaridianForest(const int2& _Start, const int2& _Size)
{
	FieldmapBattleZone* BattleZone = CreateActor<FieldmapBattleZone>();

	BattleZone->InitBattleZone("ViridianForest", _Start, _Size, 5, 8);
	BattleZone->AddPokemon(PokeNumber::Bulbasaur);
	BattleZone->AddPokemon(PokeNumber::Charmander);
	BattleZone->AddPokemon(PokeNumber::Squirtle);
}