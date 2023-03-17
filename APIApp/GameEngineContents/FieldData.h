#pragma once
#include <vector>
#include "ContentsEnum.h"
#include "int2.h"

class FieldData
{
public:
	enum class TileWalkType
	{
		Walk,
		Unwalk,
		Swim
	};

	class TileData
	{
	public:
		TileWalkType WalkType = TileWalkType::Walk;
		GroundType groundType = GroundType::Grass;
	};

public:
	FieldData(const int2& _Size);
	~FieldData();

	FieldData(const FieldData& _Other) = delete;
	FieldData(FieldData&& _Other) noexcept = delete;
	FieldData& operator=(const FieldData& _Other) = delete;
	FieldData& operator=(FieldData&& _Other) noexcept = delete;

protected:

private:
	std::vector<std::vector<TileData>> TileDatas;

};