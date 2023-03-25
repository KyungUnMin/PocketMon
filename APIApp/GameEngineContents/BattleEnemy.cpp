#include "BattleEnemy.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "BattleLevel.h"
#include "ContentsEnum.h"
#include "PokeDataBase.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyFSM.h"

BattleEnemy* BattleEnemy::EnemyPtr = nullptr;

BattleEnemy::BattleEnemy()
{
	EnemyPtr = this;
	FsmPtr = new BattleEnemyFSM;
}

BattleEnemy::~BattleEnemy()
{
	if (this == EnemyPtr)
	{
		EnemyPtr = nullptr;
	}

	if (nullptr != FsmPtr)
	{
		delete FsmPtr;
		FsmPtr = nullptr;
	}
}

void BattleEnemy::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	FsmPtr->Init(_FieldType, _NpcType);
	CreateGround(_FieldType);
}


void BattleEnemy::CreateGround(BattleFieldType _FieldType)
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float Height = 250.f;

	std::string GroundPath = "";
	switch (_FieldType)
	{
	case BattleFieldType::Indoor:
		GroundPath = "BattleIndoorEnemyGround.bmp";
		break;
	case BattleFieldType::Forest0:
	case BattleFieldType::Forest1:
		GroundPath = "BattleForestEnemyGround.bmp";
		break;
	case BattleFieldType::Gym:
		GroundPath = "BattleGymEnemyGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, BattleRenderOrder::Ground);
	GroundRender->SetScaleToImage();
}





void BattleEnemy::CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	switch (_NpcType)
	{
	case BattleNpcType::None:
		CreateWildMonster(_FieldType);
		break;
	case BattleNpcType::Woong:
		break;
	default:
		MsgAssert("아직 어떤 NPC와 싸울지 결정해주지 않았습니다");
		break;
	}
}



void BattleEnemy::CreateWildMonster(BattleFieldType _FieldType)
{
	const float4 CreateOffset = float4::Up * 100.f;
	std::vector<PokeNumber> MonsterNumsters;

	switch (_FieldType)
	{
	case BattleFieldType::Forest0:
		//꼬렛, 구구
		MonsterNumsters = std::vector<PokeNumber>{ PokeNumber::Rattata, PokeNumber::Pidgey };
		break;
	case BattleFieldType::Forest1:
		//이상해씨, 파이리, 꼬부기
		MonsterNumsters = std::vector<PokeNumber>{ PokeNumber::Bulbasaur, PokeNumber::Charmander, PokeNumber::Squirtle };
		break;
	case BattleFieldType::Forest2:
		MonsterNumsters = std::vector<PokeNumber>{ PokeNumber::Geodude, PokeNumber::Spearow };
		break;
	default:
		MsgAssert("해당 지역에서는 야생포켓몬과 싸울수 없습니다");
		break;
	}

	int MonIndex = GameEngineRandom::MainRandom.RandomInt(0, static_cast<int>(MonsterNumsters.size() - 1));
	Monster = GetLevel()->CreateActor<BattleMonsterEnemy>(UpdateOrder::Battle_Actors);
	Monster->Init(static_cast<PokeNumber>(MonsterNumsters[MonIndex]), true);
}



void BattleEnemy::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}