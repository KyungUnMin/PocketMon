#include "FieldData.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>

FieldData::FieldData()
{
}

FieldData::~FieldData()
{
}

void FieldData::Init(const int2& _Size)
{
	TileSizeX = _Size.x;
	TileSizeY = _Size.y;

	TileDatas.reserve(TileSizeY);

	for (size_t y = 0; y < TileSizeY; y++)
	{
		std::vector<TileData> DatasX;
		DatasX.reserve(TileSizeX);

		for (size_t x = 0; x < TileSizeX; x++)
		{
			TileData NewData = TileData();
			DatasX.push_back(NewData);
		}

		TileDatas.push_back(DatasX);
	}
}

bool FieldData::Walkabal(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return true;
	}

	return TileWalkType::Walk == TileDatas[_Index.y][_Index.x].WalkType;
}

bool FieldData::Swinable(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return false;
	}

	return TileWalkType::Swim == TileDatas[_Index.y][_Index.x].WalkType;
}

void FieldData::AddEvent(const int2& _Index, const FieldEventParameter& _EventParameter)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 시티 인덱스 밖에 이벤트를 생성하려 했습니다");
	}

	std::map<int, FieldEvent>& EventListRef = TileDatas[_Index.y][_Index.x].EventList;

	if (EventListRef.find(_EventParameter.Order) != EventListRef.end())
	{
		MsgAssert("같은 우선순위의 필드맵 이벤트를 생성하려 했습니다");
	}

	std::string UpperName = GameEngineString::ToUpper(_EventParameter.Name);

	for (const std::pair<int, FieldEvent>& _Loop : EventListRef)
	{
		if (_Loop.second.Name == UpperName)
		{
			MsgAssert("같은 이름의 필드맵 이벤트를 생성하려 했습니다");
		}
	}

	EventListRef[_EventParameter.Order] = FieldEvent(UpperName, _EventParameter.VaildFunc, _EventParameter.EventFunc, _EventParameter.Loop);
}

void FieldData::EventCheck(const int2& _Index)
{
	if (true == OverlapCheck(_Index))
	{
		return;
	}

	std::map<int, FieldEvent>& OrederListRef = TileDatas[_Index.y][_Index.x].EventList;

	std::map<int, FieldEvent>::iterator OrderLoopIter = OrederListRef.begin();
	std::map<int, FieldEvent>::iterator OrderEndIter = OrederListRef.end();

	while (OrderLoopIter != OrderEndIter)
	{
		FieldEvent& EventRef = (*OrderLoopIter).second;

		if (true == EventRef.EvenetVaild())
		{
			EventRef.MainEvent();

			if (false == EventRef.Loop)
			{
				OrderLoopIter = OrederListRef.erase(OrderLoopIter);
			}

			return;
		}

		++OrderLoopIter;
	}
}

GroundType FieldData::GetGroundType(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return GroundType::Unknown;
	}

	return TileDatas[_Index.y][_Index.x].groundType;
}

void FieldData::SetRenderData(const int2& _Index, int _RenderFrame)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 밖의 데이터를 수정하려했습니다.");
	}

	TileDatas[_Index.y][_Index.x].RenderIndex = _RenderFrame;
}

void FieldData::SetWalkData(const int2& _Index, TileWalkType _WalkData)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 밖의 데이터를 수정하려했습니다.");
	}

	TileDatas[_Index.y][_Index.x].WalkType = _WalkData;
}

void FieldData::SetGroundData(const int2& _Index, GroundType _GroundData)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("필드맵 밖의 데이터를 수정하려했습니다.");
	}

	TileDatas[_Index.y][_Index.x].groundType = _GroundData;
}

int FieldData::GetRenderFrame(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return 0;
	}

	return TileDatas[_Index.y][_Index.x].RenderIndex;
}

size_t FieldData::GetEventCount(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return 0;
	}

	return TileDatas[_Index.y][_Index.x].EventList.size();
}

bool FieldData::OverlapCheck(const int2& _Index) const
{
	if (0 > _Index.x || _Index.x >= TileSizeX ||
		0 > _Index.y || _Index.y >= TileSizeY)
	{
		return true;
	}

	return false;
}

void FieldData::ShowEventLog(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		DebugMsgBox("Event Empty");
	}

	std::string Result;

	for (const std::pair<int, FieldEvent>& Loop : TileDatas[_Index.y][_Index.x].EventList)
	{
		Result += "Event : " + Loop.second.Name + "\n";
	}

	if ("" == Result)
	{
		DebugMsgBox("Event Empty");
	}
	else
	{
		DebugMsgBox(Result);
	}
}
