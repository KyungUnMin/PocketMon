#pragma once
#include "BattleState_SkillBase.h"
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineCore/GameEngineResources.h>

class BattleMonsterEnemy;
class BattleMonsterPlayer;

class BattleSkill_PlayerBase : public BattleState_SkillBase
{
public:
	BattleSkill_PlayerBase();
	~BattleSkill_PlayerBase() override;

	BattleSkill_PlayerBase(const BattleSkill_PlayerBase& _Other) = delete;
	BattleSkill_PlayerBase(BattleSkill_PlayerBase&& _Other) noexcept = delete;
	BattleSkill_PlayerBase& operator=(const BattleSkill_PlayerBase& _Other) = delete;
	BattleSkill_PlayerBase& operator=(const BattleSkill_PlayerBase&& _Other) noexcept = delete;

protected:
	bool Update_CheckTime(float _DeltaTime, float _Duration) override;

private:
	
};

