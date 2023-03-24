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
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("DownMove") || GameEngineInput::IsPress("UpMove"))
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
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		if (true == Fieldmap::Walkable(NextXplusIndex))
		{
			EndPos = StartPos + (MoveRange - NextPos2);
		}
	}
	else if(true == GameEngineInput::IsPress("UpMove"))
	{
		if (true == Fieldmap::Walkable(NextYMinusIndex))
		{
			EndPos = StartPos + (MoveRange - NextPos3);
		}
	}
	else if(true == GameEngineInput::IsPress("DownMove"))
	{
		if (true == Fieldmap::Walkable(NextYplusIndex))
		{
			EndPos = StartPos + (MoveRange - NextPos4);
		}
	}
	Fieldmap::GetGroundType(NextYplusIndex);
	
}
void Player::MoveUpdate(float _Time)
{
	PlayerTime+=_Time;
	
	float4 POS = float4::LerpClamp(StartPos, EndPos, PlayerTime*5);
	//float4 POS = float4::BezierClamp(StartPos, EndPos, PlayerTime * 5);
	 SetPos(POS); 
	/*if (POS.x < EndPos.x)
	{
		PlayerMoveBool = false;
	}*/
	
	
	 if (PlayerTime > 0.2f)//다음타일까지의 이동시간
	 {
		 PlayerTime = 0.0f;
		 ChangeState(PlayerState::IDLE);
	 }
	 
}

void Player::MoveEnd()
{
	
	//PlayerTime = 0.0f;
}
