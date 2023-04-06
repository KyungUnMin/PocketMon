#include "BattleFSM.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleLevel.h"
#include "BattleEnemy.h"
#include "Player.h"
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
#include "BattleState_ItemUse.h"
#include "BattleState_BattleWin.h"
#include "BattleState_GymTalk.h"
#include "BattleState_ChangeMonster.h"
#include "BattleState_BattleLose.h"
#include "BattleState_NextStage.h"
#include "BattleState_GymBattleWin.h"
#include "BattleState_NpcTalk.h"
#include "BattleState_LeafTalk.h"
#include "BattleState_UnlockWildMonster.h"
#include "BattleState_InValidBattle.h"

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
	CreateState<BattleState_RivalTalk>(BattleStateType::RivalTalk);
	CreateState<BattleState_GymTalk>(BattleStateType::GymTalk);
	CreateState<BattleState_LeafTalk>(BattleStateType::LeafTalk);
	CreateState<BattleState_NpcTalk>(BattleStateType::NpcTalk);
	CreateState<BattleState_NextStage>(BattleStateType::NextStage);

	CreateState<BattleState_PlayerTurn>(BattleStateType::PlayerTurn);
	CreateState<BattleState_EnemyTurn>(BattleStateType::EnemyTurn);
	CreateState<BattleState_ThrowMonsterBall>(BattleStateType::ThrowMonsterBall);
	CreateState<BattleState_CatchWhildMonster>(BattleStateType::CatchWildMonster);
	CreateState<BattleState_UnlockWildMonster>(BattleStateType::CatchFailWildMonster);
	CreateState<BattleState_PlayerHPCheck>(BattleStateType::CheckPlayerHP);
	CreateState<BattleState_EnemyHPCheck>(BattleStateType::CheckEnemyHP);

	CreateState<BattleState_StageWin>(BattleStateType::StageWin);
	CreateState<BattleState_StageLose>(BattleStateType::StageLose);
	CreateState<BattleState_BattleWin>(BattleStateType::BattleWin);
	CreateState<BattleState_BattleLose>(BattleStateType::BattleLose);

	CreateState<BattleState_ItemUse>(BattleStateType::UseItem);
	CreateState<BattleState_ChangeMonster>(BattleStateType::PlayerMonsterChange);
	CreateState<BattleState_GymBattleWin>(BattleStateType::GymBattleWin);
	CreateState<BattleState_InValidBattle>(BattleStateType::InValidBattle);

	if (false == Player::MainPlayer->GetPlayerPokemon()->HasNextPokemon())
	{
		ChangeState(BattleStateType::InValidBattle);
		return;
	}


	switch (_NpcType)
	{
	case BattleNpcType::None:
		//BattleEnemy::EnemyPtr->CreateWildMonster(_FieldType);
		ChangeState(BattleStateType::WildTalk);
		break;
	case BattleNpcType::Rival:
		ChangeState(BattleStateType::RivalTalk);
		break;
	case BattleNpcType::Woong:
		ChangeState(BattleStateType::GymTalk);
		break;
	case BattleNpcType::Leaf:
		ChangeState(BattleStateType::LeafTalk);
		break;
	case BattleNpcType::NPC2:
	case BattleNpcType::NPC3:
		ChangeState(BattleStateType::NpcTalk);
		break;
	default:
		MsgAssert("배틀 FSM에서 아직 연결해주지 않은 전투상황입니다");
		break;
	}
}


