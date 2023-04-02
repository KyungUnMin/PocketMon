#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_RazorLeaf;

class BattleSkill_PlayerRazorLeaf : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerRazorLeaf();
	~BattleSkill_PlayerRazorLeaf();

	// delete Function
	BattleSkill_PlayerRazorLeaf(const BattleSkill_PlayerRazorLeaf& _Other) = delete;
	BattleSkill_PlayerRazorLeaf(BattleSkill_PlayerRazorLeaf&& _Other) noexcept = delete;
	BattleSkill_PlayerRazorLeaf& operator=(const BattleSkill_PlayerRazorLeaf& _Other) = delete;
	BattleSkill_PlayerRazorLeaf& operator=(BattleSkill_PlayerRazorLeaf&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;
		
	SkillActor_RazorLeaf* LeafRender1 = nullptr;
	SkillActor_RazorLeaf* LeafRender2 = nullptr;
	SkillActor_RazorLeaf* LeafRender3 = nullptr;
	SkillActor_RazorLeaf* LeafRender4 = nullptr;
	SkillActor_RazorLeaf* LeafRender5 = nullptr;

	SkillActor_RazorLeaf* RazorRender1 = nullptr;
	SkillActor_RazorLeaf* RazorRender2 = nullptr;

	float4 StartPos1 = float4::Zero;
	float4 StartPos2 = float4::Zero;
	float4 EndPos1 = float4::Zero;
	float4 EndPos2 = float4::Zero;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	bool IsShoot1 = false;
	bool IsShoot2 = false;

	float ShootTime1 = 0.0f;
	float ShootTime2 = 0.0f;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};