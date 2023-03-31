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

#include "BattleSkill_PlayerFeatherDance.h"
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

	CreateState<BattlePlayerMonster_CreateState>(BattlePlayerMonster_StateType::Create);
	CreateState<BattleStateIdle>(BattlePlayerMonster_StateType::Idle);
	CreateState<BattleState_MonsterDead>(BattlePlayerMonster_StateType::Dead);

	CreateState<BattleSkill_PlayerTackle>(BattlePlayerMonster_StateType::Skill_Tackle);
	CreateState<BattleSkill_PlayerScratch>(BattlePlayerMonster_StateType::Skill_Scratch);
	CreateState<BattleSkill_PlayerFeatherDance>(BattlePlayerMonster_StateType::Skill_FeatherDance);

	ChangeState(BattlePlayerMonster_StateType::Create);
}
