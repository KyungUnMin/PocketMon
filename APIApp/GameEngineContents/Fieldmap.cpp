#include "Fieldmap.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "FieldData.h"
#include "ContentsEnum.h"

const float Fieldmap::TileSize = 64.0f;
const float Fieldmap::TileSizeHalf = 32.0f;
FieldData* Fieldmap::CurFieldData = nullptr;
std::map<std::string, FieldData*> Fieldmap::FieldList;

Fieldmap Fieldmap::DeleteObject = Fieldmap();

Fieldmap::Fieldmap()
{
}

Fieldmap::~Fieldmap()
{
	std::map<std::string, FieldData*>::iterator LoopIter = FieldList.begin();
	std::map<std::string, FieldData*>::iterator EndIter = FieldList.end();

	while (LoopIter != EndIter)
	{
		if (nullptr != LoopIter->second)
		{
			delete LoopIter->second;
		}

		++LoopIter;
	}

	FieldList.clear();
}

int2 Fieldmap::GetIndex(const float4& _Pos)
{
	int2 ResultIndex = { 0, 0 };

	float PosX = _Pos.x;
	float PosY = _Pos.y;

	if (PosX < 0)
	{
		float DiffX = (PosX - static_cast<int>(PosX));

		if (DiffX != 0.0f)
		{
			PosX -= TileSize - DiffX;
		}
	}

	if (PosY < 0)
	{
		float DiffY = (PosY - static_cast<int>(PosY));

		if (DiffY != 0.0f)
		{
			PosY -= TileSize - DiffY;
		}
	}

	float CountX = PosX / TileSize;
	float CountY = PosY / TileSize;

	ResultIndex.x = static_cast<int>(CountX);
	ResultIndex.y = static_cast<int>(CountY);

	return ResultIndex;
}

int Fieldmap::GetRenderFrame(const int2& _Index)
{
	if (nullptr == CurFieldData)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려했습니다.");
	}

	return CurFieldData->GetRenderFrame(_Index);
}

bool Fieldmap::Walkable(const int2& _Index)
{
	if (nullptr == CurFieldData)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려 했습니다.");
		return false;
	}

	return CurFieldData->Walkabal(_Index);
}

bool Fieldmap::AddFieldData(std::string _FieldName, std::string _FileName)
{
	if (FieldList.end() != FieldList.find(_FieldName))
	{
		MsgAssert("같은 이름의 필드 데이터를 중복 생성했습니다.");
		return false;
	}

	FieldData* NewData = new FieldData(int2(30, 30));

	for (size_t y = 0; y < NewData->GetSizeY(); y++)
	{
		for (size_t x = 0; x < NewData->GetSizeX(); x++)
		{
			NewData->SetWalkData(int2{static_cast<int>(x), static_cast<int>(y)}, FieldData::TileWalkType::Walk);
			NewData->SetRenderData(int2{ static_cast<int>(x), static_cast<int>(y) }, 1);
		}
	}

	NewData->SetWalkData(int2{ 1, 1 }, FieldData::TileWalkType::Unwalk);
	NewData->SetRenderData(int2{ 1, 1 }, 0);
	NewData->SetWalkData(int2{ 0, 5 }, FieldData::TileWalkType::Unwalk);
	NewData->SetRenderData(int2{0, 5}, 0);
	NewData->SetWalkData(int2{ 5, 0 }, FieldData::TileWalkType::Unwalk);
	NewData->SetRenderData(int2{5, 0}, 0);
	NewData->SetWalkData(int2{ 8, 0 }, FieldData::TileWalkType::Swim);
	NewData->SetRenderData(int2{8, 0}, 10);
	NewData->SetWalkData(int2{ 9, 0 }, FieldData::TileWalkType::Swim);
	NewData->SetRenderData(int2{9, 0}, 10);

	FieldList[_FieldName] = NewData;
	return true;
}

bool Fieldmap::ChangeField(std::string _FieldName)
{
	if (FieldList.end() == FieldList.find(_FieldName))
	{
		MsgAssert("생성하지 않은 필드를 사용하려 했습니다.");
		return false;
	}

	CurFieldData = FieldList[_FieldName];
	return true;
}
