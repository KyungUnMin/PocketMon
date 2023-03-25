#pragma once
#include "BattleFSMBase.h"

enum class BattleEnemy_StateType
{
	Move,
	Idle,

	COUNT
};

class BattleEnemyFSM : public BattleFSMBase
{
public:
	BattleEnemyFSM();
	~BattleEnemyFSM() override;

	BattleEnemyFSM(const BattleEnemyFSM& _Other) = delete;
	BattleEnemyFSM(BattleEnemyFSM&& _Other) noexcept = delete;
	BattleEnemyFSM& operator=(const BattleEnemyFSM& _Other) = delete;
	BattleEnemyFSM& operator=(const BattleEnemyFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType) override;

protected:

private:
};

