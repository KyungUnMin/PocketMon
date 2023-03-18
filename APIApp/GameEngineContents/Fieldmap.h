#pragma once
#include <vector>
#include <map>
#include <string>
#include <GameEngineBase/GameEngineMath.h>
#include "int2.h"

class FieldmapCity;
class Fieldmap
{
public:
	static const float TileSize;
	static const float TileSizeHalf;

	static float4 GetPos(const int _x, const int _y)
	{
		return GetPos(int2(_x, _y));
	}

	static float4 GetPos(const int2& _Index);

	static int2 GetIndex(const float _x, const float _y)
	{
		return GetIndex(float4(_x, _y));
	}

	static int2 GetIndex(const float4& _Pos);

	static bool Walkable(const float4& _Pos)
	{
		return Walkable(GetIndex(_Pos));
	}
	
	static bool Walkable(const int2& _Index);

	static void AddCity(const std::string_view& _CityName, FieldmapCity* _CityPtr);
	static void ChangeCity(const std::string_view& _CityName);

private:
	static FieldmapCity* CurCity;
	static std::map<std::string, FieldmapCity*> AllCitys;

private:	
	Fieldmap();
	~Fieldmap();

	Fieldmap(const Fieldmap& _Other) = delete;
	Fieldmap(Fieldmap&& _Other) noexcept = delete;
	Fieldmap& operator=(const Fieldmap& _Other) = delete;
	Fieldmap& operator=(Fieldmap&& _Other) noexcept = delete;
};