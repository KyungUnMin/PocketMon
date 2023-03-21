#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineBase/GameEngineTimeEvent.h>
#include "int2.h"

class GameEngineRender;
class FieldmapDoubleDoor : public GameEngineActor
{
public:
	FieldmapDoubleDoor();
	~FieldmapDoubleDoor();

	FieldmapDoubleDoor(const FieldmapDoubleDoor& _Other) = delete;
	FieldmapDoubleDoor(FieldmapDoubleDoor&& _Other) noexcept = delete;
	FieldmapDoubleDoor& operator=(const FieldmapDoubleDoor& _Other) = delete;
	FieldmapDoubleDoor& operator=(FieldmapDoubleDoor&& _Other) noexcept = delete;

	inline void SetDestCity(const std::string_view& _CityName)
	{
		DestCityName = _CityName;
	}

	inline void SetDestIndex(const int2& _Dest)
	{
		DestIndex = _Dest;
	}

	bool VaildDoor() const
	{
		return true;
	}

	void UseDoor();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void ActorMove();
	void Fade();



private:
	GameEngineTimeEvent DoorEvent;

	std::string DestCityName = "";
	int2 DestIndex = int2(0, 0);

	bool IsUse = false;

	GameEngineRender* DoorRender = nullptr;
};