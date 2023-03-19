#include "FieldData.h"
#include <GameEngineBase/GameEngineDebug.h>

FieldData::FieldData()
{
}

FieldData::~FieldData()
{
}

void FieldData::Init(const int2& _Size)
{
	TileSizeX = _Size.x;
	TileSizeY = _Size.y;

	TileDatas.reserve(TileSizeY);

	for (size_t y = 0; y < TileSizeY; y++)
	{
		std::vector<TileData> DatasX;
		DatasX.reserve(TileSizeX);

		for (size_t x = 0; x < TileSizeX; x++)
		{
			TileData NewData = TileData();
			DatasX.push_back(NewData);
		}

		TileDatas.push_back(DatasX);
	}
}

bool FieldData::Walkabal(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return true;
	}

	return TileWalkType::Walk == TileDatas[_Index.y][_Index.x].WalkType;
}

bool FieldData::Swinable(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return false;
	}

	return TileWalkType::Swim == TileDatas[_Index.y][_Index.x].WalkType;
}

GroundType FieldData::GetGroundType(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return GroundType::Unknown;
	}

	return TileDatas[_Index.y][_Index.x].groundType;
}

void FieldData::SetRenderData(const int2& _Index, int _RenderFrame)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 밖의 데이터를 수정하려했습니다.");
	}

	TileDatas[_Index.y][_Index.x].RenderIndex = _RenderFrame;
}

void FieldData::SetWalkData(const int2& _Index, TileWalkType _WalkData)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 밖의 데이터를 수정하려했습니다.");
	}

	TileDatas[_Index.y][_Index.x].WalkType = _WalkData;
}

void FieldData::SetGroundData(const int2& _Index, GroundType _GroundData)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 밖의 데이터를 수정하려했습니다.");
	}

	TileDatas[_Index.y][_Index.x].groundType = _GroundData;
}

int FieldData::GetRenderFrame(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return 0;
	}

	return TileDatas[_Index.y][_Index.x].RenderIndex;
}

bool FieldData::OverlapCheck(const int2& _Index) const
{
	if (0 > _Index.x || _Index.x >= TileSizeX ||
		0 > _Index.y || _Index.y >= TileSizeY)
	{
		return true;
	}

	return false;
}
