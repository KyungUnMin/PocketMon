#include "BattleLevel.h"
#include "BattleBackGround.h"
#include "BattlePlayer.h"
#include "BattleNPC.h"

const float BattleLevel::IntroTime = 2.f;

BattleLevel::BattleLevel()
{

}

BattleLevel::~BattleLevel()
{

}

void BattleLevel::Loading()
{
	CreateActor<BattleBackGround>();
}

#include <GameEnginePlatform/GameEngineInput.h>
#include "PocketMonCore.h"

void BattleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange2"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}
}





void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BattlePlayer* P1 = CreateActor<BattlePlayer>();
	BattleNPC* P2 = CreateActor<BattleNPC>();
}


void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}