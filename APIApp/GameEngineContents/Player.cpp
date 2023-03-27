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

Player* Player::MainPlayer;

Player::Player()
{
}

Player::~Player()
{
}

bool Player::VaildJumpUp()
{
	return false;
}

bool Player::VaildJumpDown()
{
	return false;
}

bool Player::VaildJumpLeft()
{
	return false;
}

bool Player::VaildJumpRight()
{
	return false;
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
		NPCtalkValueSet(); //NPC号狽室特遂
		if (true == GameEngineInput::IsDown("FieldMainMenuSwitch"))
		{
			FieldMainMenu::GetFieldMainMenu()->OnOffSwtich();
		}
	}
	ChangeLevelCheck();
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
		//瑛諾生艦猿 析舘差細
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