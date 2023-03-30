#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;

class BattleSkill_PlayerGrowl : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerGrowl();
	~BattleSkill_PlayerGrowl();

	// delete Function
	BattleSkill_PlayerGrowl(const BattleSkill_PlayerGrowl& _Other) = delete;
	BattleSkill_PlayerGrowl(BattleSkill_PlayerGrowl&& _Other) noexcept = delete;
	BattleSkill_PlayerGrowl& operator=(const BattleSkill_PlayerGrowl& _Other) = delete;
	BattleSkill_PlayerGrowl& operator=(BattleSkill_PlayerGrowl&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EffectRender = nullptr;

	void dllddl();

};

