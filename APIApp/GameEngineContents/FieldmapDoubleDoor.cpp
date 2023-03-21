#include "FieldmapDoubleDoor.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"
#include "Player.h"

FieldmapDoubleDoor::FieldmapDoubleDoor()
{
}

FieldmapDoubleDoor::~FieldmapDoubleDoor()
{
}

void FieldmapDoubleDoor::RenderInit()
{
	DoorRender = CreateRender("DoubleDoor.bmp", RenderOrder::FieldBack);

	float TileSIze = Fieldmap::TileSize;

	DoorRender->SetScale(float4(TileSIze, TileSIze));

	DoorRender->CreateAnimation({ .AnimationName = DoorIdleAnimName, .ImageName = "DoubleDoor.bmp", .Start = 0, .End = 0,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorOpenAnimName, .ImageName = "DoubleDoor.bmp", .Start = 0, .End = 3,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorCloseAnimName, .ImageName = "DoubleDoor.bmp", .Start = 4, .End = 7,.InterTime = 0.075f, .Loop = false });

	DoorRender->ChangeAnimation(DoorIdleAnimName);
}