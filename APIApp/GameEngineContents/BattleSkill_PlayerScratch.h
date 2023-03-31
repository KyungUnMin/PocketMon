#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerScratch : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerScratch();
	~BattleSkill_PlayerScratch();

	// delete Function
	BattleSkill_PlayerScratch(const BattleSkill_PlayerScratch& _Other) = delete;
	BattleSkill_PlayerScratch(BattleSkill_PlayerScratch&& _Other) noexcept = delete;
	BattleSkill_PlayerScratch& operator=(const BattleSkill_PlayerScratch& _Other) = delete;
	BattleSkill_PlayerScratch& operator=(BattleSkill_PlayerScratch&& _Other) noexcept = delete;

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

