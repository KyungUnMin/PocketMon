#include "Fieldmap.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineCore/GameEngineActor.h>
#include "FieldData.h"
#include "FieldmapCity.h"
#include "ContentsEnum.h"
#include "CityNameUI.h"

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
		MsgAssert("���� �ʵ���� �ʱ�ȭ���� �ʾҽ��ϴ�");
	}

	return float4(_Index.x * TileSize, _Index.y * TileSize) + CurCity->GetCityStartPos() + TileSizeFloat4Half;
}

float4 Fieldmap::GetPos(const std::string_view& _CityName, const int2& _Index)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	std::map<std::string, FieldmapCity*>::iterator FindIter = AllCitys.find(UpperName);

	if (FindIter == AllCitys.end())
	{
		MsgAssert("�������� �ʴ� �ʵ�� ��Ƽ�� ��ġ���� �޾ƿ��� �߽��ϴ�.");
		return float4::Zero;
	}

	return float4(_Index.x * TileSize, _Index.y * TileSize) + FindIter->second->GetCityStartPos() + TileSizeFloat4Half;
}

int2 Fieldmap::GetIndex(const float4& _Pos)
{
	if (nullptr == CurCity)
	{
		MsgAssert("���� �ʵ���� �ʱ�ȭ���� �ʾҽ��ϴ�");
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
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
		return false;
	}

	return CurCity->Walkable(_Index);
}

void Fieldmap::SetWalkable(const std::string_view& _CityName, const int2& _Index, bool _Able)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�ش� �ʵ�� ��Ƽ�� �������� �ʽ��ϴ�.");
	}

	AllCitys[UpperName]->SetWalkable(_Index, _Able);
}

GroundType Fieldmap::GetGroundType(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
	}

	return CurCity->GetGroundType(_Index);
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

void Fieldmap::ChangeCity(FieldmapCity* _CityPtr)
{
	if (CurCity == _CityPtr)
	{
		return;
	}

	if (nullptr == _CityPtr)
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}
	
	if (nullptr != CurCity)
	{
		CurCity->DisableCity();
	}

	CurCity = _CityPtr;
	CurCity->ActiveCity();

	for (const std::pair<std::string, FieldmapCity*>& CityRef : AllCitys)
	{
		CityRef.second->CityActiveUpdate();
	}

	CityNameUI::FieldmapCityNameUI->PlayText(CurCity->GetUICityName());
}

void Fieldmap::ChangeCity(const std::string_view& _CityName)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}

	ChangeCity(AllCitys[UpperName]);
}

void Fieldmap::AddStartEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}

	AllCitys[UpperName]->AddStartEvent(_Index, _Parameter);
}

void Fieldmap::AddUpdateEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}

	AllCitys[UpperName]->AddUpdateEvent(_Index, _Parameter);
}

void Fieldmap::AddEndEvent(const std::string_view& _CityName, const int2& _Index, const FieldData::FieldEventParameter& _Parameter)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}

	AllCitys[UpperName]->AddEndEvent(_Index, _Parameter);
}
void Fieldmap::StartEventCheck(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
	}

	CurCity->StartEventCheck(_Index);
}

void Fieldmap::UpdateEventCheck(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
	}

	CurCity->UpdateEventCheck(_Index);
}

void Fieldmap::EndEventCheck(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
	}

	CurCity->EndEventCheck(_Index);
}

size_t Fieldmap::GetEventCount(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
	}
	
	return CurCity->GetEventCount(_Index);
}

void Fieldmap::ShowEventLog(const int2& _Index)
{
	if (nullptr == CurCity)
	{
		MsgAssert("�ʵ�� �����͸� �������� �ʰ� ����Ϸ� �߽��ϴ�.");
	}

	CurCity->ShowEventLog(_Index);
}

void Fieldmap::AddActor(const std::string_view& _CityName, const int2& _Index, GameEngineActor* _Actor, bool _Walkalbe)
{
	if (nullptr == _Actor)
	{
		MsgAssert("�ʵ�� ��Ƽ�� nullptr ���͸� ����Ϸ� �߽��ϴ�");
		return;
	}

	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
	}

	FieldmapCity* FindCity = AllCitys[UpperName];
	FindCity->AddActor(_Index, _Actor);

	if (false == _Walkalbe)
	{
		FindCity->SetWalkable(_Index, false);
	}
}

void Fieldmap::AddFlowerActors(const std::string_view& _CityName, const std::string_view& _FlowerImageName)
{
	std::string UpperName = GameEngineString::ToUpper(_CityName);

	if (AllCitys.end() == AllCitys.find(UpperName))
	{
		MsgAssert("�������� ���� �ʵ�� ��Ƽ�� ����Ϸ� �߽��ϴ�.");
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
		MsgAssert(std::string(_CityNameA.data()) + "�ش� �̸��� ��Ƽ�� �������� �ʾ��ϴ�");
	}

	if (nullptr == CityBPtr)
	{
		MsgAssert(std::string(_CityNameB.data()) + "�ش� �̸��� ��Ƽ�� �������� �ʾ��ϴ�");
	}

	CityAPtr->AddNeighbor(CityBPtr);
	CityBPtr->AddNeighbor(CityAPtr);
}

void Fieldmap::FieldUpdate()
{
	for (const std::pair<std::string, FieldmapCity*>& CityRef : AllCitys)
	{
		CityRef.second->CityColUpdate();
	}

	for (const std::pair<std::string, FieldmapCity*>& CityRef : AllCitys)
	{
		CityRef.second->CityActiveUpdate();
	}
}