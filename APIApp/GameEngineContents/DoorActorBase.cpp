#include "DoorActorBase.h"
#include "Fieldmap.h"
#include "Player.h"
#include "MoveMapFadeEffect.h"

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
		MsgAssert("�ʵ�� Door�� ��ũ�� nullptr �Դϴ�");
	}

	Player* MainPlayer = Player::MainPlayer;

	if (nullptr == MainPlayer)
	{
		MsgAssert("�̵���ų �÷��̾ �������� �ʽ��ϴ�");
	}

	MainPlayer->SetPos(Fieldmap::GetPos(LinkDoor->DoorCity, LinkDoor->DoorIndex));
	Fieldmap::FieldUpdate();
	LinkDoor->DoorOpenAndClose();
}

void DoorActorBase::SetLinkDoor(DoorActorBase* _LinkDoor)
{
	if (nullptr == _LinkDoor)
	{
		MsgAssert("�������� �ʴ� ���� ��ũ�Ϸ� �߽��ϴ�");
	}

	LinkDoor = _LinkDoor;
}

void DoorActorBase::UseDoor()
{
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