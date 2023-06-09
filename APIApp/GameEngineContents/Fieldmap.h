#pragma once
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <GameEngineBase/GameEngineMath.h>
#include "int2.h"
#include "ContentsEnum.h"
#include "FieldData.h"

class FieldmapCity;
class GameEngineActor;
class Fieldmap
{
public:
	static const float TileSize;
	static const float TileSizeHalf;
	static const float4 TileSizeFloat4Half;

	static float4 GetPos(const int _x, const int _y)
	{
		return GetPos(int2(_x, _y));
	}

	static float4 GetPos(const int2& _Index);

	static float4 GetPos(const std::string_view& _CityName, int _x, int _y)
	{
		return GetPos(_CityName, int2(_x, _y));
	}

	static float4 GetPos(const std::string_view& _CityName, const int2& _Index);

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

	static void SetWalkable(const std::string_view& _CityName, const int2& _Index, bool _Able);

	static GroundType GetGroundType(const float4& _Pos)
	{
		return GetGroundType(GetIndex(_Pos));
	}

	static GroundType GetGroundType(const int2& _Index);

	static std::string GetCityName();

	static void AddCity(const std::string_view& _CityName, FieldmapCity* _CityPtr);
	static void ChangeCity(FieldmapCity* _CityPtr, bool _PlayUI = true, bool _BgmPlay = true);
	static void ChangeCity(const std::string_view& _CityName, bool _PlayUI = true, bool _BgmPlay = true);
	static void PlayCityBGM();

	static void AddStartEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter);
	static void AddUpdateEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter);
	static void AddEndEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter);

	static void StartEventCheck(const int2& _Index);
	static void UpdateEventCheck(const int2& _Index);
	static void EndEventCheck(const int2& _Index);

	static size_t GetEventCount(const int2& _Index);
	static void ShowEventLog(const int2& _Index);

	static void AddActor(const std::string_view& _CityName, const int2& _Index, GameEngineActor* _Actor, bool _Walkalbe = true);
	static void AddFlowerActors(const std::string_view& _CityName, const std::string_view& _FlowerImageName);
	static void LinkNeighbor(const std::string_view& _CityNameA, const std::string_view& _CityNameB);

	static void FieldUpdate();
	

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