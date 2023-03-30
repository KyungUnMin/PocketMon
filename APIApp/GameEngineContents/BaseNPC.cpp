#include "BaseNPC.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "Fieldmap.h"
#include "ContentsEnum.h"
#include "ContentConst.h"
#include "Player.h"
#include "InputControll.h"
#include "BattleLevel.h"

BaseNPC::BaseNPC() :
	Dir(LookDir::Up),
	InteractionDir(LookDir::Right),
	Type(BattleNpcType::None)
{
	PokemonDatas.reserve(6);
}

BaseNPC::~BaseNPC()
{
}

void BaseNPC::InitNPC(const std::string_view& _Name, const std::string_view& _ImageName, BattleNpcType _NpcType)
{
	Name = _Name;
	Type = _NpcType;

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
	NPCRender->CreateAnimation({.AnimationName = "Interaction_Down", .ImageName = _ImageName, .Start = 21, .End = 21, .Loop = false});
	NPCRender->CreateAnimation({.AnimationName = "Interaction_Left", .ImageName = _ImageName, .Start = 22, .End = 22, .Loop = false});
	NPCRender->CreateAnimation({.AnimationName = "Interaction_Right", .ImageName = _ImageName, .Start = 23, .End = 23, .Loop = false});
}

void BaseNPC::AddNPC(const std::string_view& _CityName, int2 _Index)
{
	CityName = _CityName;
	Fieldmap::AddActor(_CityName, _Index, this, false);
}

void BaseNPC::AddScript(const std::string_view& _Script)
{
	ScriptDatas.push_back(_Script.data());
}

void BaseNPC::Look(LookDir _Dir)
{
	Dir = _Dir;
	PlayAnimation();
}

void BaseNPC::Look(const float4& _TargetPos)
{
	Look(GetPos(), _TargetPos);
}

void BaseNPC::Look(const float4& _NpcPos, const float4& _TargetPos)
{
	int2 NpcIndex = Fieldmap::GetIndex(_NpcPos);
	int2 TargetIndex = Fieldmap::GetIndex(_NpcPos);

	Look(NpcIndex, TargetIndex);
}

void BaseNPC::Look(const int2& _NpcIndex, const int2& _TargetPos)
{
	Look(GetDir(_NpcIndex, _TargetPos));
}

LookDir BaseNPC::GetDir(const int2& _ViewIndex, const int2& _TargetIndex)
{
	int2 DirIndex = _TargetIndex - _ViewIndex;

	if (DirIndex.x != 0 && DirIndex.y != 0)
	{
		int SizeX = abs(DirIndex.x);
		int SizeY = abs(DirIndex.y);

		if (SizeX > SizeY)
		{
			DirIndex.y = 0;
		}
		else
		{
			DirIndex.x = 0;
		}
	}

	if (0 < DirIndex.x)
	{
		return LookDir::Right;
	}
	else if (0 > DirIndex.x)
	{
		return LookDir::Left;
	}
	else if (0 < DirIndex.y)
	{
		return LookDir::Down;
	}
	else
	{
		return LookDir::Up;
	}
}

LookDir BaseNPC::TurnLeftDir(LookDir _Dir)
{
	switch (_Dir)
	{
	case LookDir::Up:
		return LookDir::Left;
	case LookDir::Down:
		return LookDir::Right;
	case LookDir::Left:
		return LookDir::Down;
	case LookDir::Right:
		return LookDir::Up;
	default:
		return _Dir;
	}
}

LookDir BaseNPC::TurnRightDir(LookDir _Dir)
{
	switch (_Dir)
	{
	case LookDir::Up:
		return LookDir::Right;
	case LookDir::Down:
		return LookDir::Left;
	case LookDir::Left:
		return LookDir::Up;
	case LookDir::Right:
		return LookDir::Down;
	default:
		return _Dir;
	}
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

void BaseNPC::PlayAnimation()
{
	switch (Dir)
	{
	case LookDir::Up:
		NPCRender->ChangeAnimation(AnimationName + "_Up");
		break;
	case LookDir::Down:
		NPCRender->ChangeAnimation(AnimationName + "_Down");
		break;
	case LookDir::Left:
		NPCRender->ChangeAnimation(AnimationName + "_Left");
		break;
	case LookDir::Right:
		NPCRender->ChangeAnimation(AnimationName + "_Right");
		break;
	default:
		MsgAssert("잘못된 NPC Dir 입니다");
		break;
	}

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
		AnimationName = "Idle";
		IdleStart();
		break;
	case BaseNPC::NPCState::Move:
		AnimationName = "Move";
		MoveStart();
		break;
	case BaseNPC::NPCState::interaction:
		AnimationName = "Interaction";
		InteractionStart();
		break;
	default:
		MsgAssert("잘못된 NPC State 입니다");
		break;
	}

	State = _State;
}

bool BaseNPC::CheckInteractionTrigger() const
{

	if (false == InputControll::CanControll())
	{
		return false;
	}


	Player* PlayerPtr = Player::MainPlayer;
	
	int2 NpcIndex = Fieldmap::GetIndex(GetPos());
	int2 PlayerIndex = Fieldmap::GetIndex(PlayerPtr->GetPos());

	switch (TriggerType)
	{
	case BaseNPC::InteractionTriggerType::None:
		return false;
	case BaseNPC::InteractionTriggerType::Talk:
	{
		int Distance = int2::GetDistance(NpcIndex, PlayerIndex);
	
		if (1 != Distance)
		{
			return false;
		}

		LookDir PlayerLookDir = PlayerPtr->GetDir();

		if (PlayerLookDir != GetDir(PlayerIndex, NpcIndex))
		{
			return false;
		}

		if (false == GameEngineInput::IsDown("NpcTalk"))
		{
			return false;
		}

		return true;
	}
		break;
	case BaseNPC::InteractionTriggerType::Shop:
	{
		LookDir PlayerLookDir = PlayerPtr->GetDir();

		if (InteractionIndex != PlayerIndex)
		{
			return false;
		}

		if (InteractionDir != PlayerLookDir)
		{
			return false;
		}

		if (false == GameEngineInput::IsDown("NpcTalk"))
		{
			return false;
		}

		return true;
	}
		break;
	case BaseNPC::InteractionTriggerType::Look:
	{
		int2 CheckIndex = NpcIndex;

		for (size_t i = 0; i < LookDistance; i++)
		{
			switch (Dir)
			{
			case LookDir::Up:
				CheckIndex.y -= 1;
				break;
			case LookDir::Down:
				CheckIndex.y += 1;
				break;
			case LookDir::Left:
				CheckIndex.x -= 1;
				break;
			case LookDir::Right:
				break;
				CheckIndex.x += 1;
			default:
				break;
			}

			if (CheckIndex == PlayerIndex)
			{
				return true;
			}

			if (false == Fieldmap::Walkable(CheckIndex))
			{
				return false;
			}
		}
	}
		break;
	default:
		break;
	}

	return false;
}
