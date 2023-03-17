#include "BattlePlayer.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleLevel.h"

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

}

void BattlePlayer::CreateGround(BattleFieldType _FieldType)
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float Height = (ScreenSize.y - 196.f);
	std::string GroundPath = "";

	switch (_FieldType)
	{
	case BattleFieldType::Indoor:
		GroundPath = "BattleIndoorPlayerGround.bmp";
		break;
	case BattleFieldType::Grass:
		GroundPath = "BattleGrassPlayerGround.bmp";
		break;
	case BattleFieldType::Stone:
		GroundPath = "BattleStonePlayerGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, RenderOrder::Player);
	GroundRender->SetScaleToImage();

	const float4& RenderScale = GroundRender->GetScale();
	SetMovePositions({ ScreenSize.x + RenderScale.hx(), Height }, { RenderScale.hx(), Height });
}

void BattlePlayer::CreatePlayer()
{
	const float4 GroundRenderScale = float4{ 256.f, 196.f };
	GameEngineRender* GroundRender = CreateRender("BattlePlayer.bmp", RenderOrder::Player);
	GroundRender->SetScale(GroundRenderScale);
}
