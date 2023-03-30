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
#include "CenterLevel.h"


BattleLevel* BattleLevel::BattleLevelPtr = nullptr;
const std::string_view  BattleLevel::BattleKeyName = "Battle_Z";
const char BattleLevel::BattleKey = 'Z';

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

	CenterLevel* ChangedCenterLevel = dynamic_cast<CenterLevel*>(_PrevLevel);
	if (nullptr == ChangedCenterLevel)
		return;

	//Init({ PokeDataBase::PokeCreate(1) }, GroundType::Grass);
	//Init({ PokeDataBase::PokeCreate(1) }, GroundType::Beige, BattleNpcType::Rival);
	Init({ PokeDataBase::PokeCreate(1) }, GroundType::Rock, BattleNpcType::Woong);
}

void BattleLevel::Init(
	const std::vector<PokeDataBase>& _EnemyMonsters, 
	GroundType _FieldType, BattleNpcType _NpcType)
{
	Init_Level(_EnemyMonsters, FieldConvertor(_FieldType), _NpcType);
}

void BattleLevel::Init_Level(
	const std::vector<PokeDataBase>& _EnemyMonsters, 
	BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	//배경 및 플레이어와 상대편의 바닥 이미지를 초기화
	InitActors(_FieldType, _NpcType, _EnemyMonsters);

	BattleFsmPtr = new BattleFSM(nullptr);
	BattleFsmPtr->Init(_FieldType, _NpcType);
}

void BattleLevel::InitActors(
	BattleFieldType _FieldType, BattleNpcType _NpcType, 
	const std::vector<PokeDataBase>& _EnemyMonsters)
{
	CreateActor<BattleBackGround>(UpdateOrder::Battle_Actors)->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>(UpdateOrder::Battle_Actors);
	Player->Init(_FieldType, _NpcType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>(UpdateOrder::Battle_Actors);
	Enemy->Init(_FieldType, _NpcType, _EnemyMonsters);
}








void BattleLevel::Update(float _DeltaTime)
{
	//테스트용
	if (true == TestKeyUpdate())
		return;

	BattleFsmPtr->Update(_DeltaTime);
}

bool BattleLevel::TestKeyUpdate()
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return true;
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

	BattleFsmPtr->ChangeState(BattleStateType::UseItem);
}

void BattleLevel::UseMonsterBall(ItemCode _MonsterBallType)
{
	if (BattleStateType::PlayerTurn != BattleFsmPtr->GetNowState<BattleStateType>())
	{
		MsgAssert("[배틀error] : 플레이어 차례가 아닌 경우에 몬스터볼을 사용할 수 없습니다");
		return;
	}

	if (ItemCode::MasterBall != _MonsterBallType && ItemCode::MonsterBall != _MonsterBallType)
	{
		MsgAssert("[배틀error] : 입력으로 들어온 ItemCode가 몬스터볼 종류가 아닙니다");
		return;
	}

	bool IsMasterBall = (ItemCode::MasterBall == _MonsterBallType) ? true : false;
	BattleFsmPtr->ChangeState(BattleStateType::ThrowMonsterBall);
	BattlePlayer::PlayerPtr->ThrowBallToCatch(IsMasterBall);
}

void BattleLevel::ChangePlayerMonster(PokeNumber _NextMonster)
{

}

void BattleLevel::LockWildPocketMon()
{
	if (BattleStateType::ThrowMonsterBall != BattleFsmPtr->GetNowState<BattleStateType>())
	{
		MsgAssert("몬스터볼을 던졌을때만 야생포켓몬을 잡을수 있습니다");
		return;
	}

	BattleFsmPtr->ChangeState(BattleStateType::CatchWildMonster);
}

void BattleLevel::ChangeFieldLevel()
{
	PocketMonCore::GetInst().ChangeLevel("FieldmapLevel");
}

