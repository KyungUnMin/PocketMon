#include "FieldmapFlower.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

FieldmapFlower::FieldmapFlower()
{
}

FieldmapFlower::~FieldmapFlower()
{
}

void FieldmapFlower::Start()
{
	float TileSize = Fieldmap::TileSize;
	float4 RenderScale = float4(TileSize, TileSize);

	GameEngineRender* RenderPtr = CreateRender("Flower.bmp", RenderOrder::FieldBack);
	RenderPtr->SetScale(RenderScale);
	RenderPtr->CreateAnimation({ .AnimationName = "Idle", .ImageName = "Flower.bmp", .Start = 0, .End = 4, .InterTime = 0.3f, .Loop = true});
	RenderPtr->ChangeAnimation("Idle");
}