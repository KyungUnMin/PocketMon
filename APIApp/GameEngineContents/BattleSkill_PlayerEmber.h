#pragma once
#include "BattleSkill_PlayerBase.h"
// Ό³Έν :
class GameEngineRender;
class SkillActor_Ember;
class BattleSkill_PlayerEmber : public BattleSkill_PlayerBase
{
	friend class EmberEffect;
public:
	// constrcuter destructer
	BattleSkill_PlayerEmber();
	~BattleSkill_PlayerEmber();

	// delete Function
	BattleSkill_PlayerEmber(const BattleSkill_PlayerEmber& _Other) = delete;
	BattleSkill_PlayerEmber(BattleSkill_PlayerEmber&& _Other) noexcept = delete;
	BattleSkill_PlayerEmber& operator=(const BattleSkill_PlayerEmber& _Other) = delete;
	BattleSkill_PlayerEmber& operator=(BattleSkill_PlayerEmber&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 1.1f;
	const float EmberSpeed = 1.5f;
	const float4 StartPos = { -332, 212 };
	const float4 EndPos = { 0, 32 };

	SkillActor_Ember* EmberActor = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

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

