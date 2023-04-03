#pragma once
#include "BattleSkill_PlayerBase.h"

// Ό³Έν :
class SkillActor_BlackBox;
class GameEngineRender;
class BattleSkill_PlayerIronDefense : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerIronDefense();
	~BattleSkill_PlayerIronDefense();

	// delete Function
	BattleSkill_PlayerIronDefense(const BattleSkill_PlayerIronDefense& _Other) = delete;
	BattleSkill_PlayerIronDefense(BattleSkill_PlayerIronDefense&& _Other) noexcept = delete;
	BattleSkill_PlayerIronDefense& operator=(const BattleSkill_PlayerIronDefense& _Other) = delete;
	BattleSkill_PlayerIronDefense& operator=(BattleSkill_PlayerIronDefense&& _Other) noexcept = delete;

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

