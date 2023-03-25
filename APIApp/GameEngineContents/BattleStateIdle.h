#pragma once
#include "BattleStateBase.h"

//FSM�����߿� �ƹ��͵� ���� �ʴ� State, �ܺο��� FSM State�� �ٲ��־�� ��
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

