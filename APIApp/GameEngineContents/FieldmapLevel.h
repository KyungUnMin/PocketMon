#pragma once
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "int2.h"
#include "DoorActorBase.h"
#include "Fieldmap.h"

class Player;
class FieldDialog;
class FieldmapRender;
class FieldMainMenu;
class MoveMapFadeEffect;
class FieldmapLevel : public GameEngineLevel
{
public:
	static float4 GetPlayerPos()
	{
		return PlayerPos;
	}
private:
	static float4 PlayerPos;
public:
	FieldmapLevel();
	~FieldmapLevel();

	FieldmapLevel(const FieldmapLevel& _Other) = delete;
	FieldmapLevel(FieldmapLevel&& _Other) noexcept = delete;
	FieldmapLevel& operator=(const FieldmapLevel& _Other) = delete;
	FieldmapLevel& operator=(FieldmapLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}
private:
	std::map<std::string, DoorActorBase*> AllDoors;

	Player* MainPlayer = nullptr;
	FieldDialog* MainFieldDialog = nullptr;
	FieldmapRender* MainFieldRender = nullptr;
	FieldMainMenu* MainFieldMainMenu = nullptr;
	MoveMapFadeEffect* MainMoveMapFadeEffect = nullptr;
	bool IsCameraDebug = false;

	void UIImageLoad();

	void CreateFlower(const std::string_view& _CityName, const int2& _Index);

	template<typename DoorClass>
	void CreateDoor(const std::string_view& _DoorName, const std::string_view& _CityName, const int2& _Index, const std::string_view& _EventName, int _Order = 0)
	{
		DoorActorBase* NewDoor = CreateActor<DoorClass>();

		std::string UpperDoorName = GameEngineString::ToUpper(_DoorName);

		NewDoor->SetDoorName(UpperDoorName);
		NewDoor->SetDoorCity(_CityName);
		NewDoor->SetDoorIndex(_Index);

		Fieldmap::AddEvent(_CityName, _Index,
			{
				.Name = _EventName.data(),
				.Order = _Order,
				.VaildFunc = std::bind(&DoorActorBase::VaildDoor, NewDoor),
				.EventFunc = std::bind(&DoorActorBase::UseDoor, NewDoor),
				.Loop = true
			});

		Fieldmap::AddActor(_CityName, _Index, NewDoor);
		AllDoors.insert(std::make_pair(UpperDoorName, NewDoor));
	}

	void LinkDoor(const std::string_view& _LinkDoorName1, const std::string_view& _LinkDoorName2);

	// ImageName에는 .bmp를 빼고 입력
	void CreateFieldmapCity(const std::string_view& _CityName, const std::string_view& _ImageName, const float4& _Pos);

	bool VaileTest() const
	{
		int b = 0;

		return true;
	}

	void EventTest1() const
	{
		DebugMsgBox("Call Event1\n");
	}

	void EventTest2() const
	{
		DebugMsgBox("Call Event2\n");
	}
};