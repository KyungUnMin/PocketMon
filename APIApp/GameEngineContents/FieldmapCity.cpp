#include "FieldmapCity.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Fieldmap.h"
#include "FieldmapLevel.h"

FieldmapCity::FieldmapCity()
{
}

FieldmapCity::~FieldmapCity()
{
}

void FieldmapCity::InitPos(const float4& _CityPos)
{
	SetPos(_CityPos);

	if (nullptr == CityRenderer)
	{
		MsgAssert("���� �ʵ�� ��Ƽ�� �������� �ʾҽ��ϴ�.");
	}

	CityPos = _CityPos - CityRenderer->GetScale().half();
}

void FieldmapCity::InitFieldRender(const std::string_view& _CityName, const std::string_view& _ImageName, const std::string_view& _ColImageName)
{
	CityName = _CityName;

	if (nullptr != CityRenderer)
	{
		MsgAssert("�ʵ�� ��Ƽ�� �ߺ� �ʱ�ȭ �߽��ϴ�");
	}

	CityRenderer = CreateRender(_ImageName, RenderOrder::Tilemap);
	CityRenderer->SetScaleToImage();

	CityColImage = GameEngineResources::GetInst().ImageFind(_ColImageName);

	CityScale = CityRenderer->GetImage()->GetImageScale();

	float TileSize = Fieldmap::TileSize;

	int TileSizeX = static_cast<int>(CityScale.x / TileSize);
	int TileSizeY = static_cast<int>(CityScale.y / TileSize);

	MyTilemapData.Init(int2(TileSizeX, TileSizeY));

	float4 CheckPos = float4::Zero;

	for (int y = 0; y < TileSizeY; y++)
	{
		for (int x = 0; x < TileSizeX; x++)
		{
			CheckPos.x = x * TileSize;
			CheckPos.y = y * TileSize;

			if (RGB(0, 0, 0) != CityColImage->GetPixelColor(CheckPos.ix(), CheckPos.iy(), RGB(0, 0, 0)))
			{
				MyTilemapData.SetWalkData(int2(x, y), FieldData::TileWalkType::Walk);
			}
			else
			{
				MyTilemapData.SetWalkData(int2(x, y), FieldData::TileWalkType::Unwalk);
			}
		}
	}

	Fieldmap::AddCity(CityName, this);
}

void FieldmapCity::Update(float _DeltaTime)
{
	float4 PlayerPos = FieldmapLevel::GetPlayerPos();

	if (true == GameEngineCollision::CollisionRectToPoint(
		CollisionData(GetPos(), CityScale), CollisionData(PlayerPos)))
	{
		CityRenderer->On();
		Fieldmap::ChangeCity(CityName);
	}
	else
	{
		CityRenderer->Off();
	}
}