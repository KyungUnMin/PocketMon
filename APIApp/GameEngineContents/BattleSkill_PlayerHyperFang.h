#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Bite;

class BattleSkill_PlayerHyperFang : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerHyperFang();
	~BattleSkill_PlayerHyperFang();

	// delete Function
	BattleSkill_PlayerHyperFang(const BattleSkill_PlayerHyperFang& _Other) = delete;
	BattleSkill_PlayerHyperFang(BattleSkill_PlayerHyperFang&& _Other) noexcept = delete;
	BattleSkill_PlayerHyperFang& operator=(const BattleSkill_PlayerHyperFang& _Other) = delete;
	BattleSkill_PlayerHyperFang& operator=(BattleSkill_PlayerHyperFang&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;
	
	SkillActor_Bite* BiteRender = nullptr;

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
