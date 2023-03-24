#pragma once


class BattleFSM_StateBase
{
public:
	friend class BattleFSMBase;


	BattleFSM_StateBase();
	~BattleFSM_StateBase();

	BattleFSM_StateBase(const BattleFSM_StateBase& _Other) = delete;
	BattleFSM_StateBase(BattleFSM_StateBase&& _Other) noexcept = delete;
	BattleFSM_StateBase& operator=(const BattleFSM_StateBase& _Other) = delete;
	BattleFSM_StateBase& operator=(const BattleFSM_StateBase&& _Other) noexcept = delete;

protected:

private:

};

