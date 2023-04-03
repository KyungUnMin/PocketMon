#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Bubble;

class BattleSkill_PlayerBubble : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerBubble();
	~BattleSkill_PlayerBubble();

	// delete Function
	BattleSkill_PlayerBubble(const BattleSkill_PlayerBubble& _Other) = delete;
	BattleSkill_PlayerBubble(BattleSkill_PlayerBubble&& _Other) noexcept = delete;
	BattleSkill_PlayerBubble& operator=(const BattleSkill_PlayerBubble& _Other) = delete;
	BattleSkill_PlayerBubble& operator=(BattleSkill_PlayerBubble&& _Other) noexcept = delete;

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

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	bool IsShoot1 = false;

	float ShootTime1 = 0.0f;
	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};