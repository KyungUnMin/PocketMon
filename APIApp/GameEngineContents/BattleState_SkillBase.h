#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class BattleMonsterEnemy;
class BattleMonsterPlayer;

class BattleState_SkillBase : public BattleStateBase
{
public:
	BattleState_SkillBase();
	~BattleState_SkillBase() override;

	BattleState_SkillBase(const BattleState_SkillBase& _Other) = delete;
	BattleState_SkillBase(BattleState_SkillBase&& _Other) noexcept = delete;
	BattleState_SkillBase& operator=(const BattleState_SkillBase& _Other) = delete;
	BattleState_SkillBase& operator=(const BattleState_SkillBase&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	virtual bool Update_CheckTime(float _DeltaTime, float _Duration) = 0;
	void ExitState() override;

	inline BattleMonsterEnemy* GetEnemyMonster()
	{
		CheckValid();
		return EnemyMonster;
	}

	inline BattleMonsterPlayer* GetPlayerMonster()
	{
		CheckValid();
		return PlayerMonster;
	}

	inline float GetLiveTime()
	{
		return LiveTime;
	}

	inline void AddLiveTime(float _DeltaTime)
	{
		LiveTime += _DeltaTime;
	}

private:
	float LiveTime = 0.f;

	BattleMonsterEnemy* EnemyMonster = nullptr;
	BattleMonsterPlayer* PlayerMonster = nullptr;

	bool CheckValid();
};

