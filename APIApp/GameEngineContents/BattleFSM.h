#pragma once
#include "BattleFSMBase.h"

enum class BattleStateType
{
	WildTalk,
	PlayerTurn,
	EnemyTurn,
	ThrowMonsterBall,
	CatchWildMonster,
	RivalTalk,

	COUNT,
};


class BattleFSM : public BattleFSMBase
{
public:
	BattleFSM();
	~BattleFSM() override;

	BattleFSM(const BattleFSM& _Other) = delete;
	BattleFSM(BattleFSM&& _Other) noexcept = delete;
	BattleFSM& operator=(const BattleFSM& _Other) = delete;
	BattleFSM& operator=(const BattleFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType) override;
	
protected:

private:
};

