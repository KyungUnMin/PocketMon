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

Player* Player::MainPlayer;

Player::Player()
{
}

Player::~Player()
{
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
	if (true == PlayerMoveBool)
	{
		UpdateState(_DeltaTime); //崇送績淫軒
	}
	
	if (Fieldmap::Walkable(GetPos() + (MoveDir * _DeltaTime)) && true == PlayerMoveBool)
	{
	}
	NPCtalkValueSet(); //NPC号狽室特遂
	ChangeLevelCheck();
}

//己 中宜 淫軒        
void Player::Movecalculation(float _DeltaTime)
{
	
}

//collision 端滴
void Player::CollisionCheck(float _DeltaTime)
{
	
}

void Player::ChangeLevelCheck()
{
	/*if (溌懸 || Collision拭 願生檎)
	{
		switch (FieldmapCity::GetGroundType(int2 & _index))
		{
		case:
				GameEngineCore::ChangeLevel("しししbattle level");
				break;
		case:
				GameEngineCore::ChangeLevel("しししbattle level");
				break;
		case:
				GameEngineCore::ChangeLevel("しししbattle level");
				break;
		}
	}
	if (GameEngineInput::IsDown("しししItemBag"))
	{
		GameEngineCore::ChangeLevel("しししItemLevel");
	}*/
}

void Player::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	Players->ChangeAnimation(DirString + _AnimationName.data());
	BikePlayers->ChangeAnimation(DirString + _AnimationName.data());

	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
	}
	else if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
	}

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

void Player::Render(float _DeltaTime)
{
	float4 PlayerPos = GetPos() - GetLevel()->GetCameraPos();

	Rectangle(GameEngineWindow::GetWindowBackBufferHdc(),
		PlayerPos.ix() - 5,
		PlayerPos.iy() - 5,
		PlayerPos.ix() + 5,
		PlayerPos.iy() + 5);
	if (GameEngineInput::IsPress("CollisionRender"))
	{
		RedCollision->DebugRender();
	}
}

