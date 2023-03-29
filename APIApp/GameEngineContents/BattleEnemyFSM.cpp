#include "BattleEnemyFSM.h"
#include "BattleEnemy_MoveState.h"
#include "BattleStateIdle.h"
#include "BattleLevel.h"
#include "BattleEnemy.h"
#include "BattleEnemy_CreateMonster.h"

BattleEnemyFSM::BattleEnemyFSM(GameEngineActor* _Owner)
	:BattleFSMBase( _Owner)
{

}

BattleEnemyFSM::~BattleEnemyFSM()
{

}

void BattleEnemyFSM::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	ResizeStates(BattleEnemy_StateType::COUNT);
	CreateState<BattleEnemy_MoveState>(BattleEnemy_StateType::Move);
	CreateState<BattleStateIdle>(BattleEnemy_StateType::Idle);
	CreateState<BattleEnemy_CreateMonster>(BattleEnemy_StateType::CreateMonster);

	
	if (BattleNpcType::None == _NpcType)
	{
		BattleEnemy::EnemyPtr->CreateWildMonster(_FieldType);
	}
	
	//TODO
	ChangeState(BattleEnemy_StateType::Move);
}
