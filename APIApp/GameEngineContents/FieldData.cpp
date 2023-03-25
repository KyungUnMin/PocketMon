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

	return TileWalkType::Walk == TileDatas[_Index.y][_Index.x].WalkType && TileDatas[_Index.y][_Index.x].IsWalkalbe;
}

bool FieldData::Swinable(const int2& _Index) const
{
	if (true == OverlapCheck(_Index))
	{
		return false;
	}

	return TileWalkType::Swim == TileDatas[_Index.y][_Index.x].WalkType && TileDatas[_Index.y][_Index.x].IsWalkalbe;
}

void FieldData::AddStartEvent(const int2& _Index, const FieldEventParameter& _EventParameter)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("�ʵ�� ��Ƽ �ε��� �ۿ� �̺�Ʈ�� �����Ϸ� �߽��ϴ�");
	}

	AddEvent(TileDatas[_Index.y][_Index.x].StartEvents, _EventParameter);
}

void FieldData::AddUpdateEvent(const int2& _Index, const FieldEventParameter& _EventParameter)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("�ʵ�� ��Ƽ �ε��� �ۿ� �̺�Ʈ�� �����Ϸ� �߽��ϴ�");
	}

	AddEvent(TileDatas[_Index.y][_Index.x].UpdateEvents, _EventParameter);
}

void FieldData::AddEndEvent(const int2& _Index, const FieldEventParameter& _EventParameter)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("�ʵ�� ��Ƽ �ε��� �ۿ� �̺�Ʈ�� �����Ϸ� �߽��ϴ�");
	}

	AddEvent(TileDatas[_Index.y][_Index.x].EndEvents, _EventParameter);
}

void FieldData::StartEventCheck(const int2& _Index)
{
	if (true == OverlapCheck(_Index))
	{
		return;
	}

	CheckEvent(TileDatas[_Index.y][_Index.x].StartEvents);
}

void FieldData::UpdateEventCheck(const int2& _Index)
{
	if (true == OverlapCheck(_Index))
	{
		return;
	}

	CheckEvent(TileDatas[_Index.y][_Index.x].UpdateEvents);
}

void FieldData::EndEventCheck(const int2& _Index)
{
	if (true == OverlapCheck(_Index))
	{
		return;
	}

	CheckEvent(TileDatas[_Index.y][_Index.x].EndEvents);
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
		MsgAssert("�ʵ�� ���� �����͸� �����Ϸ��߽��ϴ�.");
	}

	TileDatas[_Index.y][_Index.x].RenderIndex = _RenderFrame;
}

void FieldData::SetWalkType(const int2& _Index, TileWalkType _WalkData)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("�ʵ�� ���� �����͸� �����Ϸ��߽��ϴ�.");
	}

	TileDatas[_Index.y][_Index.x].WalkType = _WalkData;
}

void FieldData::SetWalkable(const int2& _Index, bool _Able)
{
	if (true == OverlapCheck(_Index))
	{
		return;
	}

	TileDatas[_Index.y][_Index.x].IsWalkalbe = _Able;
}

void FieldData::SetGroundData(const int2& _Index, GroundType _GroundData)
{
	if (true == OverlapCheck(_Index))
	{
		MsgAssert("�ʵ�� ���� �����͸� �����Ϸ��߽��ϴ�.");
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

	const TileData* TileRef = &(TileDatas[_Index.y][_Index.x]);
	size_t EventCount = TileRef->StartEvents.size();
	EventCount += TileRef->UpdateEvents.size();
	EventCount += TileRef->EndEvents.size();

	return EventCount;
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

	for (const std::pair<int, FieldEvent>& Loop : TileDatas[_Index.y][_Index.x].StartEvents)
	{
		Result += "Start Event : " + Loop.second.Name + "\n";
	}

	for (const std::pair<int, FieldEvent>& Loop : TileDatas[_Index.y][_Index.x].UpdateEvents)
	{
		Result += "Update Event : " + Loop.second.Name + "\n";
	}

	for (const std::pair<int, FieldEvent>& Loop : TileDatas[_Index.y][_Index.x].EndEvents)
	{
		Result += "End Event : " + Loop.second.Name + "\n";
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

void FieldData::AddEvent(std::map<int, FieldEvent>& _Events, const FieldEventParameter& _EventParameter)
{
	if (_Events.find(_EventParameter.Order) != _Events.end())
	{
		MsgAssert("���� �켱������ �ʵ�� �̺�Ʈ�� �����Ϸ� �߽��ϴ�");
	}

	std::string UpperName = GameEngineString::ToUpper(_EventParameter.Name);

	for (const std::pair<int, FieldEvent>& _Loop : _Events)
	{
		if (_Loop.second.Name == UpperName)
		{
			MsgAssert("���� �̸��� �ʵ�� �̺�Ʈ�� �����Ϸ� �߽��ϴ�");
		}
	}

	_Events[_EventParameter.Order] = FieldEvent(UpperName, _EventParameter.VaildFunc, _EventParameter.EventFunc, _EventParameter.Loop);
}

void FieldData::CheckEvent(std::map<int, FieldEvent>& _Events)
{
	std::map<int, FieldEvent>::iterator OrderLoopIter = _Events.begin();
	std::map<int, FieldEvent>::iterator OrderEndIter = _Events.end();

	while (OrderLoopIter != OrderEndIter)
	{
		FieldEvent& EventRef = (*OrderLoopIter).second;

		if (true == EventRef.EvenetVaild())
		{
			EventRef.MainEvent();

			if (false == EventRef.Loop)
			{
				OrderLoopIter = _Events.erase(OrderLoopIter);
			}

			return;
		}

		++OrderLoopIter;
	}

}
