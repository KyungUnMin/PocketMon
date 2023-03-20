#include "BattleLevel.h"
#include "BattleBackGround.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

BattleLevel::BattleLevel()
{

}

BattleLevel::~BattleLevel()
{

}




void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	//임시 코드, 원래대로면 맵쪽에서 호출해주어야 함, 나중에 지울 예정
	Init(BattleFieldType::Forest0);
	//Init(BattleFieldType::Indoor);
	//Init(BattleFieldType::Gym);
}

void BattleLevel::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	CreateActor<BattleBackGround>()->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>();
	Player->Init(_FieldType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>();
	Enemy->Init(_FieldType, _NpcType);
}


//임시
#include <GameEnginePlatform/GameEngineInput.h>
#include "PocketMonCore.h"

void BattleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}
}






void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//다음에 이동할 레벨이 전투 인벤토리 쪽이 아니라면
	//엑터들을 지운다


}