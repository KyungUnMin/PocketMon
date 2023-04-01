#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
// 스킬 전방 class SkillActor_Leer;

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
