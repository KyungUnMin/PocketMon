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
	GameEngineInput::CreateKey("Test_ThrowMonsterBall", 'H');
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

	CenterLevel* ChangedCenterLevel = dynamic_cast<CenterLevel*>(_PrevLevel);
	if (nullptr == ChangedCenterLevel)
		return;

	Init({ PokeDataBase::PokeCreate(1) }, GroundType::Grass);
	//Init_Level(BattleFieldType::Forest);
	//Init(BattleFieldType::Indoor, BattleNpcType::Rival);
	//Init(BattleFieldType::Gym);
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
	//��� �� �÷��̾�� ������� �ٴ� �̹����� �ʱ�ȭ
	InitGroundRenders(_FieldType, _NpcType, _EnemyMonsters);

	BattleFsmPtr = new BattleFSM;
	BattleFsmPtr->Init(_FieldType, _NpcType);
}

void BattleLevel::InitGroundRenders(
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
	//�׽�Ʈ��
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

	if (true == GameEngineInput::IsDown("Test_ThrowMonsterBall"))
	{
		UseMonsterBall(ItemCode::MonsterBall);
		return false;
	}

	return false;
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
	BattleStateType NowFsmType = BattleFsmPtr->GetNowState<BattleStateType>();

	if (BattleStateType::PlayerTurn != NowFsmType)
	{
		MsgAssert("���� ��Ʋ FSM�� Player���ʰ� �ƴմϴ�");
		return;
	}

	BattleFsmPtr->ChangeState(BattleStateType::EnemyTurn);
}

void BattleLevel::UseMonsterBall(ItemCode _MonsterBallType)
{
	if (BattleStateType::PlayerTurn != BattleFsmPtr->GetNowState<BattleStateType>())
	{
		MsgAssert("[��Ʋerror] : �÷��̾� ���ʰ� �ƴ� ��쿡 ���ͺ��� ����� �� �����ϴ�");
		return;
	}

	if (ItemCode::MasterBall != _MonsterBallType && ItemCode::MonsterBall != _MonsterBallType)
	{
		MsgAssert("[��Ʋerror] : �Է����� ���� ItemCode�� ���ͺ� ������ �ƴմϴ�");
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
		MsgAssert("���ͺ��� ���������� �߻����ϸ��� ������ �ֽ��ϴ�");
		return;
	}

	BattleFsmPtr->ChangeState(BattleStateType::CatchWildMonster);
}

