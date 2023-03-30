#pragma once

// Ό³Έν :
class BattleSkill_EnemyScratch
{
public:
	// constrcuter destructer
	BattleSkill_EnemyScratch();
	~BattleSkill_EnemyScratch();

	// delete Function
	BattleSkill_EnemyScratch(const BattleSkill_EnemyScratch& _Other) = delete;
	BattleSkill_EnemyScratch(BattleSkill_EnemyScratch&& _Other) noexcept = delete;
	BattleSkill_EnemyScratch& operator=(const BattleSkill_EnemyScratch& _Other) = delete;
	BattleSkill_EnemyScratch& operator=(BattleSkill_EnemyScratch&& _Other) noexcept = delete;

protected:

private:

};

