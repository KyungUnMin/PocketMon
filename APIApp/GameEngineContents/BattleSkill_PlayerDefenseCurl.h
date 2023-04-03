#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class GameEngineRender;
class BattleSkill_PlayerDefenseCurl : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerDefenseCurl();
	~BattleSkill_PlayerDefenseCurl();

	// delete Function
	BattleSkill_PlayerDefenseCurl(const BattleSkill_PlayerDefenseCurl& _Other) = delete;
	BattleSkill_PlayerDefenseCurl(BattleSkill_PlayerDefenseCurl&& _Other) noexcept = delete;
	BattleSkill_PlayerDefenseCurl& operator=(const BattleSkill_PlayerDefenseCurl& _Other) = delete;
	BattleSkill_PlayerDefenseCurl& operator=(BattleSkill_PlayerDefenseCurl&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;
private:
	const float Duration = 1.5f;
	GameEngineRender* EffectRender = nullptr;
};

