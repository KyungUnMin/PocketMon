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
		int RenderIndex = -1;
	};

public:
	FieldData();
	~FieldData();

	FieldData(const FieldData& _Other) = delete;
	FieldData(FieldData&& _Other) noexcept = delete;
	FieldData& operator=(const FieldData& _Other) = delete;
	FieldData& operator=(FieldData&& _Other) noexcept = delete;

	void Init(const int2& _Size);
	bool Walkabal(const int2& _Index) const;
	bool Swinable(const int2& _Index) const;
	GroundType GetGroundType(const int2& _Index) const;

	void SetRenderData(const int2& _Index, int _RenderFrame);
	void SetWalkData(const int2& _Index, TileWalkType _WalkData);
	void SetGroundData(const int2& _Index, GroundType _GroundData);

	int GetRenderFrame(const int2& _Index) const;

	size_t GetSizeX() const
	{
		return TileSizeX;
	}

	size_t GetSizeY() const
	{
		return TileSizeY;
	}

	bool OverlapCheck(const int2& _Index) const;

protected:

private:
	std::vector<std::vector<TileData>> TileDatas;

	size_t TileSizeX = 0;
	size_t TileSizeY = 0;
};