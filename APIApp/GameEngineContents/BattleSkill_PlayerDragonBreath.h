#pragma once
#include "BattleSkill_PlayerBase.h"
// ���� :
class GameEngineRender;
class SkillActor_Ember;
class BattleSkill_PlayerDragonBreath : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerDragonBreath();
	~BattleSkill_PlayerDragonBreath();

	// delete Function
	BattleSkill_PlayerDragonBreath(const BattleSkill_PlayerDragonBreath& _Other) = delete;
	BattleSkill_PlayerDragonBreath(BattleSkill_PlayerDragonBreath&& _Other) noexcept = delete;
	BattleSkill_PlayerDragonBreath& operator=(const BattleSkill_PlayerDragonBreath& _Other) = delete;
	BattleSkill_PlayerDragonBreath& operator=(BattleSkill_PlayerDragonBreath&& _Other) noexcept = delete;

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

