#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Gust;

class BattleSkill_PlayerGust : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerGust();
	~BattleSkill_PlayerGust();

	// delete Function
	BattleSkill_PlayerGust(const BattleSkill_PlayerGust& _Other) = delete;
	BattleSkill_PlayerGust(BattleSkill_PlayerGust&& _Other) noexcept = delete;
	BattleSkill_PlayerGust& operator=(const BattleSkill_PlayerGust& _Other) = delete;
	BattleSkill_PlayerGust& operator=(BattleSkill_PlayerGust&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_Gust* GustRender = nullptr;

	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;
	float4 NewPos = float4::Zero;
	float4 PivotPoint = float4::Zero;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	float RotationTime = 0.0f;
	float GustTime = 0.f;
	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	float Angle = 0.0f;
	
	bool IsRotate = true;
	bool IsShoot = false;

	int ShootSet = 1;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};

