#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerFeatherDance : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerFeatherDance();
	~BattleSkill_PlayerFeatherDance();

	// delete Function
	BattleSkill_PlayerFeatherDance(const BattleSkill_PlayerFeatherDance& _Other) = delete;
	BattleSkill_PlayerFeatherDance(BattleSkill_PlayerFeatherDance&& _Other) noexcept = delete;
	BattleSkill_PlayerFeatherDance& operator=(const BattleSkill_PlayerFeatherDance& _Other) = delete;
	BattleSkill_PlayerFeatherDance& operator=(BattleSkill_PlayerFeatherDance&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 4.0f;

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

