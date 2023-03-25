#pragma once
#include "BattleStateBase.h"

//FSM동작중에 아무것도 하지 않는 State, 외부에서 FSM State를 바꿔주어야 함
class BattleStateIdle : public BattleStateBase
{
public:
	BattleStateIdle();
	~BattleStateIdle();

	BattleStateIdle(const BattleStateIdle& _Other) = delete;
	BattleStateIdle(BattleStateIdle&& _Other) noexcept = delete;
	BattleStateIdle& operator=(const BattleStateIdle& _Other) = delete;
	BattleStateIdle& operator=(const BattleStateIdle&& _Other) noexcept = delete;

protected:

private:

};

