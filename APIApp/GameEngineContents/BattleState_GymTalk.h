#pragma once
#include "BattleState_TalkBase.h"

class BattleState_GymTalk : public BattleState_TalkBase
{
public:
	BattleState_GymTalk();
	~BattleState_GymTalk() override;

	BattleState_GymTalk(const BattleState_GymTalk& _Other) = delete;
	BattleState_GymTalk(BattleState_GymTalk&& _Other) noexcept = delete;
	BattleState_GymTalk& operator=(const BattleState_GymTalk& _Other) = delete;
	BattleState_GymTalk& operator=(const BattleState_GymTalk&& _Other) noexcept = delete;

protected:
	void EnterState() override;

private:


};

