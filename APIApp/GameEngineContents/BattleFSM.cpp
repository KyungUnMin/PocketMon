#include "BattleFSM.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleLevel.h"
#include "BattleEnemy.h"
#include "BattleState_WildTalk.h"
#include "BattleState_PlayerTurn.h"
#include "BattleState_EnemyTurn.h"
#include "BattleState_ThrowMonsterBall.h"
#include "BattleState_CatchWhildMonster.h"
#include "BattleState_RivalTalk.h"
#include "BattleState_EnemyHPCheck.h"
#include "BattleState_PlayerHPCheck.h"
#include "BattleState_StageWin.h"
#include "BattleState_StageLose.h"

BattleFSM::BattleFSM(GameEngineActor* _Owner)
	:BattleFSMBase(_Owner)
{
	
}

BattleFSM::~BattleFSM()
{
	
}


void BattleFSM::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	ResizeStates(BattleStateType::COUNT);
	size_t Size = static_cast<size_t>(BattleStateType::COUNT);
	
	CreateState<BattleState_WildTalk>(BattleStateType::WildTalk);
	CreateState<BattleState_PlayerTurn>(BattleStateType::PlayerTurn);
	CreateState<BattleState_EnemyTurn>(BattleStateType::EnemyTurn);
	CreateState<BattleState_ThrowMonsterBall>(BattleStateType::ThrowMonsterBall);
	CreateState<BattleState_CatchWhildMonster>(BattleStateType::CatchWildMonster);
	CreateState<BattleState_RivalTalk>(BattleStateType::RivalTalk);
	CreateState<BattleState_PlayerHPCheck>(BattleStateType::CheckPlayerHP);
	CreateState<BattleState_EnemyHPCheck>(BattleStateType::CheckEnemyHP);
	CreateState<BattleState_StageWin>(BattleStateType::StageWin);
	CreateState<BattleState_StageLose>(BattleStateType::StageLose);


	switch (_NpcType)
	{
	case BattleNpcType::None:
		//BattleEnemy::EnemyPtr->CreateWildMonster(_FieldType);
		ChangeState(BattleStateType::WildTalk);
		break;
	case BattleNpcType::Rival:
		ChangeState(BattleStateType::RivalTalk);
		break;

	default:
		MsgAssert("배틀 FSM에서 아직 연결해주지 않은 전투상황입니다");
		break;
	}
}


