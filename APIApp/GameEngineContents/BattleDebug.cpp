#include "BattleDebug.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattleEnemy.h"
#include "PokeDataBase.h"
#include "BattleLevel.h"
#include "BattleFSM.h"

const std::vector<std::string_view> BattleDebug::DebugKeys =
{
	"Battle_Debug1",
	"Battle_Debug2",
	"Battle_Debug3",
	"Battle_Debug4"
};

BattleDebug::BattleDebug()
{

}

BattleDebug::~BattleDebug()
{

}

void BattleDebug::Start()
{
	BattleStateType NowState = BattleLevel::BattleLevelPtr->GetBattleFSM()->GetNowState<BattleStateType>();
	if (BattleStateType::PlayerTurn != NowState)
	{
		MsgAssert("플레이어 차례일때만 디버깅 기능을 사용할 수 있습니다");
		return;
	}

	//야생전일때만

	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	SetPos(ScreenSize.half());

	if (true == GameEngineInput::IsKey(DebugKeys[0]))
		return;
	
	GameEngineInput::CreateKey(DebugKeys[0], '1');
	GameEngineInput::CreateKey(DebugKeys[1], '2');
	GameEngineInput::CreateKey(DebugKeys[2], '3');
	GameEngineInput::CreateKey(DebugKeys[3], '4');
}

void BattleDebug::Update(float _DeltaTime)
{
	for (size_t i = 0; i < DebugKeys.size(); ++i)
	{
		if (false == GameEngineInput::IsDown(DebugKeys[i]))
			continue;

		ChangeWildMonster(i);
		Death();
		break;
	}
}

void BattleDebug::ChangeWildMonster(size_t _Index)
{
	PokeNumber SelectedMonster = PokeNumber::Max;
	switch (_Index)
	{
	case 0:
		SelectedMonster = PokeNumber::Pikachu;
		break;
	case 1:
		SelectedMonster = PokeNumber::Bulbasaur;
		break;
	case 2:
		SelectedMonster = PokeNumber::Charmander;
		break;
	case 3:
		SelectedMonster = PokeNumber::Squirtle;
		break;
	}

	BattleEnemy::EnemyPtr->ChangeMonster_ForDegug(SelectedMonster);
}
