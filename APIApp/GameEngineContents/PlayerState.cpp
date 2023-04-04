#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "InputControll.h"

#include "Player.h"
#include "Fieldmap.h"
#include "ShopNpc.h"
#include "JumpEffect.h"


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
	case PlayerState::GymClear:
		GymClearStart();
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
	case PlayerState::GymClear:
		GymClearEnd();
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
	case PlayerState::GymClear:
		GymClearUpdate(_Time);
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
	if (NextMovePos.size() != 0)
	{
		EndPos = NextMovePos.front();
		NextMovePos.pop_front();

		switch (CalLookDir(GetPos(), EndPos))
		{
		case LookDir::Up:
			Dir = LookDir::Up;
			DirString = "Up_";
			break;
		case LookDir::Down:
			Dir = LookDir::Down;
			DirString = "Down_";
			break;
		case LookDir::Left:
			Dir = LookDir::Left;
			DirString = "Left_";
			break;
		case LookDir::Right:
			Dir = LookDir::Right;
			DirString = "Right_";
			break;
		default:
			Dir = LookDir::Down;
			DirString = "Down_";
			break;
		}

		ChangeState(PlayerState::MOVE);
		return;
	}

	if (false == InputControll::CanControll())
	{
		return;
	}

	Playerindex = Fieldmap::GetIndex(GetPos());	

	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("DownMove") || GameEngineInput::IsPress("UpMove"))
	{
		NextIndex = Playerindex;

		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			NextIndex.x -= 1;		
			DirString = "Left_";
			Dir = LookDir::Left;
		}
		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			NextIndex.x += 1;
			DirString = "Right_";
			Dir = LookDir::Right;
		}
		else if (true == GameEngineInput::IsPress("UpMove"))
		{
			NextIndex.y -= 1;
			DirString = "Up_";
			Dir = LookDir::Up;
		}
		else if (true == GameEngineInput::IsPress("DownMove"))
		{
			NextIndex.y += 1;
			DirString = "Down_";
			Dir = LookDir::Down;
		}

		DirCheck("Idle");

		if (Fieldmap::Walkable(NextIndex))
		{
			EndPos = Fieldmap::GetPos(NextIndex);
			ChangeState(PlayerState::MOVE);
			InputControlHandle = InputControll::UseControll();
			return;
		}
		else if (!(Fieldmap::Walkable(NextIndex)) &&
			(GameEngineInput::IsDown("LeftMove") ||
				GameEngineInput::IsDown("RightMove") ||
				GameEngineInput::IsDown("DownMove") ||
				GameEngineInput::IsDown("UpMove")))
		{
			BlockSound = GameEngineResources::GetInst().SoundPlayToControl("PlayerMoveBlock.wav");
			BlockSound.LoopCount(1);
			BlockSound.Volume(0.2f);
		}
		
	}

	Fieldmap::UpdateEventCheck(Playerindex);
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
	PlayerTime += _Time * PlayerMoveSpeed;
	
	float4 POS = float4::LerpClamp(StartPos, EndPos, PlayerTime);
	SetPos(POS); 
	
	 if (PlayerTime > 1.0f) //다음타일까지의 이동시간
	 {
		 PlayerTime = 0.0f;
		
		 Fieldmap::FieldUpdate();

		 ChangeState(PlayerState::IDLE);
	 }	 
}

void Player::MoveEnd()
{
	if (0 <= InputControlHandle)
	{
		InputControlHandle = InputControll::ResetControll(InputControlHandle);
	}
	Fieldmap::StartEventCheck(Fieldmap::GetIndex(GetPos()));
}

void Player::JumpStart()
{
	JumpStartPos = GetPos();
	JumpEndPos = Fieldmap::GetPos(NextJumpIndex);

	JumpSound = GameEngineResources::GetInst().SoundPlayToControl("PlayerJump.wav");
	JumpSound.LoopCount(1);
	JumpSound.Volume(0.3f);
	
}
void Player::JumpUpdate(float _Time)
{
	PlayerJumpTime += _Time * PlayerJumpSpeed;
	Shadow->On();

	if (IsRide == false)
	{
		Players->ChangeAnimation("Jump");
	}

	float4 NextJumpPos = float4::BezierClamp(JumpStartPos, JumpEndPos, JumpHeight, PlayerJumpTime);
	SetPos(NextJumpPos);

	if (PlayerJumpTime > 1.0f)
	{
		JumpEffect* Test=GetLevel()->CreateActor<JumpEffect>();
		Test->SetPos(GetPos());
		Shadow->Off();
		PlayerJumpTime = 0.0f;
		ChangeState(PlayerState::IDLE);
	}
	
}
void Player::JumpEnd()
{
	
}

void Player::GymClearStart()
{
	ClaerProgress = 0.0f;
	Dir = LookDir::Down;
	DirString = "Down_";
	Players->ChangeAnimation("Down_Clear");
}

void Player::GymClearUpdate(float _Time)
{
	ClaerProgress += _Time;

	if (3.0f <= ClaerProgress)
	{
		ChangeState(PlayerState::IDLE);
	}
}

void Player::GymClearEnd()
{

}

void Player::PlayerAutoMove()
{
	if (NextMovePos.size() != 0)
	{
		
		std::list<float4>::iterator It;
		StartPos = GetPos();
		for (It = NextMovePos.begin(); It != NextMovePos.end() ; ++It)
		{
			InputControlHandle = InputControll::UseControll();
			EndPos =*It;
			ChangeState(PlayerState::MOVE);
		}

	}
}