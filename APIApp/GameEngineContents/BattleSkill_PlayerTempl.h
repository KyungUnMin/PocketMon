#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
// 스킬 전방 class SkillActor_Leer;

class BattleSkill_PlayerTempl : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerTempl();
	~BattleSkill_PlayerTempl();

	// delete Function
	BattleSkill_PlayerTempl(const BattleSkill_PlayerTempl& _Other) = delete;
	BattleSkill_PlayerTempl(BattleSkill_PlayerTempl&& _Other) noexcept = delete;
	BattleSkill_PlayerTempl& operator=(const BattleSkill_PlayerTempl& _Other) = delete;
	BattleSkill_PlayerTempl& operator=(BattleSkill_PlayerTempl&& _Other) noexcept = delete;

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