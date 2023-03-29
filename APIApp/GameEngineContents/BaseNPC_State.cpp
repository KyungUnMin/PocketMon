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

	if (1 == Distance && true == InputControll::CanControll() && true == GameEngineInput::IsDown("NpcTalk"))
	{
		ChangeState(NPCState::interaction);
		return;
	}

	if (0 < MovePoints.size())
	{
		MoveStartPos = GetPos();
		MoveEndPos = MovePoints.front();
		MovePoints.pop_front();

		Look(MoveStartPos, MoveEndPos);
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
}

// Interaction
void BaseNPC::InteractionStart()
{
	PlayAnimation();

	if (ScriptDatas.size() != 0)
	{
		FieldDialog::GetFieldDialog()->ConversationStart(&ScriptDatas);
		//InputHandle = InputControll::UseControll();
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
	InteractionFunc();

	if (InputHandle >= 0)
	{
		InputHandle = InputControll::ResetControll(InputHandle);
		InputControll::UsedKey();
	}
}

void BaseNPC::InteractionFunc()
{
}
