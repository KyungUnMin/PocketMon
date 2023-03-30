#include "BattleSkill_EnemyTest.h"

BattleSkill_EnemyTest::BattleSkill_EnemyTest()
{

}

BattleSkill_EnemyTest::~BattleSkill_EnemyTest()
{

}

void BattleSkill_EnemyTest::EnterState()
{
	BattleSkill_EnemyBase::EnterState();

	//이 스킬이 시작될때 수행일 일을 만들어주세요
}

void BattleSkill_EnemyTest::Update(float _DeltaTime)
{
	float Duration = 10.f;
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	//Duration시간 동안 동작할 연출을 만들어주세요
}

void BattleSkill_EnemyTest::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	//이 스킬이 끝날때 정리해야 할 작업들을 만들어주세요
}
