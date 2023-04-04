#include "BattleEnemyMonsterFSM.h"
#include "BattleEnemyMonster_ShadowState.h"
#include "BattleStateIdle.h"
#include "BattleEnemyMonster_LockState.h"
#include "BattleState_MonsterDead.h"
#include "BattleEnemyMonster_CreatedInBall.h"

#include "BattleSkill_EnemyTackle.h"
#include "BattleSkill_EnemyScratch.h"
#include "BattleSkill_EnemyFeatherDance.h"
#include "BattleSkill_EnemyDefenseCurl.h"
#include "BattleSkill_EnemyIronDefense.h"
#include "BattleSkill_EnemyEmber.h"
#include "BattleSkill_EnemyFlamethrower.h"
#include "BattleSkill_EnemyDragonBreath.h"
#include "BattleSkill_EnemyGrowl.h"
#include "BattleSkill_EnemyLeer.h"
#include "BattleSkill_EnemyTailWhip.h"
#include "BattleSkill_EnemyEarthquake.h"
#include "BattleSkill_EnemyGust.h"
#include "BattleSkill_EnemyQuickAttack.h"
#include "BattleSkill_EnemyThunderbolt.h"
#include "BattleSkill_EnemyThunder.h"
#include "BattleSkill_EnemyWaterGun.h"
#include "BattleSkill_EnemyBubble.h"
#include "BattleSkill_EnemyVinewhip.h"
#include "BattleSkill_EnemyRazorLeaf.h"
#include "BattleSkill_EnemyRockThrow.h"
#include "BattleSkill_EnemyAgility.h"
#include "BattleSkill_EnemySuperFang.h"
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
	CreateState<BattleSkill_EnemyLeer>(BattleEnemyMonster_StateType::Skill_Leer);
	CreateState<BattleSkill_EnemyTailWhip>(BattleEnemyMonster_StateType::Skill_TailWhip);
	CreateState<BattleSkill_EnemyEarthquake>(BattleEnemyMonster_StateType::Skill_Earthquake);
	CreateState<BattleSkill_EnemyGust>(BattleEnemyMonster_StateType::Skill_Gust);
	CreateState<BattleSkill_EnemyQuickAttack>(BattleEnemyMonster_StateType::Skill_QuickAttack);

	CreateState<BattleSkill_EnemyThunderbolt>(BattleEnemyMonster_StateType::Skill_Thunderbolt);
	CreateState<BattleSkill_EnemyThunder>(BattleEnemyMonster_StateType::Skill_Thunder);
	CreateState<BattleSkill_EnemyWaterGun>(BattleEnemyMonster_StateType::Skill_WaterGun);
	CreateState<BattleSkill_EnemyBubble>(BattleEnemyMonster_StateType::Skill_Bubble);
	CreateState<BattleSkill_EnemyVinewhip>(BattleEnemyMonster_StateType::Skill_VineWhip);
	CreateState<BattleSkill_EnemyRazorLeaf>(BattleEnemyMonster_StateType::Skill_RazorLeaf);

	CreateState<BattleEnemyMonster_ShadowState>(BattleEnemyMonster_StateType::Shadow);
	CreateState<BattleStateIdle>(BattleEnemyMonster_StateType::Idle);
	CreateState<BattleEnemyMonster_LockState>(BattleEnemyMonster_StateType::Lock);
	CreateState<BattleState_MonsterDead>(BattleEnemyMonster_StateType::Dead);
	CreateState<BattleEnemyMonster_CreatedInBall>(BattleEnemyMonster_StateType::CreatedInBall);

	CreateState<BattleSkill_EnemyTackle>(BattleEnemyMonster_StateType::Skill_Tackle);
	CreateState<BattleSkill_EnemyScratch>(BattleEnemyMonster_StateType::Skill_Scratch);
	CreateState<BattleSkill_EnemyFeatherDance>(BattleEnemyMonster_StateType::Skill_FeatherDance);
	CreateState<BattleSkill_EnemyAgility>(BattleEnemyMonster_StateType::Skill_Agility);
	CreateState<BattleSkill_EnemySuperFang>(BattleEnemyMonster_StateType::Skill_SuperFang);
	CreateState<BattleSkill_EnemyDefenseCurl>(BattleEnemyMonster_StateType::Skill_DefenseCurl);
	CreateState<BattleSkill_EnemyIronDefense>(BattleEnemyMonster_StateType::Skill_IronDefense);
	CreateState<BattleSkill_EnemyEmber>(BattleEnemyMonster_StateType::Skill_Ember);
	CreateState<BattleSkill_EnemyFlamethrower>(BattleEnemyMonster_StateType::Skill_Flamethrower);
	CreateState<BattleSkill_EnemyDragonBreath>(BattleEnemyMonster_StateType::Skill_DragonBreath);
	CreateState<BattleSkill_EnemyRockThrow>(BattleEnemyMonster_StateType::Skill_RockThrow);

	if (true == _IsWildMonster)
	{
		ChangeState(BattleEnemyMonster_StateType::Shadow);
	}
	else
	{
		ChangeState(BattleEnemyMonster_StateType::CreatedInBall);
	}
}
