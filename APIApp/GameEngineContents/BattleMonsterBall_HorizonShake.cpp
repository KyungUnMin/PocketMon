#include "BattleMonsterBall_HorizonShake.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBall.h"
#include "BattleMonsterBallFSM.h"
#include "BattleEnemy.h"

BattleMonsterBall_HorizonShake::BattleMonsterBall_HorizonShake()
{

}

BattleMonsterBall_HorizonShake::~BattleMonsterBall_HorizonShake()
{

}

void BattleMonsterBall_HorizonShake::EnterState()
{
	BattleMonsterBall* MonsterBall = dynamic_cast<BattleMonsterBallFSM*>(GetFSM())->GetMonsterBall();
	BallRender = MonsterBall->GetRender();
	BallRender->ChangeAnimation(BattleMonsterBall::RollAniName);

	if (BattleMonsterBall::MasterBallName == MonsterBall->GetName())
	{
		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Catch);
		return;
	}

	SelectNextState();
}

void BattleMonsterBall_HorizonShake::SelectNextState()
{
	PokeDataBase* EnemyMonDB = BattleEnemy::EnemyPtr->GetMonsterDB();
	int EnemyMonCurHP = EnemyMonDB->GetMonsterCurrentHP();
	float EnemyMonMaxHP = EnemyMonDB->GetMonsterMaxHP_float();

	float HpRatio = (static_cast<float>(EnemyMonCurHP) / EnemyMonMaxHP);
	float RandValue = GameEngineRandom::MainRandom.RandomFloat(0.f, 1.f);

	if (RandValue < HpRatio)
	{
		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Unlock);
	}
	else
	{
		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Catch);
	}

	//int RandValue = GameEngineRandom::MainRandom.RandomInt(1, 10);
	////HP�� 20 �̻��϶�
	//if (20 < EnemyMonHP)
	//{
	//	//NegativePer�� Ȯ���� ���͸� ��´�
	//	if (RandValue <= NegativePer)
	//	{
	//		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Catch);
	//	}
	//	else
	//	{
	//		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Unlock);
	//	}
	//}

	////HP�� 20�����϶�
	//else
	//{
	//	//PositivePer�� Ȯ���� ���͸� ��´�
	//	if (RandValue <= PositivePer)
	//	{
	//		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Catch);
	//	}
	//	else
	//	{
	//		NextState = static_cast<size_t>(BattleMonsterBall_Movement::Unlock);
	//	}
	//}
}





void BattleMonsterBall_HorizonShake::Update(float _DeltaTime)
{
	LiveTime += _DeltaTime;
	if (Duration < LiveTime)
	{
		GetFSM()->ChangeState(static_cast<BattleMonsterBall_Movement>(NextState));
		return;
	}

	int NowFrame = BallRender->GetFrame();
	switch (NowFrame)
	{
	case 0:
		BallRender->SetPosition(float4::Left * Range);
		break;
	case 1:
		BallRender->SetPosition(float4::Zero);
		break;
	case 2:
		BallRender->SetPosition(float4::Right * Range);
		break;
	default:
		MsgAssert("�������� ���� �������Դϴ�");
		break;
	}
	
}

void BattleMonsterBall_HorizonShake::ExitState()
{
	BallRender->SetPosition(float4::Zero);
	BallRender = nullptr;

	LiveTime = 0.f;
	NextState = -1;
}

