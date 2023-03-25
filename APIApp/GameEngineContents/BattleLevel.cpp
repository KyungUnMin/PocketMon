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
#include "BagLevel.h"
#include "PokemonLevel.h"


BattleLevel* BattleLevel::BattleLevelPtr = nullptr;
const std::string_view  BattleLevel::BattleKeyName = "Battle_Z";
const char BattleLevel::BattleKey = 'Z';
bool BattleLevel::Debug_LevelChanged = false;

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
	GameEngineInput::CreateKey(BattleKeyName, BattleKey);
	GameEngineInput::CreateKey("Test_ThrowMonsterBall", 'H');
}


void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	//임시 코드, 원래대로면 맵쪽에서 호출해주어야 함, 나중에 지울 예정
	BagLevel* BagUILevel = dynamic_cast<BagLevel*>(_PrevLevel);
	if (nullptr != BagUILevel)
		return;

	PokemonLevel* MonsterChangeLevel = dynamic_cast<PokemonLevel*>(_PrevLevel);
	if (nullptr != MonsterChangeLevel)
		return;

	Init(BattleFieldType::Forest0);
	//Init(BattleFieldType::Indoor);
	//Init(BattleFieldType::Gym);
}



void BattleLevel::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	//배경 및 플레이어와 상대편의 바닥 이미지를 초기화
	InitGroundRenders(_FieldType, _NpcType);

	BattleFsmPtr = new BattleFSM;
	BattleFsmPtr->Init(_FieldType, _NpcType);
}

void BattleLevel::InitGroundRenders(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	CreateActor<BattleBackGround>(UpdateOrder::Battle_Actors)->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>(UpdateOrder::Battle_Actors);
	Player->Init(_FieldType, _NpcType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>(UpdateOrder::Battle_Actors);
	Enemy->Init(_FieldType, _NpcType);
}


void BattleLevel::Update(float _DeltaTime)
{
	if (true == TestKeyUpdate())
		return;

	BattleFsmPtr->Update(_DeltaTime);
}

bool BattleLevel::TestKeyUpdate()
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		Debug_LevelChanged = true;
		return true;
	}

	if (true == GameEngineInput::IsDown("Test_ThrowMonsterBall"))
	{
		BattleFsmPtr->ChangeState(BattleStateType::ThrowMonsterBall);
		return false;
	}

	return false;
}





void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//가방으로 이동하는 경우엔 Actor들을 삭제하지 않음
	BagLevel* BagUILevel = dynamic_cast<BagLevel*>(_NextLevel);
	if (nullptr != BagUILevel)
		return;

	PokemonLevel* MonsterChangeLevel = dynamic_cast<PokemonLevel*>(_NextLevel);
	if (nullptr != MonsterChangeLevel)
		return;

	if (nullptr != BattleFsmPtr)
	{
		delete BattleFsmPtr;
		BattleFsmPtr = nullptr;
	}

	std::vector<GameEngineActor*> Actors = GetActors(UpdateOrder::Battle_Actors);
	for (GameEngineActor* Actor : Actors)
	{
		Actor->Death();
	}

	Actors.clear();
}



void BattleLevel::PassPlayerTurn()
{
	BattleStateType NowFsmType = BattleFsmPtr->GetNowState<BattleStateType>();

	if (BattleStateType::PlayerTurn != NowFsmType)
	{
		MsgAssert("현재 배틀 FSM은 Player차례가 아닙니다");
		return;
	}

	BattleFsmPtr->ChangeState(BattleStateType::EnemyTurn);
}

void BattleLevel::UseMonsterBall(ItemCode _MonsterBallType)
{
	//TODO
}

void BattleLevel::ChangePlayerMonster(PokeNumber _NextMonster)
{

}

