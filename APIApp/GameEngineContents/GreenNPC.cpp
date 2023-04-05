#include "GreenNPC.h"
#include "PokemonScript.h"
#include "InputControll.h"
#include "Fieldmap.h"
#include "Player.h"
#include "FieldmapLevel.h"
#include "StartingPokeball.h"
#include "BgmPlayer.h"

GreenNPC::GreenNPC()
{
}

GreenNPC::~GreenNPC()
{
}

bool GreenNPC::BattleEventCheck()
{
	if (false == PokemonScript::IsScriptEnd(200) &&
		true == PokemonScript::IsScriptEnd(150) &&
		false == IsBattleEnd)
	{
		return true;
	}

	return false;
}

void GreenNPC::BattleStart()
{
	InputHandle = InputControll::UseControll();
	PokemonDatas.AddPokemon(PokeDataBase::PokeCreate(StartingPokeball::StaticRivalPokeball->GetPokeNumber(), 5));

	BgmPlayer::PlayBGM("RivalAppears.mp3");

	FieldmapLevel::AddLevelStartFunc(std::bind([](GreenNPC* _this)
		{
			int2 CurIndex = Fieldmap::GetIndex(_this->GetPos());

			for (size_t i = 0; i < 1; i++)
			{
				CurIndex.y += 1;
				_this->AddMovePoint(Fieldmap::GetPos(CurIndex));
			}

			if (CurIndex.x != 7)
			{
				CurIndex.x = 7;
				_this->AddMovePoint(Fieldmap::GetPos(CurIndex));
			}

			for (size_t i = 0; i < 2; i++)
			{
				CurIndex.y += 1;
				_this->AddMovePoint(Fieldmap::GetPos(CurIndex));
			}

			PokemonScript::EndScript(200);
			_this->IsBattleEnd = true;
		}, this));

	int2 NpcIndex = Fieldmap::GetIndex(GetPos());
	int2 PlayerIndex = Fieldmap::GetIndex(Player::MainPlayer->GetPos());

	NpcIndex.y += 1;
	AddMovePoint(Fieldmap::GetPos(NpcIndex));

	int DestX = 0;

	if (PlayerIndex.x >= 7)
	{
		DestX = 6;
	}
	else
	{
		DestX = 8;
	}

	while (NpcIndex.x != DestX)
	{
		NpcIndex.x -= 1;
		AddMovePoint(Fieldmap::GetPos(NpcIndex));
	}

	for (size_t i = 0; i < 3; i++)
	{
		NpcIndex.y += 1;
		AddMovePoint(Fieldmap::GetPos(NpcIndex));
	}

	while (NpcIndex.x != PlayerIndex.x)
	{
		if (NpcIndex.x < PlayerIndex.x)
		{
			NpcIndex += 1;
		}
		else
		{
			NpcIndex -= 1;
		}

		AddMovePoint(Fieldmap::GetPos(NpcIndex));
	}
	SetBaseDir(LookDir::Up);

	IsBlockMove = true;
}

void GreenNPC::IdleUpdate(float _DeltaTime)
{
	if (false == NPCRender->IsUpdate())
	{
		return;
	}

	if (0.0f < WaitTime)
	{
		WaitTime -= _DeltaTime;
		return;
	}
	if (true == PokemonScript::IsScriptEnd(200))
	{
		if (MovePoints.size() == 0 && true == IsBattleEnd)
		{
			NPCRender->Off();
			Fieldmap::SetWalkable(CityName, Fieldmap::GetIndex(GetPos()), true);
		}
	}
	else if (true == PokemonScript::IsScriptEnd(150))
	{
		if (true == IsBlockMove && MovePoints.size() == 0)
		{
			ChangeState(NPCState::interaction);

			PokemonScript::EndScript(200);
		}

		ScriptKey = 2;
	}
	else if (true == PokemonScript::IsScriptEnd(100))
	{
		ScriptKey = 1;

		if (IsSelectMove == false)
		{
			InputHandle = InputControll::UseControll();

			int2 NpcIndex = Fieldmap::GetIndex(GetPos());
			int2 PokeballPos = StartingPokeball::StaticRivalMovelIndex;

			WaitTime = 2.0f;

			for (size_t i = 0; i < 2; i++)
			{
				NpcIndex.y -= 1;
				AddMovePoint(Fieldmap::GetPos(NpcIndex));
			}

			while (NpcIndex.x != PokeballPos.x)
			{
				NpcIndex.x += 1;
				AddMovePoint(Fieldmap::GetPos(NpcIndex));
			}

			NpcIndex.y -= 1;
			AddMovePoint(Fieldmap::GetPos(NpcIndex));

			IsSelectMove = true;
			SetBaseDir(LookDir::Up);
			return;
		}

		if (true == IsSelectMove && MovePoints.size() == 0)
		{
			ChangeState(NPCState::interaction);
			SetInteractionTrigger(InteractionTriggerType::None);
			PokemonScript::EndScript(150);
			StartingPokeball::StaticRivalPokeball->RenderOff();
		}
	}
	else
	{
		ScriptKey = 0;
		SetInteractionTrigger(InteractionTriggerType::Talk);
	}

	StaticNPC::IdleUpdate(_DeltaTime);
}

void GreenNPC::InteractionEnd()
{
	StaticNPC::InteractionEnd();
}
