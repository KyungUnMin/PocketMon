#include "FieldData.h"

FieldData::FieldData(const int2& _Size)
{
	TileDatas.reserve(_Size.y);

	for (size_t y = 0; y < _Size.y; y++)
	{
		std::vector<TileData> DatasX;
		DatasX.reserve(_Size.x);

		for (size_t x = 0; x < _Size.x; x++)
		{
			TileData NewData = TileData();
			DatasX.push_back(NewData);
		}

		TileDatas.push_back(DatasX);
	}

}

FieldData::~FieldData()
{
}