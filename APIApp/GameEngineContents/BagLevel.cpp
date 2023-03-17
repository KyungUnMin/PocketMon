#include "BagLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "PocketMonCore.h"
#include "BagUI.h"
BagLevel::BagLevel() {

}

BagLevel::~BagLevel() {

}

void BagLevel::Loading()
{
	CreateActor<BagUI>();
}

void BagLevel::Update(float _DeltaTime)
{
	// 5번키를 누르면 다시 CenterLevel로 이동
	if (GameEngineInput::IsDown("LevelChange5"))
	{
		GameEngineCore::GetInst()->ChangeLevel("CenterLevel");
	}
}

void BagLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void BagLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
