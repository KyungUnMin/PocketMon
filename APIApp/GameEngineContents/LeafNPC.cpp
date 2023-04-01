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

void LeafNPC::InteractionEnd()
{
	FieldmapLevel::AddLevelStartFunc(std::bind([](LeafNPC* _this)
		{
			_this->NPCRender->Off();
			Fieldmap::SetWalkable(_this->CityName, Fieldmap::GetIndex(_this->GetPos()), true);
		}, this));


	StaticNPC::InteractionEnd();
}
