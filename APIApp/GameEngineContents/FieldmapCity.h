#pragma once
#include <string>
#include <list>
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"
#include "FieldData.h"

class GameEngineRender;
class GameEngineImage;
class FieldmapCity : public GameEngineActor
{
public:
	FieldmapCity();
	~FieldmapCity();

	FieldmapCity(const FieldmapCity& _Other) = delete;
	FieldmapCity(FieldmapCity&& _Other) noexcept = delete;
	FieldmapCity& operator=(const FieldmapCity& _Other) = delete;
	FieldmapCity& operator=(FieldmapCity&& _Other) noexcept = delete;

	void InitPos(const float4& _CityPos);

	inline float4 GetCityStartPos() const
	{
		return CityPos;
	}

	// .bmp 빼고 입력
	void InitFieldRender(const std::string_view& _CityName, const std::string_view& _UIName, const std::string_view& _ImageName, const std::string_view& _BgmName = "");

	void SetWalkable(const int2& _Index, bool _Able)
	{
		MyTilemapData.SetWalkable(_Index, _Able);
	}

	bool Walkable(const int2& _Index) const
	{
		return MyTilemapData.Walkabal(_Index);
	}

	GroundType GetGroundType(const int2& _Index) const
	{
		return MyTilemapData.GetGroundType(_Index);
	}

	inline void AddStartEvent(const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
	{
		MyTilemapData.AddStartEvent(_Index, _Parameter);
	}

	inline void AddUpdateEvent(const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
	{
		MyTilemapData.AddUpdateEvent(_Index, _Parameter);
	}

	inline void AddEndEvent(const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
	{
		MyTilemapData.AddEndEvent(_Index, _Parameter);
	}

	inline void StartEventCheck(const int2& _Index)
	{
		MyTilemapData.StartEventCheck(_Index);
	}

	inline void UpdateEventCheck(const int2& _Index)
	{
		MyTilemapData.UpdateEventCheck(_Index);
	}

	inline void EndEventCheck(const int2& _Index)
	{
		MyTilemapData.EndEventCheck(_Index);
	}

	inline size_t GetEventCount(const int2& _Index) const
	{
		return MyTilemapData.GetEventCount(_Index);
	}

	inline void ShowEventLog(const int2& _Index) const
	{
		return MyTilemapData.ShowEventLog(_Index);
	}

	inline std::string GetCityName() const
	{
		return CityName;
	}

	inline std::string GetUICityName() const
	{
		return UICityName;
	}

	inline std::string GetBgmName() const
	{
		return BgmName;
	}

	// 인덱스 중복체크를 안하기 때문에 주의해서 사용
	void AddActor(const int2& _Index, GameEngineActor* _Actor);
	void AddFlowerActors(const std::string_view& _FlowerImageName);
	void AddNeighbor(FieldmapCity* _NeighborCityPtr);

	void CityColUpdate();
	void CityActiveUpdate();

	void ActiveCity();
	void DisableCity();

protected:

private:
	std::string CityName;
	std::string UICityName;
	std::string BgmName = "";

	bool CityActive = false;
	bool NeighborActive = false;

	std::vector<GameEngineActor*> CityActors;
	std::vector<FieldmapCity*> NeighborCitys;

	GameEngineRender* CityRenderer = nullptr;
	GameEngineRender* CityFrontRenderer = nullptr;
	GameEngineImage* CityColImage = nullptr;
	GameEngineImage* CityTypeImage = nullptr;

	FieldData MyTilemapData = FieldData();;

	float4 CityPos = float4::Zero;
	float4 CityScale = float4::Zero;
};