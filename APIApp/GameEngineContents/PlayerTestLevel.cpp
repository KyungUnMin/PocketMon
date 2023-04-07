#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

#include "PocketMonCore.h"

#include "Player.h"
#include "PlayerTestLevel.h"
#include "ShopNpc.h"





PlayerTestLevel::PlayerTestLevel()
{

}

PlayerTestLevel::~PlayerTestLevel()
{
}
void PlayerTestLevel::Loading()
{
	// 액터 생성
	{
		//CreateActor<Player>();
		/*NPC1* TestNpc = CreateActor<NPC1>();
		TestNpc->SetPos({ 300,300 });*/
	}
		
}

void PlayerTestLevel::Update(float _DeltaTime)
{
}


void PlayerTestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}


