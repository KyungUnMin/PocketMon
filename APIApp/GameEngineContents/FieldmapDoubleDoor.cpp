#include "FieldmapDoubleDoor.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

FieldmapDoubleDoor::FieldmapDoubleDoor()
{
}

FieldmapDoubleDoor::~FieldmapDoubleDoor()
{
}

void FieldmapDoubleDoor::Start()
{
	DoorRender = CreateRender("DoubleDoor.bmp", RenderOrder::FieldBack);

	float TileSIze = Fieldmap::TileSize;

	DoorRender->SetScale(float4(TileSIze, TileSIze));

	DoorRender->CreateAnimation({.AnimationName = "DoorIdle", .ImageName = "DoubleDoor.bmp", .Start = 0, .End = 0, .Loop = false});
	DoorRender->CreateAnimation({.AnimationName = "DoorPlay", .ImageName = "DoubleDoor.bmp", .Start = 0, .End = 3, .Loop = false});

	DoorRender->ChangeAnimation("DoorIdle");
}

void FieldmapDoubleDoor::Update(float _DeltaTime)
{
	DoorEvent.Update(_DeltaTime);
}

void FieldmapDoubleDoor::UseDoor()
{
	if (true == IsUse)
	{
		return;
	}

	IsUse = true;
	DoorRender->ChangeAnimation("DoorPlay");
	DoorEvent.AddEvent(0.4f, std::bind(&FieldmapDoubleDoor::Fade, this), false);
}

void FieldmapDoubleDoor::ActorMove()
{
	IsUse = false;
	DoorRender->ChangeAnimation("DoorIdle");

	DebugMsgBox(DestCityName + ", " + DestIndex.ToString() + "으로 이동합니다");
}

void FieldmapDoubleDoor::Fade()
{
	DoorEvent.AddEvent(0.5f, std::bind(&FieldmapDoubleDoor::ActorMove, this), false);
}