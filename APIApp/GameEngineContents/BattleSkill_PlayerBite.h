#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Bite;

class BattleSkill_PlayerBite : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerBite();
	~BattleSkill_PlayerBite();

	// delete Function
	BattleSkill_PlayerBite(const BattleSkill_PlayerBite& _Other) = delete;
	BattleSkill_PlayerBite(BattleSkill_PlayerBite&& _Other) noexcept = delete;
	BattleSkill_PlayerBite& operator=(const BattleSkill_PlayerBite& _Other) = delete;
	BattleSkill_PlayerBite& operator=(BattleSkill_PlayerBite&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;
		
	SkillActor_Bite* BiteRender1 = nullptr;
	SkillActor_Bite* BiteRender2 = nullptr;

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
