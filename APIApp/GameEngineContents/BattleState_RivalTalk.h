#pragma once
#include "BattleState_TalkBase.h"

class BattleState_RivalTalk : public BattleState_TalkBase
{
public:
	BattleState_RivalTalk();
	~BattleState_RivalTalk() override;

	BattleState_RivalTalk(const BattleState_RivalTalk& _Other) = delete;
	BattleState_RivalTalk(BattleState_RivalTalk&& _Other) noexcept = delete;
	BattleState_RivalTalk& operator=(const BattleState_RivalTalk& _Other) = delete;
	BattleState_RivalTalk& operator=(const BattleState_RivalTalk&& _Other) noexcept = delete;

protected:
	void EnterState() override;

private:

};

