#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;

class BattleSkill_EnemyRazorLeaf : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyRazorLeaf();
	~BattleSkill_EnemyRazorLeaf();

	// delete Function
	BattleSkill_EnemyRazorLeaf(const BattleSkill_EnemyRazorLeaf& _Other) = delete;
	BattleSkill_EnemyRazorLeaf(BattleSkill_EnemyRazorLeaf&& _Other) noexcept = delete;
	BattleSkill_EnemyRazorLeaf& operator=(const BattleSkill_EnemyRazorLeaf& _Other) = delete;
	BattleSkill_EnemyRazorLeaf& operator=(BattleSkill_EnemyRazorLeaf&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:

};

