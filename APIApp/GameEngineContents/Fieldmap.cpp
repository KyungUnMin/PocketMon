#include "Fieldmap.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineCore/GameEngineActor.h>
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

float4 Fieldmap::GetPos(const std::string_view& _CityName, const int2& _Index)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	std::map<std::string, FieldmapCity*>::iterator FindIter = AllCitys.find(UpperName);

	if (FindIter == AllCitys.end())
	{
		MsgAssert("존재하지 않는 필드맵 시티의 위치값을 받아오려 했습니다.");
		return float4::Zero;
	}

	return float4(_Index.x * TileSize, _Index.y * TileSize) + FindIter->second->GetCityStartPos() + TileSizeFloat4Half;
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

void Fieldmap::SetWalkable(const std::string_view& _CityName, const int2& _Index, bool _Able)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() != AllCitys.find(UpperName))
	{
		MsgAssert("같은 이름의 필드맵 시티를 중복 생성했습니다.");
	}

	AllCitys[UpperName]->SetWalkable(_Index, _Able);
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

void Fieldmap::ChangeCity(FieldmapCity* _CityPtr)
{
	if (nullptr == _CityPtr)
	{
		MsgAssert("생성하지 않은 필드맵 시티를 사용하려 했습니다.");
	}
	
	CurCity = _CityPtr;
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

void Fieldmap::AddActor(const std::string_view& _CityName, const int2& _Index, GameEngineActor* _Actor)
{
	if (nullptr == _Actor)
	{
		MsgAssert("필드맵 시티에 nullptr 액터를 등록하려 했습니다");
		return;
	}

	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("생성하지 않은 필드맵 시티를 사용하려 했습니다.");
	}

	AllCitys[UpperName]->AddActor(_Index, _Actor);
}

void Fieldmap::AddFlowerActors(const std::string_view& _CityName, const std::string_view& _FlowerImageName)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("생성하지 않은 필드맵 시티를 사용하려 했습니다.");
	}

	AllCitys[UpperName]->AddFlowerActors(_FlowerImageName);
}

void Fieldmap::LinkNeighbor(const std::string_view& _CityNameA, const std::string_view& _CityNameB)
{
	std::string CityAUpper = GameEngineString::ToUpper(_CityNameA);
	std::string CityBUpper = GameEngineString::ToUpper(_CityNameB);

	FieldmapCity* CityAPtr = AllCitys[CityAUpper];
	FieldmapCity* CityBPtr = AllCitys[CityBUpper];

	if (nullptr == CityAPtr)
	{
		MsgAssert(std::string(_CityNameA.data()) + "해당 이름의 시티가 존재하지 않씁니다");
	}

	if (nullptr == CityBPtr)
	{
		MsgAssert(std::string(_CityNameB.data()) + "해당 이름의 시티가 존재하지 않씁니다");
	}

	CityAPtr->AddNeighbor(CityBPtr);
	CityBPtr->AddNeighbor(CityAPtr);
}