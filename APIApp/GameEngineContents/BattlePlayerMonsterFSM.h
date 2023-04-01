#pragma once
#include "BattleFSMBase.h"

enum class BattlePlayerMonster_StateType
{
	Test,

	Create,
	Idle,
	Dead,

	Skill_Tackle,
	Skill_Growl,
	Skill_Leer,
	Skill_TailWhip,
	Skill_Earthquake,

	Skill_WaterGun,
	Skill_Bubble,
	Skill_VineWhip,
	Skill_RazorLeaf,
	Skill_Thunder,
	Skill_Thunderbolt,
	Skill_DragonBreath,
	Skill_DoubleEdge,
	Skill_Bite,
	Skill_HyperFang,
	Skill_AirSlash,
	Skill_Gust,
	Skill_QuickAttack,

	Skill_Scratch,
	Skill_FeatherDance,
	Skill_Ember,

	COUNT
};

class BattlePlayerMonsterFSM : public BattleFSMBase
{
public:
	BattlePlayerMonsterFSM(class GameEngineActor* _Owner);
	~BattlePlayerMonsterFSM() override;

	BattlePlayerMonsterFSM(const BattlePlayerMonsterFSM& _Other) = delete;
	BattlePlayerMonsterFSM(BattlePlayerMonsterFSM&& _Other) noexcept = delete;
	BattlePlayerMonsterFSM& operator=(const BattlePlayerMonsterFSM& _Other) = delete;
	BattlePlayerMonsterFSM& operator=(const BattlePlayerMonsterFSM&& _Other) noexcept = delete;

	void Init();

protected:


private:

};

