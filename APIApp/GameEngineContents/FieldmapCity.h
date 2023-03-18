#pragma once
#include <string>
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

class GameEngineRender;
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

	void InitFieldRender(const std::string_view& _ImageName);

	bool Walkable(const int2& _Index) const
	{
		return true;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* CityRenderer = nullptr;

	float4 CityPos = float4::Zero;
};