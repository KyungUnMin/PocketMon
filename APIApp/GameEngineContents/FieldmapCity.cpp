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
	CityActors.reserve(128);
}

FieldmapCity::~FieldmapCity()
{
}

void FieldmapCity::InitPos(const float4& _CityPos)
{
	SetPos(_CityPos);

	if (nullptr == CityRenderer)
	{
		MsgAssert("아직 필드맵 시티가 생성되지 않았습니다.");
	}

	CityPos = _CityPos - CityRenderer->GetScale().half();
}

void FieldmapCity::InitFieldRender(const std::string_view& _CityName, const std::string_view& _ImageName)
{
	CityName = _CityName;

	if (nullptr != CityRenderer)
	{
		MsgAssert("필드맵 시티를 중복 초기화 했습니다");
	}

	std::string ImageName = _ImageName.data();

	CityRenderer = CreateRender(ImageName + ".bmp", RenderOrder::Tilemap);
	CityRenderer->SetScaleToImage();

	CityColImage = GameEngineResources::GetInst().ImageFind(ImageName + "_Col.bmp");
	CityTypeImage = GameEngineResources::GetInst().ImageFind(ImageName + "_Type.bmp");

	CityScale = CityRenderer->GetImage()->GetImageScale();
	CityRenderer->Off();

	float TileSize = Fieldmap::TileSize;

	int TileSizeX = static_cast<int>(CityScale.x / TileSize);
	int TileSizeY = static_cast<int>(CityScale.y / TileSize);

	MyTilemapData.Init(int2(TileSizeX, TileSizeY));

	for (int y = 0; y < TileSizeY; y++)
	{
		for (int x = 0; x < TileSizeX; x++)
		{
			int2 Index = int2(x, y);

			if (RGB(0, 0, 0) != CityColImage->GetPixelColor(x, y, RGB(0, 0, 0)))
			{
				MyTilemapData.SetWalkData(Index, FieldData::TileWalkType::Walk);
			}
			else
			{
				MyTilemapData.SetWalkData(Index, FieldData::TileWalkType::Unwalk);
			}

			DWORD TypeColor = CityTypeImage->GetPixelColor(x, y, RGB(0, 0, 0));

			switch (TypeColor)
			{
			case RGB(192, 248, 144): //  Grassc 0f890 [r] 192 [g] 248 [b] 144
				MyTilemapData.SetGroundData(Index, GroundType::Grass);
				break;
			case RGB(200, 192, 88): // Rock c8c058 [r] 200 [g] 192 [b] 88
				MyTilemapData.SetGroundData(Index, GroundType::Rock);
				break;
			case RGB(112, 184, 240): // Water 70b8f0 [r] 112 [g] 184 [b] 240
				MyTilemapData.SetGroundData(Index, GroundType::Water);
				break;
			case RGB(200, 224, 232): // Blue c8e0e8 [r] 200 [g] 224 [b] 232
				MyTilemapData.SetGroundData(Index, GroundType::Blue);
				break;
			case RGB(232, 232, 240): // Grey e8e8f0 [r] 232 [g] 232 [b] 240
				MyTilemapData.SetGroundData(Index, GroundType::Grey);
				break;
			case RGB(232, 224, 192): // Gold e8e0c0 [r] 232 [g] 224 [b] 192
				MyTilemapData.SetGroundData(Index, GroundType::Gold);
				break;
			case RGB(216, 184, 232): // Purple d8b8e8 [r] 216 [g] 184 [b] 232
				MyTilemapData.SetGroundData(Index, GroundType::Purple);
				break;
			case RGB(184, 224, 208): // Cyan b8e0d0 [r] 184 [g] 224 [b] 208
				MyTilemapData.SetGroundData(Index, GroundType::Cyan);
				break;
			case RGB(232, 232, 232): // Beige e8e8e8 [r] 232 [g] 232 [b] 232
				MyTilemapData.SetGroundData(Index, GroundType::Beige);
				break;
			default:
				MyTilemapData.SetGroundData(Index, GroundType::Unknown);
				break;
			}
		}
	}

	Fieldmap::AddCity(CityName, this);
}

void FieldmapCity::AddActor(const int2& _Index, GameEngineActor* _Actor)
{
	if (nullptr == _Actor)
	{
		MsgAssert("필드맵 시티에 nullptr 액터를 등록하려 했습니다");
		return;
	}

	if (true == MyTilemapData.OverlapCheck(_Index))
	{
		MsgAssert("필드맵 시티 범위를 초과해 액터를 등록하려 했습니다");
		return;
	}

	float TileSize = Fieldmap::TileSize;
	_Actor->SetPos(float4(_Index.x * TileSize, _Index.y * TileSize) + GetCityStartPos() + Fieldmap::TileSizeFloat4Half);

	if (true == CityActive)
	{
		_Actor->On();
	}
	else
	{
		_Actor->Off();
	}

	CityActors.push_back(_Actor);
}

void FieldmapCity::Update(float _DeltaTime)
{
	float4 PlayerPos = FieldmapLevel::GetPlayerPos();

	if (true == GameEngineCollision::CollisionRectToPoint(
		CollisionData(GetPos(), CityScale), CollisionData(PlayerPos)))
	{
		if (false == CityActive)
		{
			CityActive = true;
			CityRenderer->On();

			for (size_t i = 0; i < CityActors.size(); i++)
			{
				CityActors[i]->On();
			}

			Fieldmap::ChangeCity(CityName);
		}
	}
	else
	{
		if (true == CityActive)
		{
			CityActive = false;
			CityRenderer->Off();

			for (size_t i = 0; i < CityActors.size(); i++)
			{
				CityActors[i]->Off();
			}
		}
	}
}