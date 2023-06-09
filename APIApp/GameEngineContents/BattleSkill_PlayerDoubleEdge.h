#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
// ��ų ���� class SkillActor_Leer;

class BattleSkill_PlayerDoubleEdge : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerDoubleEdge();
	~BattleSkill_PlayerDoubleEdge();

	// delete Function
	BattleSkill_PlayerDoubleEdge(const BattleSkill_PlayerDoubleEdge& _Other) = delete;
	BattleSkill_PlayerDoubleEdge(BattleSkill_PlayerDoubleEdge&& _Other) noexcept = delete;
	BattleSkill_PlayerDoubleEdge& operator=(const BattleSkill_PlayerDoubleEdge& _Other) = delete;
	BattleSkill_PlayerDoubleEdge& operator=(BattleSkill_PlayerDoubleEdge&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	GameEngineRender* EffectRender1 = nullptr;
	GameEngineRender* EffectRender2 = nullptr;
	GameEngineRender* EffectRender3 = nullptr;

	const float4 MoveOffset = { 20.f, 0.f };
	
	float4 StartPos1 = float4::Zero;
	float4 EndPos1 = float4::Zero;
	float4 StartPos2 = float4::Zero;
	float4 EndPos2 = float4::Zero;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	float Pos1Time = 0.f;
	float Pos2Time = 0.f;
	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	bool IsMove = true;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);

	float4 EdgeClamp(const float4& Start, const float4& End, float Ratio);
	float4 EdgeLerp(const float4& Start, const float4& End, float Ratio);
};
