#include "BattleEnemyMonsterFSM.h"
#include "BattleEnemyMonster_ShadowState.h"
#include "BattleStateIdle.h"
#include "BattleEnemyMonster_LockState.h"
#include "BattleSkill_EnemyTackle.h"
#include "BattleSkill_EnemyScratch.h"
#include "BattleState_MonsterDead.h"
#include "BattleEnemyMonster_CreatedInBall.h"

#include "BattleSkill_EnemyGrowl.h"

#include "BattleSkill_EnemyTest.h"


BattleEnemyMonsterFSM::BattleEnemyMonsterFSM(GameEngineActor* _Owner)
	:BattleFSMBase(_Owner)
{

}

BattleEnemyMonsterFSM::~BattleEnemyMonsterFSM()
{

}


void BattleEnemyMonsterFSM::Init(bool _IsWildMonster)
{
	ResizeStates(BattleEnemyMonster_StateType::COUNT);

	CreateState<BattleSkill_EnemyTest>(BattleEnemyMonster_StateType::Test);

	CreateState<BattleSkill_EnemyGrowl>(BattleEnemyMonster_StateType::Skill_Growl);

	CreateState<BattleEnemyMonster_ShadowState>(BattleEnemyMonster_StateType::Shadow);
	CreateState<BattleStateIdle>(BattleEnemyMonster_StateType::Idle);
	CreateState<BattleEnemyMonster_LockState>(BattleEnemyMonster_StateType::Lock);
	CreateState<BattleState_MonsterDead>(BattleEnemyMonster_StateType::Dead);
	CreateState<BattleEnemyMonster_CreatedInBall>(BattleEnemyMonster_StateType::CreatedInBall);

	CreateState<BattleSkill_EnemyTackle>(BattleEnemyMonster_StateType::Skill_Tackle);
	CreateState<BattleSkill_EnemyScratch>(BattleEnemyMonster_StateType::Skill_Scratch);

	if (true == _IsWildMonster)
	{
		ChangeState(BattleEnemyMonster_StateType::Shadow);
	}
	else
	{
		ChangeState(BattleEnemyMonster_StateType::CreatedInBall);
	}
}
