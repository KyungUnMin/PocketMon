#pragma once
#include "BattleSkill_EnemyBase.h"
// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyEmber : public BattleSkill_EnemyBase
{
	friend class EmberEffect;
public:
	// constrcuter destructer
	BattleSkill_EnemyEmber();
	~BattleSkill_EnemyEmber();

	// delete Function
	BattleSkill_EnemyEmber(const BattleSkill_EnemyEmber& _Other) = delete;
	BattleSkill_EnemyEmber(BattleSkill_EnemyEmber&& _Other) noexcept = delete;
	BattleSkill_EnemyEmber& operator=(const BattleSkill_EnemyEmber& _Other) = delete;
	BattleSkill_EnemyEmber& operator=(BattleSkill_EnemyEmber&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 1.1f;
	const float EmberSpeed = 1.5f;
	const float4 StartPos = { 372, -182 };
	const float4 EndPos = { 48, 12};

	GameEngineRender* EffectRender = nullptr;
	GameEngineRender* PlayerMonster = nullptr;


	enum class SkillState
	{
		Shoot,
		BackWard,
		Flashing
	};
	float ShootTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;
	SkillState CurState = SkillState::Shoot;
	void Update_Shoot(float _DeltaTime);
	void Update_BackWard(float _DeltaTime);
	void Update_Flashing(float _DeltaTime);

};

