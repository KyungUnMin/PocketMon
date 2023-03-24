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
}


void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	//�ӽ� �ڵ�, ������θ� ���ʿ��� ȣ�����־�� ��, ���߿� ���� ����
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
	//��� �� �÷��̾�� ������� �ٴ� �̹����� �ʱ�ȭ
	InitGroundRenders(_FieldType);

	BattleFsmPtr = new BattleFSM;
	BattleFsmPtr->Init(_FieldType, _NpcType);
}

void BattleLevel::InitGroundRenders(BattleFieldType _FieldType)
{
	CreateActor<BattleBackGround>(UpdateOrder::Battle_Actors)->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>(UpdateOrder::Battle_Actors);
	Player->Init(_FieldType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>(UpdateOrder::Battle_Actors);
	Enemy->Init(_FieldType);
}


void BattleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		Debug_LevelChanged = true;
		return;
	}

	BattleFsmPtr->Update(_DeltaTime);
}






void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//�������� �̵��ϴ� ��쿣 Actor���� �������� ����
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
	BattleStateType NowFsmType = BattleFsmPtr->GetNowState();

	if (BattleStateType::PlayerTurn != NowFsmType)
	{
		MsgAssert("���� ��Ʋ FSM�� Player���ʰ� �ƴմϴ�");
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