#include "Fieldmap.h"

const float Fieldmap::TileSize = 64.0f;
const float Fieldmap::TileSizeHalf = 32.0f;
Fieldmap* Fieldmap::CurFieldmapLevel = nullptr;

Fieldmap::Fieldmap()
{
	if (0 == CreateFieldmaps.size())
	{
		CreateFieldmaps.resize(32);
	}

	CreateFieldmaps.push_back(this);
}

Fieldmap::~Fieldmap()
{
	std::vector<Fieldmap*>::iterator LoopIter = CreateFieldmaps.begin();
	std::vector<Fieldmap*>::iterator EndIter = CreateFieldmaps.end();

	while (LoopIter != EndIter)
	{
		if ((*LoopIter) == this)
		{
			CreateFieldmaps.erase(LoopIter);
			break;
		}
		else
		{
			++LoopIter;
		}
	}
}
