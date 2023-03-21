#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>




#include "Player.h"
#include "Fieldmap.h"


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
	if (false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("DownMove") &&
		false == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir = float4::Zero;
	}
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
void Player::IdleEnd() {

}

void Player::MoveStart()
{
	DirCheck("Move");

	int2 IndexValue = Fieldmap::GetIndex(GetPos());
	float4 MoveRange = Fieldmap::GetPos(IndexValue);

	int2 NextXplusIndex = int2(IndexValue.x + 1, IndexValue.y);
	int2 NextXminusIndex = int2(IndexValue.x - 1, IndexValue.y);
	int2 NextYplusIndex = int2(IndexValue.x, IndexValue.y + 1);
	int2 NextYMinusIndex = int2(IndexValue.x, IndexValue.y - 1);

	float4 NextPos1 = Fieldmap::GetPos(NextXplusIndex);
	float4 NextPos2 = Fieldmap::GetPos(NextXminusIndex);
	float4 NextPos3 = Fieldmap::GetPos(NextYplusIndex);
	float4 NextPos4 = Fieldmap::GetPos(NextYMinusIndex);

	StartPos = GetPos();

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		EndPos = StartPos + (MoveRange-NextPos1);
	}
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		EndPos = StartPos + (MoveRange-NextPos2);
	}

	else if (true == GameEngineInput::IsPress("UpMove"))
	{
		EndPos = StartPos + (MoveRange - NextPos3);
	}
	else if (true == GameEngineInput::IsPress("DownMove"))
	{
		EndPos = StartPos + (MoveRange - NextPos4);
	}
	
}
void Player::MoveUpdate(float _Time)
{
	DirCheck("Move");
	PlayerTime+=_Time;

	 float4 POS = float4::LerpClamp(StartPos, EndPos, PlayerTime*2);
	 SetPos(POS); 
	 if (PlayerTime > 0.5f)
	 {
		 ChangeState(PlayerState::IDLE);
	 }

}

void Player::MoveEnd()
{
	PlayerTime = 0.0f;

	
}
