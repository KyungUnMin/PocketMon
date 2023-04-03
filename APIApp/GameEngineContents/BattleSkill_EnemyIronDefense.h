#pragma once
#include "BattleSkill_EnemyBase.h"

// Ό³Έν :
class SkillActor_BlackBox;
class GameEngineRender;
class BattleSkill_EnemyIronDefense : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyIronDefense();
	~BattleSkill_EnemyIronDefense();

	// delete Function
	BattleSkill_EnemyIronDefense(const BattleSkill_EnemyIronDefense& _Other) = delete;
	BattleSkill_EnemyIronDefense(BattleSkill_EnemyIronDefense&& _Other) noexcept = delete;
	BattleSkill_EnemyIronDefense& operator=(const BattleSkill_EnemyIronDefense& _Other) = delete;
	BattleSkill_EnemyIronDefense& operator=(BattleSkill_EnemyIronDefense&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	float Timer = 0;
	const float Duration = 1.7f;
	GameEngineRender* EffectRender = nullptr;
	SkillActor_BlackBox* BBox = nullptr;
};

