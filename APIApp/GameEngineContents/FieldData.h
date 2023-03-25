#pragma once
#include <vector>
#include <map>
#include <functional>
#include "ContentsEnum.h"
#include "int2.h"

class FieldData
{
public:
	class FieldEventParameter
	{
	public:
		std::string Name = "";
		int Order = 0;
		std::function<bool()> VaildFunc = nullptr;
		std::function<void()> EventFunc = nullptr;
		bool Loop = false;
	};

private:
	class FieldEvent
	{
	public:
		std::string Name = "";
		std::function<bool()> EvenetVaild = nullptr;
		std::function<void()> MainEvent = nullptr;
		bool Loop = false;
	};
public:
	enum class TileWalkType
	{
		Walk,
		Swim
	};

	class TileData
	{
	public:
		TileWalkType WalkType = TileWalkType::Walk;
		GroundType groundType = GroundType::Grass;

		bool IsWalkalbe = false;
		int RenderIndex = -1;		
		std::map<int, FieldEvent> StartEvents;
		std::map<int, FieldEvent> UpdateEvents;
		std::map<int, FieldEvent> EndEvents;
	};

public:
	FieldData();
	~FieldData();

	FieldData(const FieldData& _Other) = delete;
	FieldData(FieldData&& _Other) noexcept = delete;
	FieldData& operator=(const FieldData& _Other) = delete;
	FieldData& operator=(FieldData&& _Other) noexcept = delete;

	void Init(const int2& _Size);
	bool Walkabal(const int2& _Index) const;
	bool Swinable(const int2& _Index) const;

	void AddStartEvent(const int2& _Index, const FieldEventParameter& _EventParameter);
	void AddUpdateEvent(const int2& _Index, const FieldEventParameter& _EventParameter);
	void AddEndEvent(const int2& _Index, const FieldEventParameter& _EventParameter);

	void StartEventCheck(const int2& _Index);
	void UpdateEventCheck(const int2& _Index);
	void EndEventCheck(const int2& _Index);

	GroundType GetGroundType(const int2& _Index) const;

	void SetRenderData(const int2& _Index, int _RenderFrame);
	void SetWalkType(const int2& _Index, TileWalkType _WalkData);
	void SetWalkable(const int2& _Index, bool _Able);
	void SetGroundData(const int2& _Index, GroundType _GroundData);

	int GetRenderFrame(const int2& _Index) const;
	size_t GetEventCount(const int2& _Index) const;
	
	size_t GetSizeX() const
	{
		return TileSizeX;
	}

	size_t GetSizeY() const
	{
		return TileSizeY;
	}

	bool OverlapCheck(const int2& _Index) const;

	void ShowEventLog(const int2& _Index) const;

protected:

private:
	std::vector<std::vector<TileData>> TileDatas;

	size_t TileSizeX = 0;
	size_t TileSizeY = 0;

	void AddEvent(std::map<int, FieldEvent>& _Events, const FieldEventParameter& _EventParameter);
	void CheckEvent(std::map<int, FieldEvent>& _Events);
};