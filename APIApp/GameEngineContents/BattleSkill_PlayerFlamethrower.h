#pragma once
#include "BattleSkill_PlayerBase.h"
// Ό³Έν :
class GameEngineRender;
class SkillActor_Ember;
class BattleSkill_PlayerFlamethrower : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerFlamethrower();
	~BattleSkill_PlayerFlamethrower();

	// delete Function
	BattleSkill_PlayerFlamethrower(const BattleSkill_PlayerFlamethrower& _Other) = delete;
	BattleSkill_PlayerFlamethrower(BattleSkill_PlayerFlamethrower&& _Other) noexcept = delete;
	BattleSkill_PlayerFlamethrower& operator=(const BattleSkill_PlayerFlamethrower& _Other) = delete;
	BattleSkill_PlayerFlamethrower& operator=(BattleSkill_PlayerFlamethrower&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 2.5f;
	const float4 StartPos = { -332, 212 };
	const float4 EndPos = { 0, 32 };

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

