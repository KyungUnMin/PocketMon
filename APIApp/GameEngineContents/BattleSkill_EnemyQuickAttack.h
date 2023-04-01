#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;

// Ό³Έν :
class BattleSkill_EnemyQuickAttack : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyQuickAttack();
	~BattleSkill_EnemyQuickAttack();

	// delete Function
	BattleSkill_EnemyQuickAttack(const BattleSkill_EnemyQuickAttack& _Other) = delete;
	BattleSkill_EnemyQuickAttack(BattleSkill_EnemyQuickAttack&& _Other) noexcept = delete;
	BattleSkill_EnemyQuickAttack& operator=(const BattleSkill_EnemyQuickAttack& _Other) = delete;
	BattleSkill_EnemyQuickAttack& operator=(BattleSkill_EnemyQuickAttack&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	GameEngineRender* EffectRender = nullptr;

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

	bool IsMove = true;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};

