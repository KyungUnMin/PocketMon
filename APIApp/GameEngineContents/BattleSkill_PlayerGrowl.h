#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Growl;

class BattleSkill_PlayerGrowl : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerGrowl();
	~BattleSkill_PlayerGrowl();

	// delete Function
	BattleSkill_PlayerGrowl(const BattleSkill_PlayerGrowl& _Other) = delete;
	BattleSkill_PlayerGrowl(BattleSkill_PlayerGrowl&& _Other) noexcept = delete;
	BattleSkill_PlayerGrowl& operator=(const BattleSkill_PlayerGrowl& _Other) = delete;
	BattleSkill_PlayerGrowl& operator=(BattleSkill_PlayerGrowl&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_Growl* GrowlRender1 = nullptr;
	SkillActor_Growl* GrowlRender2 = nullptr;
	SkillActor_Growl* GrowlRender3 = nullptr;

	float4 Growl1StartPos = float4::Zero;
	float4 Growl1EndPos = float4::Zero;

	float4 Growl2StartPos = float4::Zero;
	float4 Growl2EndPos = float4::Zero;

	float4 Growl3StartPos = float4::Zero;
	float4 Growl3EndPos = float4::Zero;

	const float ForwardDuration = 0.1f;

	enum class MoveState
	{
		Forward,
		Backward
	};

	MoveState CurState = MoveState::Forward;

	float GrowlTime = 0.f;
	float ForwardTime = 0.f;
	float BackwardTime = 0.f;

	bool ReStart = true;
	int ReCount = 1;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);

};

