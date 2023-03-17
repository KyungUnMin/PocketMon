#include "BattleEnemy.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "BattleLevel.h"
#include "ContentsEnum.h"

BattleEnemy* BattleEnemy::NpcPtr = nullptr;

BattleEnemy::BattleEnemy()
{
	NpcPtr = this;
}

BattleEnemy::~BattleEnemy()
{
	if (this == NpcPtr)
	{
		NpcPtr = nullptr;
	}
}

void BattleEnemy::Init(BattleFieldType _FieldType)
{
	CreateGround(_FieldType);

}

void BattleEnemy::CreateGround(BattleFieldType _FieldType)
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float Height = 300.f;

	std::string GroundPath = "";
	switch (_FieldType)
	{
	case BattleFieldType::Indoor:
		GroundPath = "BattleIndoorEnemyGround.bmp";
		break;
	case BattleFieldType::Grass:
		GroundPath = "BattleGrassEnemyGround.bmp";
		break;
	case BattleFieldType::Stone:
		GroundPath = "BattleStoneEnemyGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, RenderOrder::Player);
	GroundRender->SetScaleToImage();

	const float4& RenderScale = GroundRender->GetScale();
	SetMovePositions({ -RenderScale.hx(), Height }, { ScreenSize.x - RenderScale.hx(), Height });
}

void BattleEnemy::CreatePlayer()
{

}
