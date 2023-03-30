#pragma once

// Ό³Έν :
class BattleSkill_PlayerScratch
{
public:
	// constrcuter destructer
	BattleSkill_PlayerScratch();
	~BattleSkill_PlayerScratch();

	// delete Function
	BattleSkill_PlayerScratch(const BattleSkill_PlayerScratch& _Other) = delete;
	BattleSkill_PlayerScratch(BattleSkill_PlayerScratch&& _Other) noexcept = delete;
	BattleSkill_PlayerScratch& operator=(const BattleSkill_PlayerScratch& _Other) = delete;
	BattleSkill_PlayerScratch& operator=(BattleSkill_PlayerScratch&& _Other) noexcept = delete;

protected:

private:

};

