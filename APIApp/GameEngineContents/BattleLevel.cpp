#include "BattleLevel.h"
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

BattleLevel::BattleLevel()
{

}

BattleLevel::~BattleLevel()
{

}

#include <string_view>
#include <GameEnginePlatform/GameEngineInput.h>

std::vector<std::string_view> TestStr =
{
	"�� ���ϸ�",
	"�߻�",
	"�ο��"
};



void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	//�ӽ� �ڵ�, ������θ� ���ʿ��� ȣ�����־�� ��, ���߿� ���� ����
	Init(BattleFieldType::Forest0);
	//Init(BattleFieldType::Indoor);
	//Init(BattleFieldType::Gym);

	GameEngineInput::CreateKey("TestZ", 'Z');
}

void BattleLevel::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	CreateActor<BattleBackGround>()->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>();
	Player->Init(_FieldType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>();
	Enemy->Init(_FieldType, _NpcType);

	/*CreateActor<BackTextActor>();
	CreateActor<Battle_Select>();
	CreateActor<BattleCommendActor>();
	CreateActor<EnemyHPBackground>();
	CreateActor<FriendlyHPBackground>();
	CreateActor<HpBackGroundMove>();
	CreateActor<TestScript>();*/

	//CreateActor<BackTextActor>();
	//ScriptPtr = CreateActor<TestScript>();// ���� ���� ���ϰ�

	Box = CreateActor<BackTextActor>();
	Box->PushTexts(TestStr);

	//���� ���� ������ �ʿ��� ��
	/*CreateActor<EnemyHPBackground>();
	CreateActor<FriendlyHPBackground>();*/
}


//�ӽ�
#include <GameEnginePlatform/GameEngineInput.h>
#include "PocketMonCore.h"

void BattleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}

	if (true == GameEngineInput::IsDown("TestZ"))
	{
		if(false == Box->WriteText())
		{
			int a = 10;
		}
		
	}

	/*static bool IsCreate = false;
	if (false == IsCreate && (3 == ScriptPtr->GetTextCount()))
	{
		CreateActor<Battle_Select>()->init(ScriptPtr);
		IsCreate = true;
	}*/
}






void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//������ �̵��� ������ ���� �κ��丮 ���� �ƴ϶��
	//���͵��� �����


}