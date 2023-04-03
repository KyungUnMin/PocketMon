#include "BattlePlayerMonsterFSM.h"
#include "BattlePlayerMonster_CreateState.h"
#include "BattleStateIdle.h"
#include "BattleSkill_PlayerTackle.h"
#include "BattleState_MonsterDead.h"

#include "BattleSkill_PlayerGrowl.h"
#include "BattleSkill_PlayerTest.h"
#include "BattleSkill_PlayerScratch.h"
#include "BattleSkill_PlayerLeer.h"
#include "BattleSkill_PlayerEarthquake.h"
#include "BattleSkill_PlayerTailWhip.h"
#include "BattleSkill_PlayerWaterGun.h"
#include "BattleSkill_PlayerBubble.h"
#include "BattleSkill_PlayerVineWhip.h"
#include "BattleSkill_PlayerRazorLeaf.h"
#include "BattleSkill_PlayerThunder.h"
#include "BattleSkill_PlayerThunderbolt.h"
#include "BattleSkill_PlayerDoubleEdge.h"
#include "BattleSkill_PlayerBite.h"
#include "BattleSkill_PlayerHyperFang.h"
#include "BattleSkill_PlayerAirSlash.h"
#include "BattleSkill_PlayerGust.h"
#include "BattleSkill_PlayerQuickAttack.h"

#include "BattleSkill_PlayerFeatherDance.h"
#include "BattleSkill_PlayerDefenseCurl.h"
#include "BattleSkill_PlayerIronDefense.h"
#include "BattleSkill_PlayerEmber.h"
#include "BattleSkill_PlayerFlamethrower.h"
#include "BattleSkill_PlayerDragonBreath.h"

BattlePlayerMonsterFSM::BattlePlayerMonsterFSM(GameEngineActor* _Owner)
	:BattleFSMBase(_Owner)
{

}

BattlePlayerMonsterFSM::~BattlePlayerMonsterFSM()
{

}

void BattlePlayerMonsterFSM::Init()
{
	ResizeStates(BattlePlayerMonster_StateType::COUNT);

	CreateState<BattleSkill_PlayerTest>(BattlePlayerMonster_StateType::Test);

	CreateState<BattleSkill_PlayerGrowl>(BattlePlayerMonster_StateType::Skill_Growl);
	CreateState<BattleSkill_PlayerLeer>(BattlePlayerMonster_StateType::Skill_Leer);
	CreateState<BattleSkill_PlayerTailWhip>(BattlePlayerMonster_StateType::Skill_TailWhip);
	CreateState<BattleSkill_PlayerEarthquake>(BattlePlayerMonster_StateType::Skill_Earthquake);

	CreateState<BattleSkill_PlayerWaterGun>(BattlePlayerMonster_StateType::Skill_WaterGun);
	CreateState<BattleSkill_PlayerBubble>(BattlePlayerMonster_StateType::Skill_Bubble);
	CreateState<BattleSkill_PlayerVineWhip>(BattlePlayerMonster_StateType::Skill_VineWhip);
	CreateState<BattleSkill_PlayerRazorLeaf>(BattlePlayerMonster_StateType::Skill_RazorLeaf);
	CreateState<BattleSkill_PlayerThunder>(BattlePlayerMonster_StateType::Skill_Thunder);
	CreateState<BattleSkill_PlayerThunderbolt>(BattlePlayerMonster_StateType::Skill_Thunderbolt);
	CreateState<BattleSkill_PlayerDoubleEdge>(BattlePlayerMonster_StateType::Skill_DoubleEdge);
	CreateState<BattleSkill_PlayerBite>(BattlePlayerMonster_StateType::Skill_Bite);
	CreateState<BattleSkill_PlayerHyperFang>(BattlePlayerMonster_StateType::Skill_HyperFang);
	CreateState<BattleSkill_PlayerAirSlash>(BattlePlayerMonster_StateType::Skill_AirSlash);
	CreateState<BattleSkill_PlayerGust>(BattlePlayerMonster_StateType::Skill_Gust);
	CreateState<BattleSkill_PlayerQuickAttack>(BattlePlayerMonster_StateType::Skill_QuickAttack);

	CreateState<BattlePlayerMonster_CreateState>(BattlePlayerMonster_StateType::Create);
	CreateState<BattleStateIdle>(BattlePlayerMonster_StateType::Idle);
	CreateState<BattleState_MonsterDead>(BattlePlayerMonster_StateType::Dead);

	CreateState<BattleSkill_PlayerTackle>(BattlePlayerMonster_StateType::Skill_Tackle);
	CreateState<BattleSkill_PlayerScratch>(BattlePlayerMonster_StateType::Skill_Scratch);
	CreateState<BattleSkill_PlayerFeatherDance>(BattlePlayerMonster_StateType::Skill_FeatherDance);
	CreateState<BattleSkill_PlayerDefenseCurl>(BattlePlayerMonster_StateType::Skill_DefenseCurl);
	CreateState<BattleSkill_PlayerIronDefense>(BattlePlayerMonster_StateType::Skill_IronDefense);
	CreateState<BattleSkill_PlayerEmber>(BattlePlayerMonster_StateType::Skill_Ember);
	CreateState<BattleSkill_PlayerFlamethrower>(BattlePlayerMonster_StateType::Skill_Flamethrower);
	CreateState<BattleSkill_PlayerDragonBreath>(BattlePlayerMonster_StateType::Skill_DragonBreath);

	ChangeState(BattlePlayerMonster_StateType::Create);
}
