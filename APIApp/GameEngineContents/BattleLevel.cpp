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
	"앗 포켓몬",
	"야생",
	"싸울까"
};



void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	//임시 코드, 원래대로면 맵쪽에서 호출해주어야 함, 나중에 지울 예정
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
	//ScriptPtr = CreateActor<TestScript>();// 대사들 띄우고 뭐하고

	Box = CreateActor<BackTextActor>();
	Box->PushTexts(TestStr);

	//띄우기 위해 조건이 필요할 때
	/*CreateActor<EnemyHPBackground>();
	CreateActor<FriendlyHPBackground>();*/
}


//임시
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
	//다음에 이동할 레벨이 전투 인벤토리 쪽이 아니라면
	//엑터들을 지운다


}