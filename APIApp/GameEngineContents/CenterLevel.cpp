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

	{
		//Battle 리소스
		Dir.Move("Battle");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleFadeDown.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BattleFadeUp.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Grass\\BattleGrassEnemyGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Grass\\BattleGrassPlayerGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Grass\\BattleGrassField.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Indoor\\BattleIndoorEnemyGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Indoor\\BattleIndoorPlayerGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Indoor\\BattleIndoorField.bmp"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Stone\\BattleStoneEnemyGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Stone\\BattleStonePlayerGround.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Field\\Stone\\BattleStoneField.bmp"));
		
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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DebugTilemap.bmp"))->Cut(4, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FieldTileSet.bmp"))->Cut(10, 10);
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
		Dir.Move("FieldUI_KKH");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_Back.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_CurrentArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_EnterArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_LeftArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_RightArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_UpArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_DownArrow.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_Items.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_PoketBalls.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_KeyItems.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_LeftOpen.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_MiddleOpen.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag_RightOpen.bmp"));
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


	}

	// 맵 관련 키
	if (false == GameEngineInput::IsKey("MapRenderDebug"))
	{
		GameEngineInput::CreateKeyNoToupper("MapRenderDebug", VK_F1);
		GameEngineInput::CreateKeyNoToupper("FreeCamera", VK_F2);

		GameEngineInput::CreateKey("FreeCameraMoveUp", VK_UP);
		GameEngineInput::CreateKey("FreeCameraMoveDown", VK_DOWN);
		GameEngineInput::CreateKey("FreeCameraMoveLeft", VK_LEFT);
		GameEngineInput::CreateKey("FreeCameraMoveRight", VK_RIGHT);
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
		GameEngineCore::GetInst()->ChangeLevel("FirstSetLevel");
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