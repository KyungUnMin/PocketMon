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

	//이 스킬이 시작될때 수행일 일을 만들어주세요

	GameEngineLevel* Level = BattleLevel::BattleLevelPtr;
	//Level->CreateActor<>(UpdateOrder::Battle_Actors);
}




void BattleSkill_PlayerTest::Update(float _DeltaTime)
{
	float Duration = 10.f;
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	//Duration시간 동안 동작할 연출을 만들어주세요

}

void BattleSkill_PlayerTest::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	//이 스킬이 끝날때 정리해야 할 작업들을 만들어주세요
}

