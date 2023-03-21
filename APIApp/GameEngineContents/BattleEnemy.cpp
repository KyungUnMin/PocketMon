#include "BattleEnemy.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "BattleLevel.h"
#include "ContentsEnum.h"
#include "BattleMonsterBase.h"
#include "PokeDataBase.h"

BattleEnemy* BattleEnemy::EnemyPtr = nullptr;

BattleEnemy::BattleEnemy()
{
	EnemyPtr = this;
}

BattleEnemy::~BattleEnemy()
{
	if (this == EnemyPtr)
	{
		EnemyPtr = nullptr;
	}
}

void BattleEnemy::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	CreateGround(_FieldType);
	CreateNpc(_FieldType, _NpcType);
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

	GameEngineRender* GroundRender = CreateRender(GroundPath, RenderOrder::BattleGround);
	GroundRender->SetScaleToImage();

	const float4& RenderScale = GroundRender->GetScale();
	SetMovePositions({ -RenderScale.hx(), Height }, { ScreenSize.x - RenderScale.hx(), Height });
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
		MsgAssert("���� � NPC�� �ο��� ���������� �ʾҽ��ϴ�");
		break;
	}
}

void BattleEnemy::CreateWildMonster(BattleFieldType _FieldType)
{
	std::vector<PokeNumber> MonsterNumsters;

	switch (_FieldType)
	{
	case BattleFieldType::Forest0:
		//����, ����
		MonsterNumsters = std::vector<PokeNumber>{ PokeNumber::Rattata, PokeNumber::Pidgey };
		break;
	case BattleFieldType::Forest1:
		//�̻��ؾ�, ���̸�, ���α�
		MonsterNumsters = std::vector<PokeNumber>{ PokeNumber::Bulbasaur, PokeNumber::Charmander, PokeNumber::Squirtle };
		break;
	default:
		MsgAssert("�ش� ���������� �߻����ϸ�� �ο�� �����ϴ�");
		break;
	}

	int MonIndex = GameEngineRandom::MainRandom.RandomInt(0, static_cast<int>(MonsterNumsters.size() - 1));
	//Monster = BattleMonsterBase::CreateMonster(GetLevel(), MonsterNumsters[MonIndex], false);

	//�ӽ�
	Monster = BattleMonsterBase::CreateMonster(GetLevel(), PokeNumber::Bulbasaur, BattleMonsterType::WildMon);
}
