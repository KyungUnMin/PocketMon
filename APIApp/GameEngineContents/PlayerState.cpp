#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>




#include "Player.h"
#include "Fieldmap.h"
#include "NPC1.h"


void Player::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PlayerState::IDLE:
		IdleStart();
		break;
	case PlayerState::MOVE:
		MoveStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case PlayerState::IDLE:
		IdleEnd();
		break;
	case PlayerState::MOVE:
		MoveEnd();
		break;
	default:
		break;
	}
}

void Player::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case PlayerState::IDLE:
		IdleUpdate(_Time);
		break;
	case PlayerState::MOVE:
			MoveUpdate(_Time);
		break;
	default:
		break;
	}
}


void Player::IdleStart()
{
	DirCheck("Idle");

}
void Player::IdleUpdate(float _Time)
{
	DirCheck("Idle");
	if (GameEngineInput::IsPress("LeftMove") ||
		GameEngineInput::IsPress("RightMove") ||
		GameEngineInput::IsPress("DownMove") ||
		GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}
}
void Player::IdleEnd() 
{

}

void Player::MoveStart()
{
	DirCheck("Move");

	Playerindex = Fieldmap::GetIndex(GetPos());
	float4 MoveRange = Fieldmap::GetPos(Playerindex);

	int2 NextXplusIndex = int2(Playerindex.x + 1, Playerindex.y);
	int2 NextXminusIndex = int2(Playerindex.x - 1, Playerindex.y);
	int2 NextYplusIndex = int2(Playerindex.x, Playerindex.y + 1);
	int2 NextYMinusIndex = int2(Playerindex.x, Playerindex.y - 1);

	NextPos1 = Fieldmap::GetPos(NextXplusIndex);
	NextPos2 = Fieldmap::GetPos(NextXminusIndex);
	NextPos3 = Fieldmap::GetPos(NextYplusIndex);
	NextPos4 = Fieldmap::GetPos(NextYMinusIndex);

	StartPos = GetPos();
	
	if (Fieldmap::Walkable(NextXminusIndex))
	{
		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			EndPos = StartPos + (MoveRange - NextPos1);
		}
	}
	if (Fieldmap::Walkable(NextXplusIndex))
	{
		if (true == GameEngineInput::IsPress("RightMove"))
		{
			EndPos = StartPos + (MoveRange - NextPos2);
		}
	}
	if (Fieldmap::Walkable(NextYMinusIndex))
	{
		if (true == GameEngineInput::IsPress("UpMove"))
		{
			EndPos = StartPos + (MoveRange - NextPos3);
		}
	}
	if (Fieldmap::Walkable(NextYplusIndex))
	{
		if (true == GameEngineInput::IsPress("DownMove"))
		{
			EndPos = StartPos + (MoveRange - NextPos4);
		}
	}
	
	
	Fieldmap::GetGroundType(NextYplusIndex);
	
}
void Player::MoveUpdate(float _Time)
{
	DirCheck("Move");
	PlayerTime+=_Time;
	
	float4 POS = float4::LerpClamp(StartPos, EndPos, PlayerTime*5);
	//float4 POS = float4::BezierClamp(StartPos, EndPos, PlayerTime * 5);
	SetPos(POS); 

	
	
	 if (PlayerTime > 0.2f)//����Ÿ�ϱ����� �̵��ð�
	 {
		 PlayerTime = 0.0f;
		 ChangeState(PlayerState::IDLE);
	 }
	 
}

void Player::MoveEnd()
{
	
	//PlayerTime = 0.0f;
}
