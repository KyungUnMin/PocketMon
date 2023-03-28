#include "BaseNPC.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineRender.h>
#include "Fieldmap.h"
#include "ContentsEnum.h"
#include "ContentConst.h"

BaseNPC::BaseNPC()
{
}

BaseNPC::~BaseNPC()
{
}

void BaseNPC::InitNPC(const std::string_view& _Name, const std::string_view& _ImageName)
{
	Name = _Name;

	NPCRender = CreateRender(_ImageName, RenderOrder::Player);
	NPCRender->SetScale(ContentConst::NpcSize);

	NPCRender->CreateAnimation({.AnimationName = "Idle_Up", .ImageName = _ImageName, .Start = 0, .End = 0, .Loop = false });
	NPCRender->CreateAnimation({.AnimationName = "Idle_Down", .ImageName = _ImageName, .Start = 1, .End = 1, .Loop = false });
	NPCRender->CreateAnimation({.AnimationName = "Idle_Left", .ImageName = _ImageName, .Start = 2, .End = 2, .Loop = false });
	NPCRender->CreateAnimation({.AnimationName = "Idle_Right", .ImageName = _ImageName, .Start = 3, .End = 3, .Loop = false });

	NPCRender->CreateAnimation({.AnimationName = "Move_Up", .ImageName = _ImageName, .Start = 4, .End = 7, .Loop = true });
	NPCRender->CreateAnimation({.AnimationName = "Move_Down", .ImageName = _ImageName, .Start = 8, .End = 11, .Loop = true });
	NPCRender->CreateAnimation({.AnimationName = "Move_Left", .ImageName = _ImageName, .Start = 12, .End = 15, .Loop = true});
	NPCRender->CreateAnimation({.AnimationName = "Move_Right", .ImageName = _ImageName, .Start = 16, .End = 19, .Loop = true});

	NPCRender->CreateAnimation({.AnimationName = "Interaction_Up", .ImageName = _ImageName, .Start = 20, .End = 20, .Loop = false});
	NPCRender->CreateAnimation({.AnimationName = "Interaction_Down", .ImageName = _ImageName, .Start = 20, .End = 20, .Loop = false});
	NPCRender->CreateAnimation({.AnimationName = "Interaction_Left", .ImageName = _ImageName, .Start = 20, .End = 20, .Loop = false});
	NPCRender->CreateAnimation({.AnimationName = "Interaction_Right", .ImageName = _ImageName, .Start = 20, .End = 20, .Loop = false});
}

void BaseNPC::AddNPC(const std::string_view& _CityName, int2 _Index)
{
	Fieldmap::AddActor(_CityName, _Index, this, false);
}

void BaseNPC::Update(float _DeltaTime)
{
	switch (State)
	{
	case BaseNPC::NPCState::Idle:
		IdleUpdate(_DeltaTime);
		break;
	case BaseNPC::NPCState::Move:
		MoveUpdate(_DeltaTime);
		break;
	case BaseNPC::NPCState::interaction:
		InteractionUpdate(_DeltaTime);
		break;
	default:
		MsgAssert("잘못된 NPC State 입니다");
		break;
	}
}

void BaseNPC::PlayAnimation(const std::string_view& _AnimationName)
{
	std::string PlayAnimName = _AnimationName.data();

	switch (Dir)
	{
	case BaseNPC::NPCDir::Up:
		PlayAnimName += "_Up";
		break;
	case BaseNPC::NPCDir::Down:
		PlayAnimName += "_Down";
		break;
	case BaseNPC::NPCDir::Left:
		PlayAnimName += "_Left";
		break;
	case BaseNPC::NPCDir::Right:
		PlayAnimName += "_Right";
		break;
	default:
		MsgAssert("잘못된 NPC Dir 입니다");
		break;
	}

	NPCRender->ChangeAnimation(PlayAnimName);
}

void BaseNPC::ChangeState(NPCState _State)
{
	switch (State)
	{
	case BaseNPC::NPCState::Idle:
		IdleEnd();
		break;
	case BaseNPC::NPCState::Move:
		MoveEnd();
		break;
	case BaseNPC::NPCState::interaction:
		InteractionEnd();
		break;
	default:
		MsgAssert("잘못된 NPC State 입니다");
		break;
	}

	switch (_State)
	{
	case BaseNPC::NPCState::Idle:
		IdleStart();
		break;
	case BaseNPC::NPCState::Move:
		MoveStart();
		break;
	case BaseNPC::NPCState::interaction:
		InteractionStart();
		break;
	default:
		MsgAssert("잘못된 NPC State 입니다");
		break;
	}

	State = _State;
}