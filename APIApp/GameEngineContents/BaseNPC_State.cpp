#include "BaseNPC.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "Fieldmap.h"
#include "InputControll.h"
#include "FieldDialog.h"
#include "Player.h"

// Idle
void BaseNPC::IdleStart()
{
	PlayAnimation();
}

void BaseNPC::IdleUpdate(float _DeltaTime)
{
	int2 NpcIndx = Fieldmap::GetIndex(GetPos());
	int2 PlayerIndex = Fieldmap::GetIndex(Player::MainPlayer->GetPos());
	
	int Distance = NpcIndx.GetDistance(PlayerIndex);

	if (1 == Distance)
	{
		LookDir PosDir = GetDir(PlayerIndex, NpcIndx);
		LookDir PlayerViewDir = Player::MainPlayer->GetDir();

		if (PosDir == PlayerViewDir && true == InputControll::CanControll() && true == GameEngineInput::IsDown("NpcTalk"))
		{
			ChangeState(NPCState::interaction);
			Look(NpcIndx, PlayerIndex);
			return;
		}
	}

	if (0 < MovePoints.size())
	{
		MoveStartPos = GetPos();
		MoveStartIndex = Fieldmap::GetIndex(MoveStartPos);

		MoveEndPos = MovePoints.front();
		MoveEndIndex = Fieldmap::GetIndex(MoveEndPos);

		MovePoints.pop_front();
		Look(MoveStartIndex, MoveEndIndex);

		ChangeState(NPCState::Move);
		return;
	}
}

void BaseNPC::IdleEnd()
{

}

// Move
void BaseNPC::MoveStart()
{
	PlayAnimation();
	MoveProgress = 0.0f;

	Fieldmap::SetWalkable(CityName, MoveEndIndex, false);
}

void BaseNPC::MoveUpdate(float _DeltaTime)
{
	MoveProgress += _DeltaTime * MoveSpeed;
	SetPos(float4::LerpClamp(MoveStartPos, MoveEndPos, MoveProgress));

	if (1.0f <= MoveProgress)
	{
		ChangeState(NPCState::Idle);
		return;
	}
}

void BaseNPC::MoveEnd()
{
	MoveProgress = 0.0f;
	Fieldmap::SetWalkable(CityName, MoveStartIndex, true);
}

// Interaction
void BaseNPC::InteractionStart()
{
	PlayAnimation();

	if (ScriptDatas.size() != 0)
	{
		FieldDialog::GetFieldDialog()->ConversationStart(&ScriptDatas);
		InputHandle = InputControll::UseControll();
		InputControll::UsedKey();
	}
}

void BaseNPC::InteractionUpdate(float _DeltaTime)
{
	if (ScriptDatas.size() == 0)
	{
		ChangeState(NPCState::Idle);
	}

	if (false == FieldDialog::GetFieldDialog()->IsUpdate())
	{
		ChangeState(NPCState::Idle);
	}
}

void BaseNPC::InteractionEnd()
{
	for (const std::function<void()>& Func : InteractionFuncs)
	{
		Func();
	}

	InteractionFuncs.clear();

	for (const std::function<void()>& Func : LoopInteractionFuncs)
	{
		Func();
	}

	if (InputHandle >= 0)
	{
		InputHandle = InputControll::ResetControll(InputHandle);
	}
}

void BaseNPC::AddInteractionFunc(std::function<void()> _Func, bool _IsLoop )
{
	if (true == _IsLoop)
	{
		LoopInteractionFuncs.push_back(_Func);
	}
	else
	{
		InteractionFuncs.push_back(_Func);
	}
}
