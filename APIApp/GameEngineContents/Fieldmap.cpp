#include "Fieldmap.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineBase/GameEngineString.h>
#include "FieldData.h"
#include "FieldmapCity.h"
#include "ContentsEnum.h"

const float Fieldmap::TileSize = 64.0f;
const float Fieldmap::TileSizeHalf = 32.0f;
const float4 Fieldmap::TileSizeFloat4Half = { TileSizeHalf, TileSizeHalf };

FieldmapCity* Fieldmap::CurCity = nullptr;
std::map<std::string, FieldmapCity*> Fieldmap::AllCitys;

Fieldmap::Fieldmap()
{
}

Fieldmap::~Fieldmap()
{
}

float4 Fieldmap::GetPos(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("아직 필드맵이 초기화되지 않았습니다");
	}

	return float4(_Index.x * TileSize, _Index.y * TileSize) + CurCity->GetCityStartPos() + TileSizeFloat4Half;
}

int2 Fieldmap::GetIndex(const float4& _Pos)
{
	if (nullptr == CurCity)
	{
		MsgAssert("아직 필드맵이 초기화되지 않았습니다");
	}

	float4 CityStartPos = CurCity->GetCityStartPos();
	int2 ResultIndex = { 0, 0 };

	float PosX = _Pos.x - CityStartPos.x;
	float PosY = _Pos.y - CityStartPos.y;

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

bool Fieldmap::Walkable(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려 했습니다.");
		return false;
	}

	return CurCity->Walkable(_Index);
}

GroundType Fieldmap::GetGroundType(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려 했습니다.");
	}

	return CurCity->GetGroundType(_Index);
}

void Fieldmap::AddCity(const std::string_view& _CityName, FieldmapCity* _CityPtr)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() != AllCitys.find(UpperName))
	{
		MsgAssert("같은 이름의 필드맵 시티를 중복 생성했습니다.");
	}

	AllCitys[UpperName] = _CityPtr;
}

void Fieldmap::ChangeCity(const std::string_view& _CityName)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("생성하지 않은 필드맵 시티를 사용하려 했습니다.");
	}

	CurCity = AllCitys[UpperName];
}

void Fieldmap::AddEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("생성하지 않은 필드맵 시티를 사용하려 했습니다.");
	}

	AllCitys[UpperName]->AddEvent(_Index, _Parameter);
}

void Fieldmap::EventCheck(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려 했습니다.");
	}

	CurCity->EventCheck(_Index);
}

size_t Fieldmap::GetEventCount(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려 했습니다.");
	}
	
	return CurCity->GetEventCount(_Index);
}

void Fieldmap::ShowEventLog(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("필드맵 데이터를 설정하지 않고 사용하려 했습니다.");
	}

	CurCity->ShowEventLog(_Index);
}