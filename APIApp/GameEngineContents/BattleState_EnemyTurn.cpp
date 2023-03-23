#include "BattleState_EnemyTurn.h"
#include <GameEngineBase/GameEngineTimeEvent.h>
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleFSM.h"

BattleState_EnemyTurn::BattleState_EnemyTurn()
{

}

BattleState_EnemyTurn::~BattleState_EnemyTurn()
{

}

void BattleState_EnemyTurn::EnterState()
{
	BattleLevel::Debug_LevelChanged = false;

	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfoUI->BattleSetText("Enemy Attacking...");

	BattleLevel::BattleLevelPtr->LevelEvent.AddEvent(3.f, [](GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)
	{
		if (true == BattleLevel::Debug_LevelChanged)
			return;

		BattleLevel::BattleLevelPtr->GetBattleFSM()->ChangeState(BattleStateType::PlayerTurn);
	});
}

void BattleState_EnemyTurn::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;
}
