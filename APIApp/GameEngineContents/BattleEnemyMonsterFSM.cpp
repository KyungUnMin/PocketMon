#include "BattleEnemyMonsterFSM.h"
#include "BattleEnemyMonster_ShadowState.h"
#include "BattleStateIdle.h"
#include "BattleEnemyMonster_LockState.h"
#include "BattleSkill_EnemyTackle.h"


BattleEnemyMonsterFSM::BattleEnemyMonsterFSM()
{

}

BattleEnemyMonsterFSM::~BattleEnemyMonsterFSM()
{

}


void BattleEnemyMonsterFSM::Init(bool _IsWildMonster)
{
	ResizeStates(BattleEnemyMonster_StateType::COUNT);
	CreateState<BattleEnemyMonster_ShadowState>(BattleEnemyMonster_StateType::Shadow);
	CreateState<BattleStateIdle>(BattleEnemyMonster_StateType::Idle);
	CreateState<BattleEnemyMonster_LockState>(BattleEnemyMonster_StateType::Lock);
	CreateState<BattleSkill_EnemyTackle>(BattleEnemyMonster_StateType::Skill_Tackle);

	if (true == _IsWildMonster)
	{
		ChangeState(BattleEnemyMonster_StateType::Shadow);
	}
	else
	{
		ChangeState(BattleEnemyMonster_StateType::Idle);
	}
}
