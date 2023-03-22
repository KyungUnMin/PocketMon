#include "CenterLevel.h"
#include "TextTestLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "CenterActor.h"

CenterLevel::CenterLevel() 
{
}

CenterLevel::~CenterLevel() 
{
}

void CenterLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CenterActor.bmp"));

	//Battle 리소스
	{
		Dir.Move("Battle");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleFadeDown.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleFadeUp.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattlePlayer.bmp"));

		Dir.Move("Field");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Forest\\BattleForestEnemyGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Forest\\BattleForestPlayerGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Forest\\BattleForestField.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Forest\\BattleForestIntro.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Indoor\\BattleIndoorEnemyGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Indoor\\BattleIndoorPlayerGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Indoor\\BattleIndoorField.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Indoor\\BattleIndoorIntro.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gym\\BattleGymEnemyGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gym\\BattleGymPlayerGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gym\\BattleGymField.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gym\\BattleGymIntro.bmp"));

		Dir.MoveParentToDirectory("Field");
		Dir.Move("Monster");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleAppearEffect.bmp"));

		// 이상해씨
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur\\BattleBulbasaurBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur\\BattleBulbasaurFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur\\BattleBulbasaurShadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur\\BattleBulbasaurBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur\\BattleBulbasaurFrontLight.bmp"));
		
		// 파이리
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander\\BattleCharmanderBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander\\BattleCharmanderFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander\\BattleCharmanderShadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander\\BattleCharmanderBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander\\BattleCharmanderFrontLight.bmp"));

		// 꼬마돌
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Geodude\\BattleGeodudeBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Geodude\\BattleGeodudeFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Geodude\\BattleGeodudeShadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Geodude\\BattleGeodudeBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Geodude\\BattleGeodudeFrontLight.bmp"));

		// 롱스톤
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Onix\\BattleOnixBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Onix\\BattleOnixFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Onix\\BattleOnixShadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Onix\\BattleOnixBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Onix\\BattleOnixFrontLight.bmp"));

		// 구구
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey\\BattlePidgeyBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey\\BattlePidgeyFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey\\BattlePidgeyShadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey\\BattlePidgeyBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey\\BattlePidgeyFrontLight.bmp"));

		// 꼬렛
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata\\BattleRattataBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata\\BattleRattataFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata\\BattleRattataShadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata\\BattleRattataBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata\\BattleRattataFrontLight.bmp"));

		// 깨비참
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow\\BattleSpearowBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow\\BattleSpearowBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow\\BattleSpearowFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow\\BattleSpearowFrontLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow\\BattleSpearowShadow.bmp"));

		// 꼬부기
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle\\BattleSquirtleBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle\\BattleSquirtleBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle\\BattleSquirtleFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle\\BattleSquirtleFrontLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle\\BattleSquirtleShadow.bmp"));

		Dir.MoveParentToDirectory("Battle");
	}

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\Combat_TextFrame.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\EnemyHPBar.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\EnemyHPBackground.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\BattleCommend.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\Battle_Select.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\FriendlyHPBackground.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\FriendlyHPBar.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\FriendlyHPExp.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\TextFrame1.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\Battle_Arrow.bmp"));

	{
		Dir.Move("Plyer_YDM");
		Dir.Move("Player");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleUp.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleRight.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleLeft.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleDown.bmp"))->Cut(1, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkLeft.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkDown.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkRight.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkUp.bmp"))->Cut(3, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopDown.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopLeft.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopRight.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopUp.bmp"))->Cut(1, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeDown.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeLeft.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeRight.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeUp.bmp"))->Cut(3, 1);
	}

	{
		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("FieldMap");

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Empty.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DoubleDoor.bmp"))->Cut(4, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SingleDoor.bmp"))->Cut(4, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WoodDoor.bmp"))->Cut(4, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Flower.bmp"))->Cut(5, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DebugTilemap.bmp"))->Cut(8, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest_Type.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FadeInOut.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Background.bmp"));
	}

	{
		//Dir.MoveParentToDirectory("Image");
		//Dir.Move("Image");
		//Dir.Move("FieldUI_HSM");
		//GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_eng.bmp"))->Cut(27, 2);
	}
	{
		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("BagUI");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_Back.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_CurrentArrow.bmp"))->Cut(2,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_LeftArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_RightArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_UpArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_DownArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag.bmp"))->Cut(3,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_Roll.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_Shadow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_SpaceText.bmp"))->Cut(1, 3);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SelectMenu.bmp"))->Cut(5, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TextBox.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_Dialog_White.bmp"))->Cut(27, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Items.bmp"))->Cut(15,2);

		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("PokemonUI");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonUI_Back.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("HPBar.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TextBar.bmp"))->Cut(1,2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CancelButton.bmp"))->Cut(2,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gender.bmp"))->Cut(2,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MainPokemon.bmp"))->Cut(2,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SubPokemon.bmp"))->Cut(2,1);
		Dir.Move("Pokemon");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mankey_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle_mini.bmp"))->Cut(2, 1);
	}
	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange1", '1');
		GameEngineInput::CreateKey("LevelChange2", '2');
		GameEngineInput::CreateKey("LevelChange3", '3');
		GameEngineInput::CreateKey("LevelChange4", '4');
		GameEngineInput::CreateKey("LevelChange5", '5');
		GameEngineInput::CreateKey("LevelChange6", '6');

		//플레이어이동
		GameEngineInput::CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::CreateKey("UpMove", VK_UP);
		GameEngineInput::CreateKey("DownMove", VK_DOWN);
		GameEngineInput::CreateKey("RightMove", VK_RIGHT);

		//기본 키 설정(에뮬레이터 기준)
		GameEngineInput::CreateKeyNoToupper("Select", VK_RSHIFT);
		GameEngineInput::CreateKeyNoToupper("Start", VK_RETURN);
		GameEngineInput::CreateKey("A", 'z'); // 게임보이 기기의 A키를 말함
		GameEngineInput::CreateKey("B", 'x'); // 게임보이 기기의 B키를 말함
	}

	// 맵 관련 키
	if (false == GameEngineInput::IsKey("WalkableDebug"))
	{
		GameEngineInput::CreateKeyNoToupper("FreeCamera", VK_F1);
		GameEngineInput::CreateKeyNoToupper("WalkableDebug", VK_F2);
		GameEngineInput::CreateKeyNoToupper("FieldmapTypeDebug", VK_F3);
		GameEngineInput::CreateKeyNoToupper("EventDebug", VK_F4);
		GameEngineInput::CreateKeyNoToupper("EventCheck", VK_F5);
		GameEngineInput::CreateKeyNoToupper("EventLog", VK_F6);

		GameEngineInput::CreateKey("FreeCameraMoveUp", VK_UP);
		GameEngineInput::CreateKey("FreeCameraMoveDown", VK_DOWN);
		GameEngineInput::CreateKey("FreeCameraMoveLeft", VK_LEFT);
		GameEngineInput::CreateKey("FreeCameraMoveRight", VK_RIGHT);

		GameEngineInput::CreateKey("BackCenterLevel", VK_ESCAPE);
		GameEngineInput::CreateKey("CollisionRender", VK_SPACE);
	}

	//Field_UI 관련 키
	if (false == GameEngineInput::IsKey("FieldDialogSwitch"))
	{
		GameEngineInput::CreateKey("FieldUITestSwitch", 'p'); //테스트용
		GameEngineInput::CreateKeyNoToupper("FieldMainMenuSwitch", VK_RETURN);
		GameEngineInput::CreateKeyNoToupper("Menu_Up", VK_UP);
		GameEngineInput::CreateKeyNoToupper("Menu_Down", VK_DOWN);
		GameEngineInput::CreateKeyNoToupper("Menu_Left", VK_LEFT);
		GameEngineInput::CreateKeyNoToupper("Menu_Right", VK_RIGHT);
	}

	CreateActor<CenterActor>();
}

void CenterLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("LevelChange1"))
	{
		GameEngineCore::GetInst()->ChangeLevel("FieldmapLevel");
	}

	if (GameEngineInput::IsDown("LevelChange2"))
	{
		GameEngineCore::GetInst()->ChangeLevel("BattleLevel");
	}

	if (GameEngineInput::IsDown("LevelChange3"))
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayerLevel");
	}

	if (GameEngineInput::IsDown("LevelChange4"))
	{
		GameEngineCore::GetInst()->ChangeLevel("PokemonLevel");
	}

	if (GameEngineInput::IsDown("LevelChange5"))
	{
		GameEngineCore::GetInst()->ChangeLevel("BagLevel");
	}

	if (GameEngineInput::IsDown("LevelChange6"))
	{
		GameEngineCore::GetInst()->ChangeLevel("TextTestLevel");
	}
}

void CenterLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void CenterLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}