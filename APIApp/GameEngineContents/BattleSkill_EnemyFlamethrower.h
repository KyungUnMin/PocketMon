#pragma once
#include "BattleSkill_EnemyBase.h"
// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyFlamethrower : public BattleSkill_EnemyBase
{
	friend class FlamethrowerEffect;
public:
	// constrcuter destructer
	BattleSkill_EnemyFlamethrower();
	~BattleSkill_EnemyFlamethrower();

	// delete Function
	BattleSkill_EnemyFlamethrower(const BattleSkill_EnemyFlamethrower& _Other) = delete;
	BattleSkill_EnemyFlamethrower(BattleSkill_EnemyFlamethrower&& _Other) noexcept = delete;
	BattleSkill_EnemyFlamethrower& operator=(const BattleSkill_EnemyFlamethrower& _Other) = delete;
	BattleSkill_EnemyFlamethrower& operator=(BattleSkill_EnemyFlamethrower&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 2.5f;
	const float4 StartPos = { 372, -182 };
	const float4 EndPos = { 48, 12};

	GameEngineRender* PlayerMonster = nullptr;

	enum class SkillState
	{
		Wait,
		BackWard,
		Flashing
	};
	float WaitTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;
	SkillState CurState = SkillState::Wait;
	void Update_Wait(float _DeltaTime);
	void Update_BackWard(float _DeltaTime);
	void Update_Flashing(float _DeltaTime);

};

