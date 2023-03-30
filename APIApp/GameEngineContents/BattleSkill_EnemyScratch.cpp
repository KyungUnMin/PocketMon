#include "BattleSkill_EnemyScratch.h"

BattleSkill_EnemyScratch::BattleSkill_EnemyScratch() 
{
}

BattleSkill_EnemyScratch::~BattleSkill_EnemyScratch() 
{
}

void BattleSkill_EnemyScratch::EnterState()
{
	BattleSkill_EnemyBase::EnterState();
}

void BattleSkill_EnemyScratch::Update(float _DeltaTime)
{
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;
}

void BattleSkill_EnemyScratch::ExitState()
{
	BattleSkill_EnemyBase::ExitState();
}
