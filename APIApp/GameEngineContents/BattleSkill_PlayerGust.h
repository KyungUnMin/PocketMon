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

