#pragma once
#include "BattleFSMBase.h"

enum class BattlePlayerMonster_StateType
{
	Create,
	Idle,

	COUNT
};

class BattlePlayerMonsterFSM : public BattleFSMBase
{
public:
	BattlePlayerMonsterFSM();
	~BattlePlayerMonsterFSM() override;

	BattlePlayerMonsterFSM(const BattlePlayerMonsterFSM& _Other) = delete;
	BattlePlayerMonsterFSM(BattlePlayerMonsterFSM&& _Other) noexcept = delete;
	BattlePlayerMonsterFSM& operator=(const BattlePlayerMonsterFSM& _Other) = delete;
	BattlePlayerMonsterFSM& operator=(const BattlePlayerMonsterFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType) override{}
	void Init();

protected:


private:

};

