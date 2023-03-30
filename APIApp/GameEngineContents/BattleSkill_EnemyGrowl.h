#pragma once
#include "BattleSkill_EnemyBase.h"
#include <GameEngineCore/GameEngineResources.h>

class GameEngineRender;
class SkillActor_Growl;

class BattleSkill_EnemyGrowl : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyGrowl();
	~BattleSkill_EnemyGrowl();

	// delete Function
	BattleSkill_EnemyGrowl(const BattleSkill_EnemyGrowl& _Other) = delete;
	BattleSkill_EnemyGrowl(BattleSkill_EnemyGrowl&& _Other) noexcept = delete;
	BattleSkill_EnemyGrowl& operator=(const BattleSkill_EnemyGrowl& _Other) = delete;
	BattleSkill_EnemyGrowl& operator=(BattleSkill_EnemyGrowl&& _Other) noexcept = delete;

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

