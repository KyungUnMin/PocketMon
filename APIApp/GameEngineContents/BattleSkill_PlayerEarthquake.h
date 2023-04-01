#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_BlackBox;

class BattleSkill_PlayerEarthquake : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerEarthquake();
	~BattleSkill_PlayerEarthquake();

	// delete Function
	BattleSkill_PlayerEarthquake(const BattleSkill_PlayerEarthquake& _Other) = delete;
	BattleSkill_PlayerEarthquake(BattleSkill_PlayerEarthquake&& _Other) noexcept = delete;
	BattleSkill_PlayerEarthquake& operator=(const BattleSkill_PlayerEarthquake& _Other) = delete;
	BattleSkill_PlayerEarthquake& operator=(BattleSkill_PlayerEarthquake&& _Other) noexcept = delete;

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

