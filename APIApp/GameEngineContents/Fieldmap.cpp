#include "Fieldmap.h"

const float Fieldmap::TileSize = 64.0f;
const float Fieldmap::TileSizeHalf = 32.0f;
Fieldmap* Fieldmap::CurFieldmapLevel = nullptr;

Fieldmap::Fieldmap()
{
}

Fieldmap::~Fieldmap()
{
}
