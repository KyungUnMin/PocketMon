#include "StopOakNPC.h"
#include "InputControll.h"
#include "PokemonScript.h"
#include "Player.h"
#include "Fieldmap.h"
#include "FieldDialog.h"
#include "BgmPlayer.h"

StopOakNPC::StopOakNPC()
{
}

StopOakNPC::~StopOakNPC()
{
}

void StopOakNPC::Start()
{
	int OakDis = 7;

	int2 StartIndex = Fieldmap::GetIndex(Player::MainPlayer->GetPos());
	int2 OakIndex = StartIndex + int2(0, OakDis);

	SetPos(Fieldmap::GetPos("PalletTown", OakIndex));

	for (size_t i = 0; i < OakDis - 1; i++)
	{
		OakIndex.y -= 1;
		AddMovePoint(Fieldmap::GetPos("PalletTown", OakIndex));
	}

	InputHandle = InputControll::UseControll();
}

void StopOakNPC::IdleUpdate(float _DeltaTime)
{
	if (true == FirstEventEnd && true == SecondEventEnd)
	{
		PokemonScript::EndScript(0);
		InputHandle = InputControll::ResetControll(InputHandle);
		Death();
		return;
	}

	if (0 < MovePoints.size())
	{
		BgmPlayer::PlayBGMFade("MeetOak.mp3");
		MoveStartPos = GetPos();
		MoveStartIndex = Fieldmap::GetIndex(MoveStartPos);

		MoveEndPos = MovePoints.front();
		MoveEndIndex = Fieldmap::GetIndex(MoveEndPos);

		MovePoints.pop_front();
		Look(MoveStartIndex, MoveEndIndex);

		ChangeState(NPCState::Move);
		return;
	}
	else
	{
		if (false == FirstEventEnd)
		{
			FirstEventEnd = true;

			int2 CurIndex = Fieldmap::GetIndex(GetPos());
			int2 DestIndex = int2(22, 13);

			Player* MainPlayer = Player::MainPlayer;

			MainPlayer->SetPlayerDirDown();
			MainPlayer->InsertPlayerPos(GetPos());

			// Down Move
			for (size_t i = 0; i < 2; i++)
			{
				CurIndex.y += 1;
				AddMovePoint(Fieldmap::GetPos(CurIndex));
				MainPlayer->InsertPlayerPos(Fieldmap::GetPos(CurIndex));
			}
			// Left Move
			for (size_t i = 0; CurIndex.x != 17; i++)
			{
				CurIndex.x -= 1;
				AddMovePoint(Fieldmap::GetPos(CurIndex));
				MainPlayer->InsertPlayerPos(Fieldmap::GetPos(CurIndex));
			}
			// Down Move
			for (size_t i = 0; i < 11; i++)
			{
				CurIndex.y += 1;
				AddMovePoint(Fieldmap::GetPos(CurIndex));
				MainPlayer->InsertPlayerPos(Fieldmap::GetPos(CurIndex));
			}

			// Right Move
			for (size_t i = 0; i < 5; i++)
			{
				CurIndex.x += 1;
				AddMovePoint(Fieldmap::GetPos(CurIndex));
				MainPlayer->InsertPlayerPos(Fieldmap::GetPos(CurIndex));
			}

			CurIndex.y -= 1;
			AddMovePoint(Fieldmap::GetPos(CurIndex));
			MainPlayer->InsertPlayerPos(Fieldmap::GetPos(CurIndex));

			ChangeState(NPCState::interaction);
		}
		else
		{
			SecondEventEnd = true;
		}		
	}
}

void StopOakNPC::MoveStart()
{
	PlayAnimation();
	MoveProgress = 0.0f;
}

void StopOakNPC::MoveEnd()
{
	PlayAnimation();
	MoveProgress = 0.0f;
}

// Interaction
void StopOakNPC::InteractionStart()
{
	PlayAnimation();
	FieldDialog::GetFieldDialog()->ConversationStart(&ScriptDatas[ScriptKey]);
}

void StopOakNPC::InteractionUpdate(float _DeltaTime)
{
	if (false == FieldDialog::GetFieldDialog()->IsUpdate())
	{
		ChangeState(NPCState::Idle);
	}
}

void StopOakNPC::InteractionEnd()
{
}