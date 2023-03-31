#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
// 스킬액터 class SkillActor_Growl;

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

	// 스킬 액터
	// SkillActor_Growl* GrowlRender1 = nullptr;

	enum class MoveState
	{
		Forward,
		Backward
	};

	MoveState CurState = MoveState::Forward;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
};

