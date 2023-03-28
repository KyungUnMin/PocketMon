#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "Player.h"
#include "ContentsEnum.h"
#include "Fieldmap.h"
#include "FieldMainMenu.h"
#include "InputControll.h"

Player* Player::MainPlayer;

Player::Player()
{
}

Player::~Player()
{
}

bool Player::VaildJumpUp()
{
	if (false == InputControll::CanControll())
	{
		return false;
	}

	if (false == GameEngineInput::IsPress("UpMove"))
	{
		return false;
	}

	int2 JumpIndex = Playerindex;
	JumpIndex.y -= 2;

	return Fieldmap::Walkable(JumpIndex);
}

bool Player::VaildJumpDown()
{
	if (false == InputControll::CanControll())
	{
		return false;
	}

	if (false == GameEngineInput::IsPress("DownMove"))
	{
		return false;
	}

	int2 JumpIndex = Playerindex;
	JumpIndex.y += 2;
	ChangeState(PlayerState::JUMP);
	return Fieldmap::Walkable(JumpIndex);
}

bool Player::VaildJumpLeft()
{
	if (false == InputControll::CanControll())
	{
		return false;
	}

	if (false == GameEngineInput::IsPress("LeftMove"))
	{
		return false;
	}

	int2 JumpIndex = Playerindex;
	JumpIndex.x -= 2;

	return Fieldmap::Walkable(JumpIndex);
}

bool Player::VaildJumpRight()
{
	if (false == InputControll::CanControll())
	{
		return false;
	}

	if (false == GameEngineInput::IsPress("RightMove"))
	{
		return false;
	}

	int2 JumpIndex = Playerindex;
	JumpIndex.x += 2;
	
	return Fieldmap::Walkable(JumpIndex);
}

void Player::Start()
{
	MainPlayer = this; 

	PlayerKeyLoad();
	PlayerRenderLoad();
	PlayerCollisionSet();
		
	ChangeState(PlayerState::IDLE);
}

void Player::Update(float _DeltaTime)
{
	if (IsRide==true)
	{
		Players->Off();
		BikePlayers->On();
		PlayerMoveSpeed = 10.0f;
	}
	else if(IsRide==false)
	{
		Players->On();
		BikePlayers->Off();
		PlayerMoveSpeed = 5.0f;
	}
	if (true == PlayerMoveBool)
	{
		UpdateState(_DeltaTime); //움직임관리
		NPCtalkValueSet(); //NPC방향세팅용
		if (true == GameEngineInput::IsDown("FieldMainMenuSwitch"))
		{
			FieldMainMenu::GetFieldMainMenu()->OnOffSwtich();
		}
	}
	if (false == PlayerMoveBool)
	{
		if (false == GameEngineInput::IsDown("NpcTalk"))
		{
			return;
		}
	}
	ChangeLevelCheck();
}

void Player::Render(float _DeltaTime)
{
	float4 PlayerPos = GetPos() - GetLevel()->GetCameraPos();

	/*Rectangle(GameEngineWindow::GetWindowBackBufferHdc(),
		PlayerPos.ix() - 5,
		PlayerPos.iy() - 5,
		PlayerPos.ix() + 5,
		PlayerPos.iy() + 5);*/
	if (GameEngineInput::IsPress("CollisionRender"))
	{
		//RedCollision->DebugRender();
	}
}

void Player::ChangeLevelCheck()
{
	/*if (확률 || Collision에 닿으면)
	{
		switch (FieldmapCity::GetGroundType(int2 & _index))
		{
		case:
				GameEngineCore::ChangeLevel("ㅇㅇㅇbattle level");
				break;
		case:
				GameEngineCore::ChangeLevel("ㅇㅇㅇbattle level");
				break;
		case:
				GameEngineCore::ChangeLevel("ㅇㅇㅇbattle level");
				break;
		}
	}
	if (GameEngineInput::IsDown("ㅇㅇㅇItemBag"))
	{
		GameEngineCore::ChangeLevel("ㅇㅇㅇItemLevel");
	}*/
}

void Player::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	Players->ChangeAnimation(DirString + _AnimationName.data());
	BikePlayers->ChangeAnimation(DirString + _AnimationName.data());

	if (PrevDirString != DirString)
	{
		Players->ChangeAnimation(DirString + _AnimationName.data());
		BikePlayers->ChangeAnimation(DirString + _AnimationName.data());
	}
}

void Player::NPCtalkValueSet()
{
	if (GameEngineInput::IsDown("LeftMove"))
	{
		TalkValue = NPCtalkValue::RIGHT;
		//귀찮으니까 일단복붙
		IsPlayerDirUP = false;
		IsPlayerDirDOWN = false;
		IsPlayerDirLEFT = true;
		IsPlayerDirRIGHT = false;
	}
	else if (GameEngineInput::IsDown("RightMove"))
	{
		TalkValue = NPCtalkValue::LEFT;
		IsPlayerDirUP = false;
		IsPlayerDirDOWN = false;
		IsPlayerDirLEFT = false;
		IsPlayerDirRIGHT = true;
	}
	else if (GameEngineInput::IsDown("UpMove"))
	{
		TalkValue = NPCtalkValue::DOWN;
		IsPlayerDirUP = true;
		IsPlayerDirDOWN = false;
		IsPlayerDirLEFT = false;
		IsPlayerDirRIGHT = false;
	}
	else if (GameEngineInput::IsDown("DownMove"))
	{
		TalkValue = NPCtalkValue::UP;
		IsPlayerDirUP = false;
		IsPlayerDirDOWN = true;
		IsPlayerDirLEFT = false;
		IsPlayerDirRIGHT = false;
	}
}

void Player::JumpRight()
{
	NextJumpIndex = { Playerindex.x + 2,Playerindex.y };
	ChangeState(PlayerState::JUMP);
}
void Player::JumpUp()
{
	NextJumpIndex = { Playerindex.x,Playerindex.y - 2 };
	ChangeState(PlayerState::JUMP);
}
void Player::JumpLeft()
{
	NextJumpIndex = { Playerindex.x - 2,Playerindex.y };
	ChangeState(PlayerState::JUMP);
}
void Player::JumpDown()
{
	NextJumpIndex = { Playerindex.x ,Playerindex.y + 2 };
	ChangeState(PlayerState::JUMP);
}



