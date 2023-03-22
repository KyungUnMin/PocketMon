#include "BattlePlayer.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleLevel.h"
#include "PokeDataBase.h"
#include "BattleMonsterPlayer.h"

BattlePlayer* BattlePlayer::PlayerPtr = nullptr;

BattlePlayer::BattlePlayer()
{
	PlayerPtr = this;
}

BattlePlayer::~BattlePlayer()
{
	if (this == PlayerPtr)
	{
		PlayerPtr = nullptr;
	}
}


void BattlePlayer::Init(BattleFieldType _FieldType)
{
	CreateGround(_FieldType);
	CreatePlayerRender();
}



void BattlePlayer::CreateGround(BattleFieldType _FieldType)
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float Height = (ScreenSize.y - 230.f);
	std::string GroundPath = "";

	switch (_FieldType)
	{
	case BattleFieldType::Indoor:
		GroundPath = "BattleIndoorPlayerGround.bmp";
		break;
	case BattleFieldType::Forest0:
	case BattleFieldType::Forest1:
		GroundPath = "BattleForestPlayerGround.bmp";
		break;
	case BattleFieldType::Gym:
		GroundPath = "BattleGymPlayerGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, BattleRenderOrder::Player0);
	GroundRender->SetScaleToImage();

	const float4& RenderScale = GroundRender->GetScale();
	SetMovePositions({ ScreenSize.x + RenderScale.hx(), Height }, { RenderScale.hx(), Height });
}

void BattlePlayer::CreatePlayerRender()
{
	const float4 Offset = {0.f, -65.f};

	PlayerRenderPtr = CreateRender("BattlePlayer.bmp", BattleRenderOrder::Player0);
	PlayerRenderPtr->SetScaleToImage();
	PlayerRenderPtr->SetPosition(Offset);
}


void BattlePlayer::CreatePlayerMonster()
{
	Monster = GetLevel()->CreateActor<BattleMonsterPlayer>(UpdateOrder::Battle_Actors);
	Monster->Init(PokeNumber::Bulbasaur);
}