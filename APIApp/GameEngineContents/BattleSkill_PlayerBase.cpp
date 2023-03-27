#include "BattleSkill_PlayerBase.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BattlePlayerMonsterFSM.h"


BattleSkill_PlayerBase::BattleSkill_PlayerBase()
{

}

BattleSkill_PlayerBase::~BattleSkill_PlayerBase()
{

}

bool BattleSkill_PlayerBase::Update_CheckTime(float _DeltaTime, float _Duration)
{
	AddLiveTime(_DeltaTime);
	float LiveTime = GetLiveTime();
	if (LiveTime < _Duration)
		return false;

	BattleFSM* GameFsm = BattleLevel::BattleLevelPtr->GetBattleFSM();
	GameFsm->ChangeState(BattleStateType::EnemyTurn);

	GetFSM()->ChangeState(BattlePlayerMonster_StateType::Idle);

	return true;
}
