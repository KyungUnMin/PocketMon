#include "CenterLevel.h"
#include "TextTestLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "CenterActor.h"
#include "BattleDefine.h"
#include "PlayTime.h"

CenterLevel::CenterLevel() 
{
}

CenterLevel::~CenterLevel() 
{
}

void CenterLevel::Loading()
{
	CreateActor<PlayTime>();

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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattlePlayer.bmp"))->Cut(5, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleFadeWhite.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleFadeBlack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleDebug.bmp"));

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

		Dir.Move("NPC");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleNPC_Rival.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleNPC_Woong.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleNPC_3.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleNPC_2.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleNPC_Leaf.bmp"));
		Dir.MoveParentToDirectory("NPC");

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

		// 피카츄
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pikachu\\BattlePikachuBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pikachu\\BattlePikachuBackLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pikachu\\BattlePikachuFront.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pikachu\\BattlePikachuFrontLight.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pikachu\\BattlePikachuShadow.bmp"));
		Dir.MoveParentToDirectory("Monster");


		Dir.Move("MonsterBall");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleBallParticle.bmp"))->Cut(7, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMonsterBall.bmp"))->Cut(8, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMonsterBallOpen.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMonsterBallRoll.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMonsterBallCatch.bmp"))->Cut(4, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMasterBall.bmp"))->Cut(8, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMasterBallOpen.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMasterBallRoll.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleMasterBallCatch.bmp"))->Cut(4, 1);
		Dir.MoveParentToDirectory("MonsterBall");

		Dir.Move("Skill");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tackle.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ThunderBack.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rock.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Growl1.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Growl2.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Growl3.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Scratch.bmp"))->Cut(1, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Leer_or_other.bmp"))->Cut(1, 8);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FeatherDance.bmp"))->Cut(1, 8);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Agility.bmp"))->Cut(1, 8);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SuperFang.bmp"))->Cut(1, 8);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Ember.bmp"))->Cut(1, 7);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DragonBreath.bmp"))->Cut(1, 7);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bubble.bmp"))->Cut(1, 3);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DefenseCurl.bmp"))->Cut(1, 8);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RazorLeaf.bmp"))->Cut(1, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Leafs.bmp"))->Cut(1, 9);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Leafs_L.bmp"))->Cut(1, 9);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("VineWhip.bmp"))->Cut(1, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Vine_R.bmp"))->Cut(1, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Vine_L.bmp"))->Cut(1, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WaterGun_R.bmp"))->Cut(1, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WaterGun_L.bmp"))->Cut(1, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WaterGun_After.bmp"))->Cut(1, 3);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("AirSlash.bmp"))->Cut(1, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bite.bmp"))->Cut(1, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gust.bmp"))->Cut(1, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Thunder.bmp"))->Cut(1, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Thunderbolt_After.bmp"))->Cut(1, 6);
		//TODO

		Dir.MoveParentToDirectory("Skill");




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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\BattleStatus.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\BattleStatusTwo.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\FriendlyHP50Bar.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\FriendlyHP30Bar.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\EnemyHP50Bar.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleUI\\EnemyHP30Bar.bmp"));



	{
		Dir.Move("Plyer_YDM");
		Dir.Move("Player");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleUp.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleRight.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleLeft.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IdleDown.bmp"))->Cut(1, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkLeft.bmp"))->Cut(4, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkDown.bmp"))->Cut(4, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkRight.bmp"))->Cut(4, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WalkUp.bmp"))->Cut(4, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopDown.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopLeft.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopRight.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeStopUp.bmp"))->Cut(1, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeDown1.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeLeft.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeRight.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BikeUp.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("shadow.bmp"))->Cut(1, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Jumpeffect.bmp"))->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GymClear.bmp"))->Cut(6, 1);

		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Image");
		Dir.Move("Plyer_YDM");
		Dir.Move("NPC");
		Dir.Move("7");

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC_Shop.bmp"))->Cut(1, 1);
	}

	{
	
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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BushEffect.bmp"))->Cut(4, 1);

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DebugTilemap.bmp"))->Cut(8, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Center_1F_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityGym_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityHouse_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_1F_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("GreyCityMuseum_2F_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Market_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_1F_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Myroom_2F_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Office_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rivalroom_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Up_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route22_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity_Front.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest_Col.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest_Type.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianForest_Front.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PewterCity_Flower.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route2_Down_Flower.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ViridianCity_Flower.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Route1_Flower.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PalletTown_Flower.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pokeball.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FadeInOut.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Background.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CutableTree.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CityNameUI.bmp"));
	}

	{
		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("NPC");

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FieldItem.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Green.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC1.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC2.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC3.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC4.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC5.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC6.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC7.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Nurse.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Oak.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Professor.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Ung.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mother.bmp"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Leaf.bmp"))->Cut(4, 6);
	}

	{
		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("Ending");

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingWalk.bmp"))->Cut(6, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndPokeballBlue.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndPokeballRed.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndPokeballYellow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndPokeballGreen.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingRing.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndLogo.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingGround.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingPokemon001.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingPokemon002.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingPokemon003.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingPokemon004.bmp"))->Cut(2, 1);
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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_Dialog_Orange.bmp"))->Cut(27, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_Dialog_Black.bmp"))->Cut(27, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Font_Dialog_Black2.bmp"))->Cut(27, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Items.bmp"))->Cut(7,2);

		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("PokemonUI");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonUI_Back.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("HPBar.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonItem.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TextBar.bmp"))->Cut(1,2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CancelButton.bmp"))->Cut(2,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Gender.bmp"))->Cut(2,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MainPokemon.bmp"))->Cut(2,3);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SubPokemon.bmp"))->Cut(7,1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Types.bmp"))->Cut(3,6);
		Dir.Move("Pokemon");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bulbasaur_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Charmander_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mankey_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pidgey_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rattata_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spearow_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Squirtle_mini.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Pikachu_mini.bmp"))->Cut(2, 1);
		Dir.MoveParentToDirectory("PokemonUI");
		Dir.Move("PokemonUI");
		Dir.Move("Summary");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonInfo.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonSkills.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonMoves.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PokemonMovesSwitch.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MoveSelect.bmp"))->Cut(1, 2);
	}

	// Opening
	{
		Dir.MoveParentToDirectory("Image");
		Dir.Move("Image");
		Dir.Move("Opening");

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Back1.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Back2.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Back3.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Backeffect.bmp"))->Cut(1, 6);;
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Charizard.bmp"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Charizard_White.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Fireredversion.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Fireredversion_White.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Gamefreakinc.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Pokemon.bmp"))->Cut(6, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_Pokemon_White.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Logo_PressStart.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Opening_Text.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BlackBox.bmp"));
	}

//////////////////////////////////////////////////////////// Sound
	{
		Dir.MoveParentToDirectory("Image");
		Dir.Move("Sound");
		Dir.Move("Opening");

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Title(recorder).mp3"));             // 오프닝(리코더)
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Title.mp3"));						  // 오프닝
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Growl.mp3"));						  // 울음소리
	}

	//필드맵 사운드
	{
		
		Dir.MoveParentToDirectory("Sound");
		Dir.Move("Sound");
		Dir.Move("Fieldmap");
		Dir.Move("BGM");
		
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("World_PalletTown.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("World_OakLap.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("World_Route1.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("GrayCity2.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Route_2.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Route_22.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("World_ViridianCity.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("World_ViridianForest.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("World_Gym.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("PokemonCenter.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Shop.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Ending_Theme.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("RivalAppears.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BeforeBattle.mp3"));
		
		Dir.MoveParent();
		Dir.Move("Effect");
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("GetFirstPokemon.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Badge_Obtained.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Item_Obtained.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("ExitBuilding.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("SlideDoorOpen.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("WoodDoorOpen.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BikeBell.wav"));

	}

	//엔딩 사운드
	{

		Dir.MoveParentToDirectory("Sound");
		Dir.Move("Sound");
		Dir.Move("Ending");

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BlastoiseHolw.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("CharizardHolw.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("PikachuHolw.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("VenusaurHolw.wav"));
	}

	{
		//배틀 사운드
		Dir.MoveParentToDirectory("Battle");
		Dir.Move("Battle");
		Dir.Move("BGM");
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_WildBGM.mp3"));             // 야생포켓몬 배틀 BGM

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_Master.mp3"));              // 의문의 마스터 배틀 BGM
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Victory_Gym.mp3"));                // Gym 승리
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_NPC.mp3"));                 // 일반NPC 배틀 BGM
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_Pikachu1.mp3"));            // 피카츄 배틀 BGM 1 (1~2 중 고르면 됨)
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_Pikachu2.mp3"));            // 피카츄 배틀 BGM 2 (1~2 중 고르면 됨)
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_Gym1.mp3"));			     // 보스 배틀 BGM 2 (1~2 중 고르면 됨)
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Battle_Gym2.mp3"));				 // 보스 배틀 BGM 2 (1~2 중 고르면 됨)


		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Wild_Victory.mp3"));			     // 전투 승리 시 BGM

		Dir.MoveParentToDirectory("SFX");
		Dir.Move("SFX");
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName(BattleDefine::SfxName_Tackle));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName(BattleDefine::SfxName_BallPop));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Scratch.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BuffSound.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("DebuffSound.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("VineWhip.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Ember.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Flamethrower.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Earthquake.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("RockThrow.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("RazorLeaf.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("AirSlash.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Bubble.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("DefenseCurl.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("IronDefense.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("DoubleEdge.mp3"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Growl.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Gust.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Leer.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("TailWhip.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Thunder.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Thunderbolt.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("WaterGun.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("HyperFang.wav"));

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Pokemon_Caught.mp3"));             // 포켓몬 포획 성공
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("NormalDamage.wav"));               // 공격 시 노말 데미지일 때 사운드
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("SuperEffectiveDamage.wav"));       // 효과는 굉장했다 사운드
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("fainting.wav"));				     // 포켓몬 기절 (쓰러뜨림)
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("PokemonSwapout.wav"));             // 포켓몬 교체 시 퇴장 사운드
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Running.wav"));				     // 야생 포켓몬에게서 도주
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("EXPGain.wav"));				     // 경험치 획득


		Dir.MoveParentToDirectory("Battle");
	}
	{
		//UI 사운드 로드하는곳이에요
		Dir.MoveParentToDirectory("FieldUI"); 
		Dir.Move("FieldUI");

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("UsePotion.wav"));                // 포션 사용했을 때 체력회복 사운드

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("MainMenuOpen.wav"));             // 필드 UI 창 오픈
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("MenuButton.wav"));               // 메뉴 버튼 사운드 (이동)
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("CenterPutBall.wav"));            // 포켓몬 센터 몬스터볼 놓기
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Healed.mp3"));                   // 포켓몬 센터 체력 회복
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BuySound.wav"));                 // 아이템 구매 사운드
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Exit_TrainerCard.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("ExpUp.wav")); 
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("HpLow.wav")); 

		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Potion.wav"));
	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange1", '1');
		GameEngineInput::CreateKey("LevelChange2", '2');
		GameEngineInput::CreateKey("LevelChange3", '3');
		GameEngineInput::CreateKey("LevelChange4", '4');
		GameEngineInput::CreateKey("LevelChange5", '5');
		GameEngineInput::CreateKey("LevelChange6", '6');
		GameEngineInput::CreateKey("LevelChange7", '7');
		GameEngineInput::CreateKey("LevelChange8", '8');

		GameEngineInput::CreateKey("BattleSelect1111", 'Z');

		//플레이어이동
		GameEngineInput::CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::CreateKey("UpMove", VK_UP);
		GameEngineInput::CreateKey("DownMove", VK_DOWN);
		GameEngineInput::CreateKey("RightMove", VK_RIGHT);

		GameEngineInput::CreateKey("PlayerAutoMoveDebug", '0');

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
		GameEngineInput::CreateKeyNoToupper("EventLog", 'L');
		GameEngineInput::CreateKeyNoToupper("StartEventCheck", VK_F6);
		GameEngineInput::CreateKeyNoToupper("UpdateEventCheck", VK_F7);
		GameEngineInput::CreateKeyNoToupper("EndEventCheck", VK_F8);
		GameEngineInput::CreateKeyNoToupper("PlayEnding", VK_F9);
		GameEngineInput::CreateKeyNoToupper("AddMove", 'M');

		GameEngineInput::CreateKey("FreeCameraMoveUp", VK_UP);
		GameEngineInput::CreateKey("FreeCameraMoveDown", VK_DOWN);
		GameEngineInput::CreateKey("FreeCameraMoveLeft", VK_LEFT);
		GameEngineInput::CreateKey("FreeCameraMoveRight", VK_RIGHT);

		GameEngineInput::CreateKey("BackCenterLevel", VK_ESCAPE);
		GameEngineInput::CreateKey("CollisionRender", VK_SPACE);

		GameEngineInput::CreateKey("FadeOnBGM", 'N');
		GameEngineInput::CreateKey("FadeOutBGM", 'B');
		GameEngineInput::CreateKey("Ridefalse", 'C');
	}

	//Field_UI 관련 키
	if (false == GameEngineInput::IsKey("FieldDialogSwitch"))
	{
		GameEngineInput::CreateKey("FieldUITestSwitch", 'p'); //테스트용
		GameEngineInput::CreateKey("MovePC", 'm'); //테스트용
		GameEngineInput::CreateKeyNoToupper("FieldMainMenuSwitch", VK_RETURN);
		GameEngineInput::CreateKeyNoToupper("Menu_Up", VK_UP);
		GameEngineInput::CreateKeyNoToupper("Menu_Down", VK_DOWN);
		GameEngineInput::CreateKeyNoToupper("Menu_Left", VK_LEFT);
		GameEngineInput::CreateKeyNoToupper("Menu_Right", VK_RIGHT);
	}
	//Battle_UI 관련 키
	if (false == GameEngineInput::IsKey("BattleUI_Next"))
	{
		GameEngineInput::CreateKey("BattleUI_Next", 'Z'); 
		GameEngineInput::CreateKey("BattleUI_Input", 'Z'); 
		GameEngineInput::CreateKeyNoToupper("CommendLeft", VK_LEFT);
		GameEngineInput::CreateKeyNoToupper("CommendRight", VK_RIGHT);
		GameEngineInput::CreateKeyNoToupper("commendUp", VK_UP);
		GameEngineInput::CreateKeyNoToupper("commendDown", VK_DOWN);
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
	if (GameEngineInput::IsDown("LevelChange7"))
	{
		GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
	}

	if (GameEngineInput::IsDown("LevelChange8"))
	{
		GameEngineCore::GetInst()->ChangeLevel("OpeningLevel");
	}
}

void CenterLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("Title(recorder).mp3");
	BGMPlayer.Volume(0.5f);
	BGMPlayer.LoopCount(10);
}

void CenterLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	BGMPlayer.Stop();
}