#include "FieldmapSingleDoor.h"
#include <GameEngineCore/GameEngineResources.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

FieldmapSingleDoor::FieldmapSingleDoor()
{
}

FieldmapSingleDoor::~FieldmapSingleDoor()
{
}

void FieldmapSingleDoor::RenderInit()
{
	DoorRender = CreateRender("SingleDoor.bmp", RenderOrder::FieldBack);

	float TileSIze = Fieldmap::TileSize;

	DoorRender->SetScale(float4(TileSIze, TileSIze));

	DoorRender->CreateAnimation({ .AnimationName = DoorIdleAnimName, .ImageName = "SingleDoor.bmp", .Start = 0, .End = 0,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorOpenAnimName, .ImageName = "SingleDoor.bmp", .Start = 0, .End = 3,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorCloseAnimName, .ImageName = "SingleDoor.bmp", .Start = 4, .End = 7,.InterTime = 0.075f, .Loop = false });

	DoorRender->ChangeAnimation(DoorIdleAnimName);
}

void FieldmapSingleDoor::PlayOpenSound()
{
	GameEngineResources::GetInst().SoundPlay("SlideDoorOpen.wav");
}