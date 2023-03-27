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
	Playerindex = Fieldmap::GetIndex(GetPos());
	Fieldmap::UpdateEventCheck(Playerindex);

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

	 if (PlayerTime > 1.0f) //����Ÿ�ϱ����� �̵��ð�
	 {
		 PlayerTime = 0.0f;

		 Fieldmap::StartEventCheck(Fieldmap::GetIndex(GetPos()));
		 Fieldmap::FieldUpdate();

		 ChangeState(PlayerState::IDLE);
	 }	 
}

void Player::MoveEnd()
{
}
