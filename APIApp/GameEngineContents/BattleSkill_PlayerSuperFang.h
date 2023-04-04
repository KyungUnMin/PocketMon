#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerSuperFang : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerSuperFang();
	~BattleSkill_PlayerSuperFang();

	// delete Function
	BattleSkill_PlayerSuperFang(const BattleSkill_PlayerSuperFang& _Other) = delete;
	BattleSkill_PlayerSuperFang(BattleSkill_PlayerSuperFang&& _Other) noexcept = delete;
	BattleSkill_PlayerSuperFang& operator=(const BattleSkill_PlayerSuperFang& _Other) = delete;
	BattleSkill_PlayerSuperFang& operator=(BattleSkill_PlayerSuperFang&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 2.6f;

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

