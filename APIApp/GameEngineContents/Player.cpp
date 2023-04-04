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
#include "PokemonCenterNPC.h"

Player* Player::MainPlayer;
bool Player::GymClear = false;

LookDir Player::CalLookDir(const float4& _Start, const float4& _End)
{
	float4 Dir = _End - _Start;

	if (0.5f > std::fabsf(Dir.x))
	{
		Dir.x = 0;
	}

	if (0.5f > std::fabsf(Dir.y))
	{
		Dir.y = 0;
	}

	if (Dir.x > 0)
	{
		return LookDir::Right;
	}
	else if (Dir.x < 0)
	{
		return LookDir::Left;
	}
	else if (Dir.y > 0)
	{
		return LookDir::Down;
	}
	else if (Dir.y < 0)
	{
		return LookDir::Up;
	}
	else
	{
		return LookDir::Down;
	}
}

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


	PlayerSoundLoad();
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
		PlayerMoveSpeed = 7.5f;
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

		if (false == InputControll::CanControll())
		{
			return;
		}

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
	//일단 내리기기능만
	if (GameEngineInput::IsPress("CollisionRender"))
	{
		//IsRide = false;
		SetPlayerDeath();
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


void Player::PlayerDeathCheckFunction()
{
	if (true == IsRide)
	{
		IsRide = false;
	}
	if (0 == CityValue)
	{
		Fieldmap::ChangeCity("PalletTown_Home2F");
		Player::MainPlayer->SetPos(Fieldmap::GetPos("PalletTown_Home2F", int2{ 7,7 }));
	}
	else if (1 == CityValue)
	{
		Fieldmap::ChangeCity("ViridianCity");
		Player::MainPlayer->SetPos(Fieldmap::GetPos("ViridianCity", int2{ 20,27 }));
	}
	else if (2 == CityValue)
	{
		Fieldmap::ChangeCity("PewterCity");
		Player::MainPlayer->SetPos(Fieldmap::GetPos("PewterCity", int2{ 17,26 }));
	}
	else
	{
		MsgAssert("등록되지않은CityValue값입니다.");
	}
	
	Fieldmap::FieldUpdate();
}







