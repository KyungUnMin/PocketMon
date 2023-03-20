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
}

void BagLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void BagLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
