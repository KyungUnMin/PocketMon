#pragma once

class BattleFSM;

class BattleStateBase
{
public:
	friend BattleFSM;

	BattleStateBase();
	virtual ~BattleStateBase() = 0;

	BattleStateBase(const BattleStateBase& _Other) = delete;
	BattleStateBase(BattleStateBase&& _Other) noexcept = delete;
	BattleStateBase& operator=(const BattleStateBase& _Other) = delete;
	BattleStateBase& operator=(const BattleStateBase&& _Other) noexcept = delete;

protected:
	inline BattleFSM* GetFSM()
	{
		return FsmPtr;
	}

	virtual void Start(){}
	virtual void EnterState() {}
	virtual void Update(float _DeltaTime) {}
	virtual void ExitState() {}


private:
	BattleFSM* FsmPtr = nullptr;
};

