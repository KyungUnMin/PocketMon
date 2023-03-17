#pragma once
#include <vector>
#include <GameEngineBase/GameEngineMath.h>
#include "int2.h"

class Fieldmap
{
public:
	static const float TileSize;
	static const float TileSizeHalf;

	static bool Walkable(const float4& _Pos)
	{
		return true;
	}

	static bool Walkable(const int2& _Index)
	{
		return true;
	}

	static float4 GetPos(const int _x, const int _y)
	{
		return GetPos(int2(_x, _y));
	}

	static float4 GetPos(const int2& _Index)
	{
		return float4(_Index.x * TileSize, _Index.y * TileSize);
	}

	static void CalRenderStartPos(float4& _Pos)
	{
		_Pos.x = TileSize * static_cast<int>(_Pos.x / TileSize);
		_Pos.y = TileSize * static_cast<int>(_Pos.y / TileSize);
	}

	static int2 GetIndex(const float _x, const float _y)
	{
		return GetIndex(float4(_x, _y));
	}

	static int2 GetIndex(const float4& _Pos);

private:
	static Fieldmap* CurFieldmapLevel;

public:
	Fieldmap();
	~Fieldmap();

	Fieldmap(const Fieldmap& _Other) = delete;
	Fieldmap(Fieldmap&& _Other) noexcept = delete;
	Fieldmap& operator=(const Fieldmap& _Other) = delete;
	Fieldmap& operator=(Fieldmap&& _Other) noexcept = delete;

protected:

private:

};