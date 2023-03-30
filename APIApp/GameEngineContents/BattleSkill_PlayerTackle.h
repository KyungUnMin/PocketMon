#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;

class BattleSkill_PlayerTackle : public BattleSkill_PlayerBase
{
public:
	BattleSkill_PlayerTackle();
	~BattleSkill_PlayerTackle() override;

	BattleSkill_PlayerTackle(const BattleSkill_PlayerTackle& _Other) = delete;
	BattleSkill_PlayerTackle(BattleSkill_PlayerTackle&& _Other) noexcept = delete;
	BattleSkill_PlayerTackle& operator=(const BattleSkill_PlayerTackle& _Other) = delete;
	BattleSkill_PlayerTackle& operator=(const BattleSkill_PlayerTackle&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	enum class MoveState
	{
		Forward,
		Backward
	};

	MoveState CurState = MoveState::Forward;

	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EffectRender = nullptr;

	const float4 MoveOffset = { 20.f, 0.f };
	float4 EffectScale = float4::Zero;

	float ForwardTimer = 0.f;
	float BackwardTimer = 0.f;
	const float ForwardDuration = 0.1f;
	const float BackwardDuration = 0.25f;

	
	const float SfxVolumn = 3.f;

	void Update_Forward(float _DeltaTime);
	void Update_BackWard(float _DeltaTime);
	
};

