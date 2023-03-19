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

	// .bmp »©°í ÀÔ·Â
	void InitFieldRender(const std::string_view& _CityName, const std::string_view& _ImageName);

	bool Walkable(const int2& _Index) const
	{
		return MyTilemapData.Walkabal(_Index);
	}

	GroundType GetGroundType(const int2& _Index) const
	{
		return MyTilemapData.GetGroundType(_Index);
	}

protected:
	void Update(float _DeltaTime) override;

private:
	std::string CityName;

	GameEngineRender* CityRenderer = nullptr;
	GameEngineImage* CityColImage = nullptr;
	GameEngineImage* CityTypeImage = nullptr;

	FieldData MyTilemapData = FieldData();;

	float4 CityPos = float4::Zero;
	float4 CityScale = float4::Zero;
};