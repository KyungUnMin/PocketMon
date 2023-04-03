#pragma once
#include "BattleSkill_EnemyBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_EnemyDefenseCurl : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyDefenseCurl();
	~BattleSkill_EnemyDefenseCurl();

	// delete Function
	BattleSkill_EnemyDefenseCurl(const BattleSkill_EnemyDefenseCurl& _Other) = delete;
	BattleSkill_EnemyDefenseCurl(BattleSkill_EnemyDefenseCurl&& _Other) noexcept = delete;
	BattleSkill_EnemyDefenseCurl& operator=(const BattleSkill_EnemyDefenseCurl& _Other) = delete;
	BattleSkill_EnemyDefenseCurl& operator=(BattleSkill_EnemyDefenseCurl&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 1.5f;
	GameEngineRender* EffectRender = nullptr;
};

