#include "BattlePlayerMonsterFSM.h"
#include "BattlePlayerMonster_CreateState.h"
#include "BattleStateIdle.h"
#include "BattleSkill_PlayerTackle.h"

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
	CreateState<BattleSkill_PlayerTackle>(BattlePlayerMonster_StateType::Skill_Tackle);

	ChangeState(BattlePlayerMonster_StateType::Create);
}
