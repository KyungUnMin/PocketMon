#include "BattleSkill_PlayerTest.h"

BattleSkill_PlayerTest::BattleSkill_PlayerTest()
{

}

BattleSkill_PlayerTest::~BattleSkill_PlayerTest()
{

}


#include "BattleLevel.h"

void BattleSkill_PlayerTest::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	//�� ��ų�� ���۵ɶ� ������ ���� ������ּ���

	GameEngineLevel* Level = BattleLevel::BattleLevelPtr;
	//Level->CreateActor<>(UpdateOrder::Battle_Actors);
}




void BattleSkill_PlayerTest::Update(float _DeltaTime)
{
	float Duration = 10.f;
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	//Duration�ð� ���� ������ ������ ������ּ���

}

void BattleSkill_PlayerTest::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	//�� ��ų�� ������ �����ؾ� �� �۾����� ������ּ���
}

