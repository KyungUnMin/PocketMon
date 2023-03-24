#include "BagLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "PocketMonCore.h"
#include "PlayerBag.h"
BagLevel::BagLevel() {

}

BagLevel::~BagLevel() {

}

void BagLevel::Loading()
{
	CreateActor<PlayerBag>();
}

void BagLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange1"))
	{
		PlayerBag::MainBag->AddItem(ItemCode::Potion);
		PlayerBag::MainBag->AddItem(ItemCode::MonsterBall);
		return;
	}
	if (true == GameEngineInput::IsDown("LevelChange2"))
	{
		PlayerBag::MainBag->BattleOn();
		return;
	}
}

void BagLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void BagLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
