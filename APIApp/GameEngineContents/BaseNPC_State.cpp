#include "BaseNPC.h"

// Idle
void BaseNPC::IdleStart()
{
	PlayAnimation("Idle");
}

void BaseNPC::IdleUpdate(float _DeltaTime)
{
	if (0 < MovePoints.size())
	{
		MoveStartPos = GetPos();
		MoveEndPos = MovePoints.front();
		MovePoints.pop_front();

		ChangeState(NPCState::Move);
	}
}

void BaseNPC::IdleEnd()
{

}

// Move
void BaseNPC::MoveStart()
{
	PlayAnimation("Move");
	MoveProgress = 0.0f;
}

void BaseNPC::MoveUpdate(float _DeltaTime)
{
	MoveProgress += _DeltaTime * MoveSpeed;
	SetPos(float4::LerpClamp(MoveStartPos, MoveEndPos, MoveProgress));

	if (1.0f <= MoveProgress)
	{
		ChangeState(NPCState::Idle);
	}
}

void BaseNPC::MoveEnd()
{
	MoveProgress = 0.0f;
}

// Interaction
void BaseNPC::InteractionStart()
{
	PlayAnimation("Interaction");
	InteractionProgress = 0.0f;
}

void BaseNPC::InteractionUpdate(float _DeltaTime)
{
	InteractionProgress += _DeltaTime;

	if (InteractionProgress >= InteractionTime)
	{
		if (0.0f == MoveProgress)
		{
			ChangeState(NPCState::Idle);
		}
		else
		{
			ChangeState(NPCState::Move);
		}
	}
}

void BaseNPC::InteractionEnd()
{
	InteractionProgress = 0.0f;

}