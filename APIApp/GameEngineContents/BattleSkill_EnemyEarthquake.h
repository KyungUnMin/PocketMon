#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;
class SkillActor_BlackBox;

class BattleSkill_EnemyEarthquake : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyEarthquake();
	~BattleSkill_EnemyEarthquake();

	// delete Function
	BattleSkill_EnemyEarthquake(const BattleSkill_EnemyEarthquake& _Other) = delete;
	BattleSkill_EnemyEarthquake(BattleSkill_EnemyEarthquake&& _Other) noexcept = delete;
	BattleSkill_EnemyEarthquake& operator=(const BattleSkill_EnemyEarthquake& _Other) = delete;
	BattleSkill_EnemyEarthquake& operator=(BattleSkill_EnemyEarthquake&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_BlackBox* BBox = nullptr;

	float4 InitCameraPos = float4::Zero;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};