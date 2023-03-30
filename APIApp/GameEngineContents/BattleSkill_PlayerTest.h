#pragma once
#include "BattleSkill_PlayerBase.h"

class BattleSkill_PlayerTest : public BattleSkill_PlayerBase
{
public:
	BattleSkill_PlayerTest();
	~BattleSkill_PlayerTest() override;

	BattleSkill_PlayerTest(const BattleSkill_PlayerTest& _Other) = delete;
	BattleSkill_PlayerTest(BattleSkill_PlayerTest&& _Other) noexcept = delete;
	BattleSkill_PlayerTest& operator=(const BattleSkill_PlayerTest& _Other) = delete;
	BattleSkill_PlayerTest& operator=(const BattleSkill_PlayerTest&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:

};




