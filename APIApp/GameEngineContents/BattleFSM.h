#pragma once
#include "BattleFSMBase.h"
#include "PokeDataBase.h"

enum class BattleStateType
{
	WildTalk,
	RivalTalk,
	GymTalk,

	PlayerTurn,
	EnemyTurn,
	ThrowMonsterBall,
	CatchWildMonster,
	CheckPlayerHP,
	CheckEnemyHP,

	StageWin,
	StageLose,
	BattleWin,
	BattleLose,

	UseItem,

	COUNT,
};



class BattleFSM : public BattleFSMBase
{
public:
	BattleFSM(class GameEngineActor* _Owner);
	~BattleFSM() override;

	BattleFSM(const BattleFSM& _Other) = delete;
	BattleFSM(BattleFSM&& _Other) noexcept = delete;
	BattleFSM& operator=(const BattleFSM& _Other) = delete;
	BattleFSM& operator=(const BattleFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType) override;
	
protected:

private:

};

