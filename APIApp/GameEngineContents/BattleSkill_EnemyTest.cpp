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

	//�� ��ų�� ���۵ɶ� ������ ���� ������ּ���
}

void BattleSkill_EnemyTest::Update(float _DeltaTime)
{
	float Duration = 10.f;
	if (true == BattleSkill_EnemyBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	//Duration�ð� ���� ������ ������ ������ּ���
}

void BattleSkill_EnemyTest::ExitState()
{
	BattleSkill_EnemyBase::ExitState();

	//�� ��ų�� ������ �����ؾ� �� �۾����� ������ּ���
}
