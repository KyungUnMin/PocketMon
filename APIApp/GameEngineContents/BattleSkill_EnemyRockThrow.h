#pragma once
#include "BattleSkill_EnemyBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyRockThrow : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyRockThrow();
	~BattleSkill_EnemyRockThrow();

	// delete Function
	BattleSkill_EnemyRockThrow(const BattleSkill_EnemyRockThrow& _Other) = delete;
	BattleSkill_EnemyRockThrow(BattleSkill_EnemyRockThrow&& _Other) noexcept = delete;
	BattleSkill_EnemyRockThrow& operator=(const BattleSkill_EnemyRockThrow& _Other) = delete;
	BattleSkill_EnemyRockThrow& operator=(BattleSkill_EnemyRockThrow&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 2.7f;

	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EffectRender = nullptr;

	float WaitTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	enum class SkillState
	{
		Wait,
		BackWard,
		Flashing
	};
	SkillState CurState = SkillState::Wait;

	void Update_Wait(float _DeltaTime);
	void Update_BackWard(float _DeltaTime);
	void Update_Flashing(float _DeltaTime);
};

