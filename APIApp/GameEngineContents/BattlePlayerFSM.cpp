#include "BattlePlayerFSM.h"
#include "BattlePlayer_MoveState.h"
#include "BattleStateIdle.h"
#include"BattlePlayer_ThrowState.h"

BattlePlayerFSM::BattlePlayerFSM()
{

}

BattlePlayerFSM::~BattlePlayerFSM()
{

}

void BattlePlayerFSM::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	ResizeStates(BattlePlayer_StateType::COUNT);
	CreateState<BattlePlayer_MoveState>(BattlePlayer_StateType::Move);
	CreateState<BattleStateIdle>(BattlePlayer_StateType::Idle);
	CreateState<BattlePlayer_ThrowState>(BattlePlayer_StateType::Throw);

	ChangeState(BattlePlayer_StateType::Move);
}
