#pragma once
#include "BattleSkill_EnemyBase.h"
// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyDragonBreath : public BattleSkill_EnemyBase
{
	friend class DragonBreathEffect;
public:
	// constrcuter destructer
	BattleSkill_EnemyDragonBreath();
	~BattleSkill_EnemyDragonBreath();

	// delete Function
	BattleSkill_EnemyDragonBreath(const BattleSkill_EnemyDragonBreath& _Other) = delete;
	BattleSkill_EnemyDragonBreath(BattleSkill_EnemyDragonBreath&& _Other) noexcept = delete;
	BattleSkill_EnemyDragonBreath& operator=(const BattleSkill_EnemyDragonBreath& _Other) = delete;
	BattleSkill_EnemyDragonBreath& operator=(BattleSkill_EnemyDragonBreath&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 2.5f;
	const float4 StartPos = { 372, -182 };
	const float4 EndPos = { 48, 12 };

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

