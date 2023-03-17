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

int2 Fieldmap::GetIndex(const float4& _Pos)
{
	int2 ResultIndex = { 0, 0 };

	float PosX = _Pos.x;
	float PosY = _Pos.y;

	if (PosX < 0)
	{
		float DiffX = (PosX - static_cast<int>(PosX));

		if (DiffX != 0.0f)
		{
			PosX -= TileSize - DiffX;
		}
	}

	if (PosY < 0)
	{
		float DiffY = (PosY - static_cast<int>(PosY));

		if (DiffY != 0.0f)
		{
			PosY -= TileSize - DiffY;
		}
	}

	float CountX = PosX / TileSize;
	float CountY = PosY / TileSize;

	ResultIndex.x = static_cast<int>(CountX);
	ResultIndex.y = static_cast<int>(CountY);

	return ResultIndex;
}
