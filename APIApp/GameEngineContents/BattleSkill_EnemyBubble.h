#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;

class BattleSkill_EnemyBubble : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyBubble();
	~BattleSkill_EnemyBubble();

	// delete Function
	BattleSkill_EnemyBubble(const BattleSkill_EnemyBubble& _Other) = delete;
	BattleSkill_EnemyBubble(BattleSkill_EnemyBubble&& _Other) noexcept = delete;
	BattleSkill_EnemyBubble& operator=(const BattleSkill_EnemyBubble& _Other) = delete;
	BattleSkill_EnemyBubble& operator=(BattleSkill_EnemyBubble&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:

};

