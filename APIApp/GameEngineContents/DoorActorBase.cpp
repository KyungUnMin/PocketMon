#include "DoorActorBase.h"
#include "Fieldmap.h"
#include "Player.h"
#include "MoveMapFadeEffect.h"
#include "InputControll.h"

const std::string DoorActorBase::DoorIdleAnimName = "DoorIdle";
const std::string DoorActorBase::DoorOpenAnimName = "DoorOpen";
const std::string DoorActorBase::DoorCloseAnimName = "DoorClose";

DoorActorBase::DoorActorBase()
{
}

DoorActorBase::~DoorActorBase()
{
}

void DoorActorBase::Start()
{
	RenderInit();
}

void DoorActorBase::Update(float _DeltaTime)
{
	DoorEvent.Update(_DeltaTime);
}

void DoorActorBase::PlayerMove()
{
	if (nullptr == LinkDoor)
	{
		MsgAssert("필드맵 Door의 링크가 nullptr 입니다");
	}

	Player* MainPlayer = Player::MainPlayer;

	if (nullptr == MainPlayer)
	{
		MsgAssert("이동시킬 플레이어가 존재하지 않습니다");
	}

	MainPlayer->SetPos(Fieldmap::GetPos(LinkDoor->DoorCity, LinkDoor->DoorIndex));
	Fieldmap::FieldUpdate();
	LinkDoor->DoorOpenAndClose();

	LinkDoor->DoorEvent.AddEvent(0.5f,std::bind(
		[](DoorActorBase* _This)
		{
			_This->InputControllHandle = InputControll::ResetControll(_This->InputControllHandle);
		}, this), false);
}

void DoorActorBase::SetLinkDoor(DoorActorBase* _LinkDoor)
{
	if (nullptr == _LinkDoor)
	{
		MsgAssert("존재하지 않는 문을 링크하려 했습니다");
	}

	LinkDoor = _LinkDoor;
}

void DoorActorBase::UseDoor()
{
	if (false == InputControll::CanControll())
	{
		return;
	}

	InputControllHandle = InputControll::UseControll();

	DoorOpenAndClose();
	DoorEvent.AddEvent(0.5f, std::bind(&DoorActorBase::PlayerMove, this), false);
}


void DoorActorBase::DoorOpenAndClose()
{
	DoorOpen();
	DoorEvent.AddEvent(0.3f, std::bind(&DoorActorBase::DoorClose, this), false);
}

void DoorActorBase::DoorOpen()
{
	DoorRender->ChangeAnimation(DoorOpenAnimName, true);
	MoveMapFadeEffect::MainMoveMapFadeEffect->On();
}

void DoorActorBase::DoorClose()
{
	DoorRender->ChangeAnimation(DoorCloseAnimName, true);
}