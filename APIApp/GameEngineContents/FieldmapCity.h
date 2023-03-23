#pragma once
#include <string>
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
	void InitFieldRender(const std::string_view& _CityName, const std::string_view& _ImageName);

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

	inline void AddEvent(const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
	{
		MyTilemapData.AddEvent(_Index, _Parameter);
	}

	inline void EventCheck(const int2& _Index)
	{
		MyTilemapData.EventCheck(_Index);
	}

	inline size_t GetEventCount(const int2& _Index) const
	{
		return MyTilemapData.GetEventCount(_Index);
	}

	inline void ShowEventLog(const int2& _Index) const
	{
		return MyTilemapData.ShowEventLog(_Index);
	}

	// 인덱스 중복체크를 안하기 때문에 주의해서 사용
	void AddActor(const int2& _Index, GameEngineActor* _Actor);
	void AddFlowerActors(const std::string_view& _FlowerImageName);
	void AddNeighbor(FieldmapCity* _NeighborCityPtr);

	void FieldmapUpdate();

protected:
	void Update(float _DeltaTime) override;

private:
	std::string CityName;

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