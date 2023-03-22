#include "BattleLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattleBackGround.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

#include "BackTextActor.h"
#include "Battle_Select.h"
#include "BattleCommendActor.h"
#include "EnemyHPBackground.h"
#include "FriendlyHPBackground.h"
#include "HpBackGroundMove.h"
#include "TestScript.h"
#include "PocketMonCore.h"
#include "BattleFSM.h"

BattleLevel* BattleLevel::BattleLevelPtr = nullptr;
const std::string_view  BattleLevel::BattleKeyName = "Battle_Z";

BattleLevel::BattleLevel()
{
	BattleLevelPtr = this;
}

BattleLevel::~BattleLevel()
{
	if (this == BattleLevelPtr)
	{
		BattleLevelPtr = nullptr;
	}

	if (nullptr != BattleFsmPtr)
	{
		delete BattleFsmPtr;
		BattleFsmPtr = nullptr;
	}
}

void BattleLevel::Loading()
{
	GameEngineInput::CreateKey(BattleKeyName, 'Z');
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
	//배경 및 플레이어와 상대편의 바닥 이미지를 초기화
	InitGroundRenders(_FieldType);

	BattleFsmPtr = new BattleFSM;
	BattleFsmPtr->Init();
	BattleFsmPtr->CreateState(BattleStateType::WildTalk);

	//야생포켓몬과 전투시
	if (BattleNpcType::None == _NpcType)
	{
		BattleFsmPtr->ChangeState(BattleStateType::WildTalk);
	}
}

void BattleLevel::InitGroundRenders(BattleFieldType _FieldType)
{
	CreateActor<BattleBackGround>()->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>();
	Player->Init(_FieldType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>();
	Enemy->Init(_FieldType);
}


void BattleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}

	BattleFsmPtr->Update(_DeltaTime);
}






void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//다음에 이동할 레벨이 전투 인벤토리 쪽이 아니라면
	//엑터들을 지운다

	if (nullptr != BattleFsmPtr)
	{
		delete BattleFsmPtr;
		BattleFsmPtr = nullptr;
	}
}