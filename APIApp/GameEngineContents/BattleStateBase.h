#pragma once

class BattleFSMBase;

class BattleStateBase
{
public:
	friend BattleFSMBase;

	BattleStateBase();
	virtual ~BattleStateBase() = 0;

	BattleStateBase(const BattleStateBase& _Other) = delete;
	BattleStateBase(BattleStateBase&& _Other) noexcept = delete;
	BattleStateBase& operator=(const BattleStateBase& _Other) = delete;
	BattleStateBase& operator=(const BattleStateBase&& _Other) noexcept = delete;

protected:
	inline BattleFSMBase* GetFSM()
	{
		return FsmPtr;
	}

	virtual void EnterState() {}
	virtual void Update(float _DeltaTime) {}
	virtual void ExitState() {}


private:
	BattleFSMBase* FsmPtr = nullptr;
};

