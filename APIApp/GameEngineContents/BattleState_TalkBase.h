#pragma once
#include "BattleStateBase.h"


class BattleState_TalkBase : public BattleStateBase
{
public:
	BattleState_TalkBase();
	virtual ~BattleState_TalkBase() = 0;

	BattleState_TalkBase(const BattleState_TalkBase& _Other) = delete;
	BattleState_TalkBase(BattleState_TalkBase&& _Other) noexcept = delete;
	BattleState_TalkBase& operator=(const BattleState_TalkBase& _Other) = delete;
	BattleState_TalkBase& operator=(const BattleState_TalkBase&& _Other) noexcept = delete;

	

	

protected:

private:
};



