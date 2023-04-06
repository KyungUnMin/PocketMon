#include "LeafNPC.h"
#include <GameEngineCore/GameEngineRender.h>
#include "Fieldmap.h"
#include "FieldmapLevel.h"

LeafNPC::LeafNPC()
{
}

LeafNPC::~LeafNPC()
{
}

void LeafNPC::InteractionStart()
{
	Fieldmap::SetWalkable(CityName, Fieldmap::GetIndex(GetPos()), true);
	StaticNPC::InteractionStart();
}

void LeafNPC::InteractionEnd()
{
	Fieldmap::SetWalkable(CityName, Fieldmap::GetIndex(GetPos()), true);

	FieldmapLevel::AddLevelStartFunc(std::bind([](LeafNPC* _this)
		{
			_this->NPCRender->Off();
		}, this));


	StaticNPC::InteractionEnd();
}
