#pragma once

class BattleStateBase
{
public:
	BattleStateBase();
	virtual ~BattleStateBase() = 0;

	BattleStateBase(const BattleStateBase& _Other) = delete;
	BattleStateBase(BattleStateBase&& _Other) noexcept = delete;
	BattleStateBase& operator=(const BattleStateBase& _Other) = delete;
	BattleStateBase& operator=(const BattleStateBase&& _Other) noexcept = delete;

	virtual void EnterState(){}
	virtual void Update(float _DeltaTime){}
	virtual void ExitState(){}

protected:

private:

};

