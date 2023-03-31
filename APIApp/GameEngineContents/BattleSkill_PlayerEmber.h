#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerEmber : public BattleSkill_PlayerBase
{
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
	const float Duration = 1.0f;

	GameEngineRender* EnemyMonster = nullptr;
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

