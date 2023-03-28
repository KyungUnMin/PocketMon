#include "BattleSkill_EnemyBase.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BattleEnemyMonsterFSM.h"

BattleSkill_EnemyBase::BattleSkill_EnemyBase()
{

}

BattleSkill_EnemyBase::~BattleSkill_EnemyBase()
{

}

bool BattleSkill_EnemyBase::Update_CheckTime(float _DeltaTime, float _Duration)
{
	AddLiveTime(_DeltaTime);
	float LiveTime = GetLiveTime();
	if (LiveTime < _Duration)
		return false;

	BattleFSM* GameFsm = BattleLevel::BattleLevelPtr->GetBattleFSM();
	GameFsm->ChangeState(BattleStateType::CheckPlayerHP);

	GetFSM()->ChangeState(BattleEnemyMonster_StateType::Idle);

	return true;
}
