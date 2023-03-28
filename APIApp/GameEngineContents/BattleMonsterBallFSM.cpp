#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall_ThrowToCreate.h"
#include "BattleMonsterBall.h"
#include "BattleMonsterBall_ThrowToCatch.h"
#include "BattleMonsterBall_OpenState.h"
#include "BattleMonsterBall_VerticalShake.h"
#include "BattleMonsterBall_HorizonShake.h"
#include "BattleMonsterBall_CatchState.h"
#include "BattleMonsterBall_FadeState.h"

BattleMonsterBallFSM::BattleMonsterBallFSM(GameEngineActor* _Owner)
	:BattleFSMBase(_Owner)
{

}

BattleMonsterBallFSM::~BattleMonsterBallFSM()
{

}


void BattleMonsterBallFSM::Init(BattleBallType _Type, BattleMonsterBall* _Ball)
{
	MonsterBall = _Ball;
	ResizeStates(BattleMonsterBall_Movement::COUNT);

	if (BattleBallType::Create_MonsterBall == _Type)
	{
		InitToCreate();
	}
	else
	{
		InitToCatch();
	}
}

void BattleMonsterBallFSM::InitToCreate()
{
	CreateState<BattleMonsterBall_ThrowToCreate>(BattleMonsterBall_Movement::Create);
	ChangeState(BattleMonsterBall_Movement::Create);
}

void BattleMonsterBallFSM::InitToCatch()
{
	CreateState<BattleMonsterBall_ThrowToCatch>(BattleMonsterBall_Movement::Create);
	CreateState<BattleMonsterBall_OpenState>(BattleMonsterBall_Movement::Opened);
	CreateState<BattleMonsterBall_VerticalShake>(BattleMonsterBall_Movement::ShakeVertical);
	CreateState<BattleMonsterBall_HorizonShake>(BattleMonsterBall_Movement::ShakeHorizon);
	CreateState<BattleMonsterBall_CatchState>(BattleMonsterBall_Movement::Catch);
	CreateState<BattleMonsterBall_FadeState>(BattleMonsterBall_Movement::Fade);

	ChangeState(BattleMonsterBall_Movement::Create);
}