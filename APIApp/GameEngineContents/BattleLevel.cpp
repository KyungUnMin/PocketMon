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
	//�ӽ� �ڵ�, ������θ� ���ʿ��� ȣ�����־�� ��, ���߿� ���� ����
	//Init(BattleFieldType::Grass);
	//Init(BattleFieldType::Indoor);
	Init(BattleFieldType::Stone);
}

void BattleLevel::Init(BattleFieldType _FieldType)
{
	CreateActor<BattleBackGround>()->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>();
	Player->Init(_FieldType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>();
	Enemy->Init(_FieldType);
}


//�ӽ�
#include <GameEnginePlatform/GameEngineInput.h>
#include "PocketMonCore.h"

void BattleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange2"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}
}






void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//������ �̵��� ������ ���� �κ��丮 ���� �ƴ϶��
	//���͵��� �����


}