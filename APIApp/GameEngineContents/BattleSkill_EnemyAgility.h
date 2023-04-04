#pragma once
#include "BattleSkill_EnemyBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyAgility : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyAgility();
	~BattleSkill_EnemyAgility();

	// delete Function
	BattleSkill_EnemyAgility(const BattleSkill_EnemyAgility& _Other) = delete;
	BattleSkill_EnemyAgility(BattleSkill_EnemyAgility&& _Other) noexcept = delete;
	BattleSkill_EnemyAgility& operator=(const BattleSkill_EnemyAgility& _Other) = delete;
	BattleSkill_EnemyAgility& operator=(BattleSkill_EnemyAgility&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 3.6f;

	GameEngineRender* EffectRender = nullptr;

	float WaitAppearTime = 0.f;
	float AppearTime = 0.f;
	float WaitDisappearTime = 0.f;
	float DisappearTime = 0.f;

	enum class SkillState
	{
		WaitAppear,
		Appear,
		Disappear,
		WaitDisappear
	};
	SkillState CurState = SkillState::WaitAppear;

	void Update_Appear(float _DeltaTime);
	void Update_WaitAppear(float _DeltaTime);
	void Update_Disappear(float _DeltaTime);
	void Update_WaitDisappear(float _DeltaTime);
};

