#include "GreenNPC.h"
#include "PokemonScript.h"
#include "Fieldmap.h"
#include "Player.h"
#include "FieldmapLevel.h"

GreenNPC::GreenNPC()
{
}

GreenNPC::~GreenNPC()
{
}

void GreenNPC::IdleUpdate(float _DeltaTime)
{
	if (false == NPCRender->IsUpdate())
	{
		return;
	}

	if (true == PokemonScript::IsScriptEnd(200))
	{
		if (true == IsPlay && MovePoints.size() == 0)
		{
			NPCRender->Off();
			Fieldmap::SetWalkable(CityName, Fieldmap::GetIndex(GetPos()), true);
		}

		if (false == IsPlay && IsOut == false)
		{
			FieldmapLevel::AddLevelStartFunc(std::bind([](GreenNPC* _this)
				{
					int2 CurIndex = Fieldmap::GetIndex(_this->GetPos());

					for (size_t i = 0; i < 2; i++)
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

					_this->IsPlay = true;
				}, this));

			IsOut = true;
		}
	}
	else if (true == PokemonScript::IsScriptEnd(100))
	{
		if (0 == PokemonDatas.GetPokemonCount())
		{
			PokemonDatas.AddPokemon(static_cast<int>(PokeNumber::Squirtle) + 1, 5);

			ScriptKey = 1;
			LookDistance = 2;
			SetBaseDir(LookDir::Left);
			SetInteractionTrigger(InteractionTriggerType::Look);
		}

		ScriptKey = 1;
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
	if (1 == ScriptKey)
	{
		PokemonScript::EndScript(200);
	}

	StaticNPC::InteractionEnd();
}
