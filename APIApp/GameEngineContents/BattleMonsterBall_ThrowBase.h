#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>
#include "PokeDataBase.h"

class BattleMonsterBallFSM;
class BattleMonsterBall;

class BattleMonsterBall_ThrowBase : public BattleStateBase
{
public:
	BattleMonsterBall_ThrowBase();
	virtual ~BattleMonsterBall_ThrowBase() = 0;

	BattleMonsterBall_ThrowBase(const BattleMonsterBall_ThrowBase& _Other) = delete;
	BattleMonsterBall_ThrowBase(BattleMonsterBall_ThrowBase&& _Other) noexcept = delete;
	BattleMonsterBall_ThrowBase& operator=(const BattleMonsterBall_ThrowBase& _Other) = delete;
	BattleMonsterBall_ThrowBase& operator=(const BattleMonsterBall_ThrowBase&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	virtual void ExitExcute() = 0;

	inline void SetGravity(float _StartGravity, float _GravityAcc)
	{
		StartGravity = _StartGravity;
		GravityAcc = _GravityAcc;
	}

	inline void SetDuration(float _Time)
	{
		Duration = _Time;
	}

	inline void SetMovePos(const float4& _StartPos, const float4& _DestPos)
	{
		StartPos = _StartPos;
		DestPos = _DestPos;
	}

	inline BattleMonsterBall* GetMonsterBall()
	{
		return MonsterBall;
	}

	inline float GetLiveTime()
	{
		return LiveTime;
	}

private:
	BattleMonsterBallFSM* FsmPtr = nullptr;
	BattleMonsterBall* MonsterBall = nullptr;
	float4 StartPos = float4::Zero;
	float4 DestPos = float4::Zero;

	float GravityAcc = 2000.f;
	float StartGravity = -100.f;
	float Duration = 0.5f;

	float NowGravity = 0.f;
	float LiveTime = 0.f;
};

