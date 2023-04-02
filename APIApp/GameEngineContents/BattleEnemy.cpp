#include "BattleEnemy.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "BattleLevel.h"
#include "ContentsEnum.h"
#include "PokeDataBase.h"
#include "BattleMonsterEnemy.h"
#include "BattleEnemyFSM.h"
#include "PokeDataBase.h"

BattleEnemy* BattleEnemy::EnemyPtr = nullptr;

BattleEnemy::BattleEnemy()
{
	EnemyPtr = this;
	FsmPtr = new BattleEnemyFSM(this);
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

void BattleEnemy::Init(BattleFieldType _FieldType, BattleNpcType _NpcType, const std::vector<PokeDataBase>& _EnemyMonsters)
{
	MonsterDatas = _EnemyMonsters;

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
	static const float4 Offset = float4{ 0.f, -100.f };

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
	EnemyRender->SetPosition(Offset);
}




void BattleEnemy::CreateWildMonster(BattleFieldType _FieldType)
{
	//const float4 CreateOffset = float4::Up * 100.f;
	
	if (MonsterDatas.size() <= CurIndex)
	{
		MsgAssert("몬스터를 넣어주지 않았습니다");
		return;
	}
	
	PokeDataBase& MonsterDB = MonsterDatas[CurIndex];
	Monster = GetLevel()->CreateActor<BattleMonsterEnemy>(UpdateOrder::Battle_Actors);
	Monster->Init(&MonsterDB, true);
	++CurIndex;
}

void BattleEnemy::CreateMonster()
{
	const float4 CreateOffset = float4::Up * 50.f;

	if (false == IsValidNextMonster())
	{
		MsgAssert("[배틀] : 적이 더이상 꺼낼 포켓몬이 없습니다");
		return;
	}

	if (nullptr != Monster)
	{
		Monster->Death();
	}

	PokeDataBase& MonsterDB = MonsterDatas[CurIndex];
	Monster = GetLevel()->CreateActor<BattleMonsterEnemy>(UpdateOrder::Battle_Actors);
	Monster->Init(&MonsterDB, false);
	Monster->SetPos(GetPos() + CreateOffset);
	++CurIndex;

	FsmPtr->ChangeState(BattleEnemy_StateType::CreateMonster);
}






bool BattleEnemy::IsValidNextMonster()
{
	return CurIndex < MonsterDatas.size();
}

void BattleEnemy::ComeBack()
{
	FsmPtr->ChangeState(BattleEnemy_StateType::ComeBack);
}

void BattleEnemy::ChangeMonster_ForDegug(PokeNumber _Index)
{

}

void BattleEnemy::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}


PokeDataBase* BattleEnemy::GetMonsterDB()
{
	if (nullptr == Monster)
		return nullptr;

	return Monster->GetDB();
}