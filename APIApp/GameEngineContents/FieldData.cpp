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

	std::vector<FieldEvent>& OrderEventList = TileDatas[_Index.y][_Index.x].EventList[_EventParameter.Order];

	std::string UpperName = GameEngineString::ToUpper(_EventParameter.Name);

	for (size_t i = 0; i < OrderEventList.size(); i++)
	{
		if (OrderEventList[i].Name == UpperName)
		{
			MsgAssert("같은 시티의 같은 필드맵 타일에 같은 오더 및 이름의 이벤트가 추가되었습니다");
			return;
		}
	}

	OrderEventList.push_back(FieldEvent(UpperName, _EventParameter.VaildFunc, _EventParameter.EventFunc, _EventParameter.Loop));
}

void FieldData::EventCheck(const int2& _Index)
{
	if (true == OverlapCheck(_Index))
	{
		return;
	}

	std::map<int, std::vector<FieldEvent>>& OrederListRef = TileDatas[_Index.y][_Index.x].EventList;

	std::map<int, std::vector<FieldEvent>>::iterator OrderLoopIter = OrederListRef.begin();
	std::map<int, std::vector<FieldEvent>>::iterator OrderEndIter = OrederListRef.end();

	while (OrderLoopIter != OrderEndIter)
	{
		std::vector<FieldEvent>& VecListRef = (*OrderLoopIter).second;

		std::vector<FieldEvent>::iterator vecLoopIter = VecListRef.begin();

		while (vecLoopIter != VecListRef.end())
		{
			if (true == vecLoopIter->EvenetVaild())
			{
				vecLoopIter->MainEvent();
			
				if (false == vecLoopIter->Loop)
				{
					vecLoopIter = VecListRef.erase(vecLoopIter);
					continue;
				}
			}

			++vecLoopIter;
		}

		if (0 == VecListRef.size())
		{
			OrderLoopIter = OrederListRef.erase(OrderLoopIter);
		}
		else
		{
			++OrderLoopIter;
		}
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

bool FieldData::OverlapCheck(const int2& _Index) const
{
	if (0 > _Index.x || _Index.x >= TileSizeX ||
		0 > _Index.y || _Index.y >= TileSizeY)
	{
		return true;
	}

	return false;
}
