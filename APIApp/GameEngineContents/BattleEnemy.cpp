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
	RenderCreate(_NpcType);
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
	case BattleFieldType::Forest:
		GroundPath = "BattleForestEnemyGround.bmp";
		break;
	case BattleFieldType::Gym:
		GroundPath = "BattleGymEnemyGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, BattleRenderOrder::Ground);
	GroundRender->SetScaleToImage();
}


void BattleEnemy::RenderCreate(BattleNpcType _NpcType)
{
	std::string ImagePath = "BattleNPC_";

	switch (_NpcType)
	{
	case BattleNpcType::None:
		return;
	case BattleNpcType::Rival:
		ImagePath += "Rival.bmp";
		break;
	case BattleNpcType::Woong:
		ImagePath += "Woong.bmp";
		break;
	default:
		MsgAssert("아직 해당 NPC를 구현하지 않았습니다");
		break;
	}

	EnemyRender = CreateRender(ImagePath, BattleRenderOrder::Player0);
	EnemyRender->SetScaleToImage();
}




void BattleEnemy::CreateWildMonster(BattleFieldType _FieldType)
{
	if (MonsterDatas.size() <= CurIndex)
	{
		MsgAssert("몬스터를 넣어주지 않았습니다");
		return;
	}
	
	//const float4 CreateOffset = float4::Up * 100.f;
	
	int PokeNum = MonsterDatas[CurIndex]->GetPokeNumber();
	Monster = GetLevel()->CreateActor<BattleMonsterEnemy>(UpdateOrder::Battle_Actors);
	Monster->Init(static_cast<PokeNumber>(PokeNum - 1), true);
}

void BattleEnemy::CreateMonster(PokeNumber _Number)
{
	//const float4 CreateOffset = float4::Up * 100.f;

	Monster = GetLevel()->CreateActor<BattleMonsterEnemy>(UpdateOrder::Battle_Actors);
	Monster->Init(_Number, false);
	Monster->SetPos(GetPos());
}






void BattleEnemy::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}


PokeDataBase* BattleEnemy::GetMonsterDB()
{
	return Monster->GetDB();
}