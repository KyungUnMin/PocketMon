#include "DoorActorBase.h"
#include "Fieldmap.h"
#include "Player.h"
#include "MoveMapFadeEffect.h"
#include "InputControll.h"
#include "ContentsEnum.h"

const std::string DoorActorBase::DoorIdleAnimName = "DoorIdle";
const std::string DoorActorBase::DoorOpenAnimName = "DoorOpen";
const std::string DoorActorBase::DoorCloseAnimName = "DoorClose";

DoorActorBase::DoorActorBase() :
	OutDir(LookDir::Down)
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
	
	switch (LinkDoor->OutDir)
	{
	case LookDir::Up:
		MainPlayer->SetPlayerDirUp();
		break;
	case LookDir::Down:
		MainPlayer->SetPlayerDirDown();
		break;
	case LookDir::Left:
		MainPlayer->SetPlayerDirLeft();
		break;
	case LookDir::Right:
		MainPlayer->SetPlayerDirRight();
		break;
	default:
		break;
	}

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
		MsgAssert("�������� �ʴ� ���� ��ũ�Ϸ� �߽��ϴ�");
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