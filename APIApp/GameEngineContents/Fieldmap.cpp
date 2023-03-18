#include "Fieldmap.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineBase/GameEngineString.h>
#include "FieldData.h"
#include "FieldmapCity.h"
#include "ContentsEnum.h"

const float Fieldmap::TileSize = 64.0f;
const float Fieldmap::TileSizeHalf = 32.0f;

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
		MsgAssert("���� �ʵ���� �ʱ�ȭ���� �ʾҽ��ϴ�");
	}

	return float4(_Index.x * TileSize, _Index.y * TileSize) + CurCity->GetCityStartPos();
}

int2 Fieldmap::GetIndex(const float4& _Pos)
{
	if (nullptr == CurCity)
	{
		MsgAssert("���� �ʵ���� �ʱ�ȭ���� �ʾҽ��ϴ�");
	}

	float4 CityStartPos = CurCity->GetCityStartPos();
	int2 ResultIndex = { 0, 0 };

	float PosX = _Pos.x + CityStartPos.x;
	float PosY = _Pos.y + CityStartPos.y;

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
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
		return false;
	}

	return CurCity->Walkable(_Index);
}

void Fieldmap::AddCity(const std::string_view& _CityName, FieldmapCity* _CityPtr)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() != AllCitys.find(UpperName))
	{
		MsgAssert("���� �̸��� �ʵ�� ��Ƽ�� �ߺ� �����߽��ϴ�.");
	}

	AllCitys[UpperName] = _CityPtr;
}

void Fieldmap::ChangeCity(const std::string_view& _CityName)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}

	CurCity = AllCitys[UpperName];
}
