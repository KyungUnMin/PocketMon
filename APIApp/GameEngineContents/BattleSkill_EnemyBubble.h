#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;
class SkillActor_Bubble;

class BattleSkill_EnemyBubble : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyBubble();
	~BattleSkill_EnemyBubble();

	// delete Function
	BattleSkill_EnemyBubble(const BattleSkill_EnemyBubble& _Other) = delete;
	BattleSkill_EnemyBubble(BattleSkill_EnemyBubble&& _Other) noexcept = delete;
	BattleSkill_EnemyBubble& operator=(const BattleSkill_EnemyBubble& _Other) = delete;
	BattleSkill_EnemyBubble& operator=(BattleSkill_EnemyBubble&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_Bubble* BubbleRender1 = nullptr;
	SkillActor_Bubble* BubbleRender2 = nullptr;
	SkillActor_Bubble* BubbleRender3 = nullptr;

	float4 StartPos1 = float4::Zero;
	float4 StartPos2 = float4::Zero;
	float4 StartPos3 = float4::Zero;
	float4 EndPos1 = float4::Zero;
	float4 EndPos2 = float4::Zero;
	float4 EndPos3 = float4::Zero;

	float4 StartPos1_A = float4::Zero;
	float4 StartPos2_A = float4::Zero;
	float4 StartPos3_A = float4::Zero;
	float4 EndPos1_A = float4::Zero;
	float4 EndPos2_A = float4::Zero;
	float4 EndPos3_A = float4::Zero;

	int SetCount1 = 1;
	int SetCount2 = 1;
	int SetCount3 = 1;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	bool IsShoot1 = false;
	bool IsShoot2 = false;
	bool IsShoot3 = false;

	bool IsShoot1_A = false;
	bool IsShoot2_A = false;
	bool IsShoot3_A = false;

	float ShootTime1 = 0.0f;
	float ShootTime2 = 0.0f;
	float ShootTime3 = 0.0f;

	float ShootTime1_A = 0.0f;
	float ShootTime2_A = 0.0f;
	float ShootTime3_A = 0.0f;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};