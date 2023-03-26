#include "BattleMonsterBallFSM.h"
#include "BattleMonsterBall_ThrowToCreate.h"
#include "BattleMonsterBall.h"

BattleMonsterBallFSM::BattleMonsterBallFSM()
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
	//TODO
}
