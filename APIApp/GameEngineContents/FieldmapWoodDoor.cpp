#include "FieldmapWoodDoor.h"
#include <GameEngineCore/GameEngineResources.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

FieldmapWoodDoor::FieldmapWoodDoor()
{
}

FieldmapWoodDoor::~FieldmapWoodDoor()
{
}

void FieldmapWoodDoor::RenderInit()
{
	DoorRender = CreateRender("WoodDoor.bmp", RenderOrder::FieldBack);

	float TileSIze = Fieldmap::TileSize;

	DoorRender->SetScale(float4(TileSIze, TileSIze));

	DoorRender->CreateAnimation({ .AnimationName = DoorIdleAnimName, .ImageName = "WoodDoor.bmp", .Start = 0, .End = 0,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorOpenAnimName, .ImageName = "WoodDoor.bmp", .Start = 0, .End = 3,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorCloseAnimName, .ImageName = "WoodDoor.bmp", .Start = 4, .End = 7,.InterTime = 0.075f, .Loop = false });

	DoorRender->ChangeAnimation(DoorIdleAnimName);
}

void FieldmapWoodDoor::PlayOpenSound()
{
	GameEngineResources::GetInst().SoundPlay("WoodDoorOpen.wav");
}