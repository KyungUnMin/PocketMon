#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerScratch : public BattleSkill_PlayerBase
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
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 1.0f;
	float Timer = 0;
	GameEngineRender* EnemyRender = nullptr;
	GameEngineRender* EffectRender = nullptr;

};

