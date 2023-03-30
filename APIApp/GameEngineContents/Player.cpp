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

Player::Player() :
	Dir(LookDir::Up)
{
}

Player::~Player()
{
	delete PlayerPokemon;
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
	//
	PlayerPokemon = new TrainerPokemon();
	PlayerPokemon->AddPokemon(1, 1);
	PlayerPokemon->AddPokemon(4, 1);
	PlayerPokemon->AddPokemon(7, 1);


	PlayerKeyLoad();
	PlayerRenderLoad();
	PlayerCollisionSet();
		
	ChangeState(PlayerState::IDLE);
}

void Player::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("PlayerAutoMoveDebug"))
	{
		if (NextMovePos.size() != 0)
		{
			return;
		}

		float4 TestPos = GetPos();

		for (size_t i = 0; i < 10; i++)
		{
			TestPos += float4{ 64,0 };
			InsertPlayerPos(TestPos);			
		}

		for (size_t i = 0; i < 10; i++)
		{
			TestPos += float4{ 0, 64 };
			InsertPlayerPos(TestPos);
		}

		for (size_t i = 0; i < 10; i++)
		{
			TestPos += float4{ -64, 0 };
			InsertPlayerPos(TestPos);
		}
	}

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
		UpdateState(_DeltaTime); //�����Ӱ���
		NPCtalkValueSet(); //NPC���⼼�ÿ�
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
	if (GameEngineInput::IsPress("CollisionRender"))
	{
		//RedCollision->DebugRender();
	}
}

void Player::ChangeLevelCheck()
{
	/*if (Ȯ�� || Collision�� ������)
	{
		switch (FieldmapCity::GetGroundType(int2 & _index))
		{
		case:
				GameEngineCore::ChangeLevel("������battle level");
				break;
		case:
				GameEngineCore::ChangeLevel("������battle level");
				break;
		case:
				GameEngineCore::ChangeLevel("������battle level");
				break;
		}
	}
	if (GameEngineInput::IsDown("������ItemBag"))
	{
		GameEngineCore::ChangeLevel("������ItemLevel");
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
	}
	else if (GameEngineInput::IsDown("RightMove"))
	{
		TalkValue = NPCtalkValue::LEFT;
	}
	else if (GameEngineInput::IsDown("UpMove"))
	{
		TalkValue = NPCtalkValue::DOWN;
	}
	else if (GameEngineInput::IsDown("DownMove"))
	{
		TalkValue = NPCtalkValue::UP;
	}
}

void Player::JumpRight()
{
	NextJumpIndex = { Playerindex.x + 2,Playerindex.y };
	ChangeState(PlayerState::JUMP);
	Dir = LookDir::Right;
}
void Player::JumpUp()
{
	NextJumpIndex = { Playerindex.x,Playerindex.y - 2 };
	ChangeState(PlayerState::JUMP);
	Dir = LookDir::Up;
}
void Player::JumpLeft()
{
	NextJumpIndex = { Playerindex.x - 2,Playerindex.y };
	ChangeState(PlayerState::JUMP);
	Dir = LookDir::Left;
}
void Player::JumpDown()
{
	NextJumpIndex = { Playerindex.x ,Playerindex.y + 2 };
	ChangeState(PlayerState::JUMP);
	Dir = LookDir::Down;
}



