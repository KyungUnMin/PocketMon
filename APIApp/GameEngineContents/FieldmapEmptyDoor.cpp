#include "FieldmapEmptyDoor.h"
#include <GameEngineCore/GameEngineResources.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

FieldmapEmptyDoor::FieldmapEmptyDoor()
{
}

FieldmapEmptyDoor::~FieldmapEmptyDoor()
{
}

void FieldmapEmptyDoor::UseDoor()
{
	GameEngineResources::GetInst().SoundPlay("ExitBuilding.wav");	
	DoorActorBase::UseDoor();
}

void FieldmapEmptyDoor::RenderInit()
{
	DoorRender = CreateRender("Empty.bmp", RenderOrder::FieldBack);

	float TileSIze = Fieldmap::TileSize;

	DoorRender->SetScale(float4(TileSIze, TileSIze));

	DoorRender->CreateAnimation({ .AnimationName = DoorIdleAnimName, .ImageName = "Empty.bmp", .Start = 0, .End = 0,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorOpenAnimName, .ImageName = "Empty.bmp", .Start = 0, .End = 0,.InterTime = 0.075f, .Loop = false });
	DoorRender->CreateAnimation({ .AnimationName = DoorCloseAnimName, .ImageName = "Empty.bmp", .Start = 0, .End = 0,.InterTime = 0.075f, .Loop = false });

	DoorRender->ChangeAnimation(DoorIdleAnimName);
}
