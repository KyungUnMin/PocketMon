#include "BattlePlayerMonsterFSM.h"
#include "BattlePlayerMonster_CreateState.h"
#include "BattleStateIdle.h"

BattlePlayerMonsterFSM::BattlePlayerMonsterFSM()
{

}

BattlePlayerMonsterFSM::~BattlePlayerMonsterFSM()
{

}

void BattlePlayerMonsterFSM::Init()
{
	ResizeStates(BattlePlayerMonster_StateType::COUNT);
	CreateState<BattlePlayerMonster_CreateState>(BattlePlayerMonster_StateType::Create);
	CreateState<BattleStateIdle>(BattlePlayerMonster_StateType::Idle);

	ChangeState(BattlePlayerMonster_StateType::Create);
}
