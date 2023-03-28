#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "InputControll.h"

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
	case PlayerState::JUMP:
		JumpStart();
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
	case PlayerState::JUMP:
		JumpEnd();
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
	case PlayerState::JUMP:
		JumpUpdate(_Time);
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
	if (false == InputControll::CanControll())
	{
		return;
	}

	Playerindex = Fieldmap::GetIndex(GetPos());	
	Fieldmap::UpdateEventCheck(Playerindex);

	// 더블체크 예제 코드
	//if (false == InputControll::IsCurFrameUsedKey() && GameEngineInput::IsPress("LeftMove"))
	//{
	//	InputControll::UsedKey();
	//}
	//
	//if (false == InputControll::IsCurFrameUsedKey() && true == GameEngineInput::IsPress("LeftMove"))
	//{
	//	InputControll::UsedKey();
	//}

	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("DownMove") || GameEngineInput::IsPress("UpMove"))
	{
		int2 NextIndex = Playerindex;

		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			NextIndex.x -= 1;		
			DirString = "Left_";
		}
		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			NextIndex.x += 1;
			DirString = "Right_";
		}
		else if (true == GameEngineInput::IsPress("UpMove"))
		{
			NextIndex.y -= 1;
			DirString = "Up_";
		}
		else if (true == GameEngineInput::IsPress("DownMove"))
		{
			NextIndex.y += 1;
			DirString = "Down_";
		}

		DirCheck("Idle");

		if (Fieldmap::Walkable(NextIndex))
		{
			EndPos = Fieldmap::GetPos(NextIndex);
			ChangeState(PlayerState::MOVE);
			InputControlHandle = InputControll::UseControll();
		}

		return;
	}
}
void Player::IdleEnd() 
{

}

void Player::MoveStart()
{
	DirCheck("Move");
	StartPos = GetPos();
	Fieldmap::EndEventCheck(Fieldmap::GetIndex(GetPos()));
}

void Player::MoveUpdate(float _Time)
{
	PlayerTime += _Time * 5.0f;
	
	float4 POS = float4::LerpClamp(StartPos, EndPos, PlayerTime);
	SetPos(POS); 
	if (PlayerTime < 1.0f)
	{

	}
	 if (PlayerTime > 1.0f) //다음타일까지의 이동시간
	 {
		 PlayerTime = 0.0f;

		 InputControlHandle = InputControll::ResetControll(InputControlHandle);

		 Fieldmap::StartEventCheck(Fieldmap::GetIndex(GetPos()));
		 Fieldmap::FieldUpdate();

		 ChangeState(PlayerState::IDLE);
	 }	 
}

void Player::MoveEnd()
{
}

void Player::JumpStart()
{

}
void Player::JumpUpdate(float _Time)
{
	PlayerJumpTime += _Time*5.0f;

	float4 Start = GetPos();
	if (true==IsPlayerDirUP)
	{
		NextJumpIndex = { Playerindex.x,Playerindex.y - 2 };
	}
	if (true == IsPlayerDirDOWN)
	{
		NextJumpIndex = { Playerindex.x ,Playerindex.y+2 };
	}
	if (true == IsPlayerDirLEFT)
	{
		NextJumpIndex = { Playerindex.x - 2,Playerindex.y };
	}
	if (true == IsPlayerDirRIGHT)
	{
		NextJumpIndex = { Playerindex.x + 2,Playerindex.y };
	}
	

	
	
	float4 End = Fieldmap::GetPos(NextJumpIndex);

	float4 NextJumpPos = float4::BezierClamp(Start, End, _Time);
	SetPos(NextJumpPos);

	if (PlayerJumpTime > 1.0f)
	{
		PlayerJumpTime = 0.0f;
		ChangeState(PlayerState::IDLE);
	}
}
void Player::JumpEnd()
{

}
