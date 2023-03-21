#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "int2.h"

class Player;
class FieldDialog;
class FieldmapRender;
class FieldMainMenu;
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
	Player* MainPlayer = nullptr;
	FieldDialog* MainFieldDialog = nullptr;
	FieldmapRender* MainFieldRender = nullptr;
	FieldMainMenu* MainFieldMainMenu = nullptr;
	bool IsCameraDebug = false;

	void UIImageLoad();

	void CreateFlower(const std::string_view& _CityName, const int2& _Index);
	void CreateSingleDoor(const std::string_view& _CityName, const int2& _Index, const std::string_view& _DestCityName, const int2& _DestIndex, const std::string_view& _EventName, int _Order = 0);
	void CreateDoubleDoor(const std::string_view& _CityName, const int2& _Index, const std::string_view& _DestCityName, const int2& _DestIndex, const std::string_view& _EventName, int _Order = 0);

	// ImageName���� .bmp�� ���� �Է�
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