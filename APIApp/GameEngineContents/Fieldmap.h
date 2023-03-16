#pragma once
#include <vector>
#include <GameEngineBase/GameEngineMath.h>
#include "int2.h"

class Fieldmap
{
public:
	static bool Walkable()
	{
		return true;
	}

	static float4 GetPos(const int _x, const int _y)
	{
		return GetPos(int2(_x, _y));
	}

	static float4 GetPos(const int2& _Index)
	{
		return float4(0.0f, 0.0f);
	}

	static int2 GetIndex(const float _x, const float _y)
	{
		return GetIndex(float4(_x, _y));
	}

	static int2 GetIndex(const float4& _Pos)
	{
		return int2(0, 0);
	}
private:
	static Fieldmap* CurFieldmapLevel;
	std::vector<Fieldmap*> CreateFieldmaps;

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