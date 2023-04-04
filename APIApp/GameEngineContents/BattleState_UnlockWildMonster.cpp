#include "BattleState_UnlockWildMonster.h"
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "BattleFSM.h"

BattleState_UnlockWildMonster::BattleState_UnlockWildMonster()
{

}

BattleState_UnlockWildMonster::~BattleState_UnlockWildMonster()
{

}

void BattleState_UnlockWildMonster::EnterState()
{
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("Ah..!!\nI failed to catch Pokemon");
}

void BattleState_UnlockWildMonster::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	GetFSM()->ChangeState(BattleStateType::EnemyTurn);
}

void BattleState_UnlockWildMonster::ExitState()
{
	TextInfo->Death();
	TextInfo = nullptr;

	Timer = 0.f;
}
