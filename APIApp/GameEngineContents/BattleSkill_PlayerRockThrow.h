#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerRockThrow : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerRockThrow();
	~BattleSkill_PlayerRockThrow();

	// delete Function
	BattleSkill_PlayerRockThrow(const BattleSkill_PlayerRockThrow& _Other) = delete;
	BattleSkill_PlayerRockThrow(BattleSkill_PlayerRockThrow&& _Other) noexcept = delete;
	BattleSkill_PlayerRockThrow& operator=(const BattleSkill_PlayerRockThrow& _Other) = delete;
	BattleSkill_PlayerRockThrow& operator=(BattleSkill_PlayerRockThrow&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 2.7f;

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

