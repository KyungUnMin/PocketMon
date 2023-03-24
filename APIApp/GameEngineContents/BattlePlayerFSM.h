#pragma once
#include <vector>

enum class BattlePlayer_StateType
{
	Move,
	Idle,
	Throw,
	//플레이어보다 플레이어의 몬스터가 FSM을 가지는게 맞는거 아냐?

	COUNT,
};

enum class BattleFieldType;
enum class BattleNpcType;
class BattlePlayer_StateBase;

class BattlePlayerFSM
{
public:
	BattlePlayerFSM();
	~BattlePlayerFSM();

	BattlePlayerFSM(const BattlePlayerFSM& _Other) = delete;
	BattlePlayerFSM(BattlePlayerFSM&& _Other) noexcept = delete;
	BattlePlayerFSM& operator=(const BattlePlayerFSM& _Other) = delete;
	BattlePlayerFSM& operator=(const BattlePlayerFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType);

protected:

private:

};

