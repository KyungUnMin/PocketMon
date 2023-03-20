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
	}
}
void Player::IdleEnd() {

}

void Player::MoveStart()
{
	DirCheck("Move");
}
void Player::MoveUpdate(float _Time)
{
	DirCheck("Move");
	if (
		false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("DownMove") &&
		false == GameEngineInput::IsPress("UpMove")
		)
	{
		ChangeState(PlayerState::IDLE);

		return;
	}

	int2 IndexValue = Fieldmap::GetIndex(GetPos());
	int2 NextIndex = int2(IndexValue.x+1 , IndexValue.y);

	float4 MoveRange = Fieldmap::GetPos(IndexValue);
	float4 NextPos = Fieldmap::GetPos(NextIndex);

	//??
	float SaveYvalue = MoveRange.y;
	if (true == GameEngineInput::IsPress("LeftMove")) 
	{
		MoveRange = float4::Left;
	}


	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveRange = float4::Right;
	}

	else if (true == GameEngineInput::IsPress("UpMove"))
	{
		MoveRange = float4::Up;
	}
	else if (true == GameEngineInput::IsPress("DownMove"))
	{
		MoveRange = float4::Down;
	}

	
	MoveDir = MoveRange;


}
void Player::MoveEnd()
{

}
