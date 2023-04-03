#pragma once
#include "BattleSkill_EnemyBase.h"
// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyDragonBrath : public BattleSkill_EnemyBase
{
	friend class DragonBrathEffect;
public:
	// constrcuter destructer
	BattleSkill_EnemyDragonBrath();
	~BattleSkill_EnemyDragonBrath();

	// delete Function
	BattleSkill_EnemyDragonBrath(const BattleSkill_EnemyDragonBrath& _Other) = delete;
	BattleSkill_EnemyDragonBrath(BattleSkill_EnemyDragonBrath&& _Other) noexcept = delete;
	BattleSkill_EnemyDragonBrath& operator=(const BattleSkill_EnemyDragonBrath& _Other) = delete;
	BattleSkill_EnemyDragonBrath& operator=(BattleSkill_EnemyDragonBrath&& _Other) noexcept = delete;

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

