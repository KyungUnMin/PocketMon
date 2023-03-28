#pragma once
#include "BattleFSMBase.h"

enum class BattlePlayer_StateType
{
	Move,
	Idle,
	Throw,

	COUNT,
};

class BattlePlayerFSM : public BattleFSMBase
{
public:
	BattlePlayerFSM(class GameEngineActor* _Owner);
	~BattlePlayerFSM() override;

	BattlePlayerFSM(const BattlePlayerFSM& _Other) = delete;
	BattlePlayerFSM(BattlePlayerFSM&& _Other) noexcept = delete;
	BattlePlayerFSM& operator=(const BattlePlayerFSM& _Other) = delete;
	BattlePlayerFSM& operator=(const BattlePlayerFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType);

protected:

private:
};

