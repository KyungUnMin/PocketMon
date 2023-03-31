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
	Skill_Scratch,
	Skill_FeatherDance,

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

