#include "FieldmapCity.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Fieldmap.h"
#include "FieldmapLevel.h"
#include "FieldmapFlower.h"

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

	CityFrontRenderer = CreateRender(ImageName + "_Front.bmp", RenderOrder::FieldFront);
	CityFrontRenderer->SetScaleToImage();

	CityColImage = GameEngineResources::GetInst().ImageFind(ImageName + "_Col.bmp");
	CityTypeImage = GameEngineResources::GetInst().ImageFind(ImageName + "_Type.bmp");

	CityScale = CityRenderer->GetImage()->GetImageScale();
	CityRenderer->Off();
	CityFrontRenderer->Off();

	float TileSize = Fieldmap::TileSize;

	int TileSizeX = static_cast<int>(CityScale.x / TileSize);
	int TileSizeY = static_cast<int>(CityScale.y / TileSize);

	MyTilemapData.Init(int2(TileSizeX, TileSizeY));

	for (int y = 0; y < TileSizeY; y++)
	{
		for (int x = 0; x < TileSizeX; x++)
		{
			int2 Index = int2(x, y);

			// Todo : 수영이 생겼을 경우 기능 수정
			MyTilemapData.SetWalkType(Index, FieldData::TileWalkType::Walk);

			if (RGB(0, 0, 0) != CityColImage->GetPixelColor(x, y, RGB(0, 0, 0)))
			{
				MyTilemapData.SetWalkable(Index, true);
			}
			else
			{
				MyTilemapData.SetWalkable(Index, false);
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

void FieldmapCity::AddFlowerActors(const std::string_view& _FlowerImageName)
{
	GameEngineImage* FindImage = GameEngineResources::GetInst().ImageFind(_FlowerImageName);

	if (nullptr == FindImage)
	{
		MsgAssert("해당 플라워 데이터 이미지파일이 존재하지 않습니다");
	}

	float4 ImageScale = FindImage->GetImageScale();
	int2 IntImageScale = int2(ImageScale.ix(), ImageScale.iy());

	GameEngineLevel* MyLevel = GetLevel();

	if (nullptr == MyLevel)
	{
		MsgAssert("게임 레벨을 불러오는데 실패했습니다.");
	}

	for (int y = 0; y < IntImageScale.y; y++)
	{
		for (int x = 0; x < IntImageScale.x; x++)
		{
			if (RGB(0, 0, 0) == FindImage->GetPixelColor(float4(static_cast<float>(x), static_cast<float>(y)), RGB(255, 255, 255)))
			{
				GameEngineActor* Flower = MyLevel->CreateActor<FieldmapFlower>();
				AddActor(int2(x, y), Flower); 
			}
		}
	}
}

void FieldmapCity::AddNeighbor(FieldmapCity* _NeighborCityPtr)
{
	for (size_t i = 0; i < NeighborCitys.size(); i++)
	{
		if (_NeighborCityPtr == NeighborCitys[i])
		{
			MsgAssert("이미 등록된 이웃시티를 중복 등록했습니다");
		}
	}

	NeighborCitys.push_back(_NeighborCityPtr);
}

void FieldmapCity::Update(float _DeltaTime)
{
	FieldmapUpdate();
}

void FieldmapCity::FieldmapUpdate()
{
	float4 PlayerPos = FieldmapLevel::GetPlayerPos();

	if (true == GameEngineCollision::CollisionRectToPoint(
		CollisionData(GetPos(), CityScale), CollisionData(PlayerPos)))
	{
		Fieldmap::ChangeCity(this);

		for (size_t i = 0; i < NeighborCitys.size(); i++)
		{
			if (nullptr == NeighborCitys[i])
			{
				MsgAssert("필드맵 이웃시티의 포인터 값이 nullptr 입니다");
			}

			NeighborCitys[i]->NeighborActive = true;
		}

		CityActive = true;
	}
	else
	{
		if (true == CityActive)
		{
			Fieldmap::ChangeCity(CityName);

			for (size_t i = 0; i < NeighborCitys.size(); i++)
			{
				if (nullptr == NeighborCitys[i])
				{
					MsgAssert("필드맵 이웃시티의 포인터 값이 nullptr 입니다");
				}

				NeighborCitys[i]->NeighborActive = false;
			}
		}

		CityActive = false;
	}

	if (true == CityActive || true == NeighborActive)
	{
		if (false == CityRenderer->IsUpdate())
		{
			CityRenderer->On();
			CityFrontRenderer->On();

			for (size_t i = 0; i < CityActors.size(); i++)
			{
				if (nullptr == CityActors[i])
				{
					MsgAssert("필드맵 시티에 등록된 nullptr 액터를 참조하려 했습니다");
				}

				CityActors[i]->On();
			}
		}
	}
	else
	{
		if (true == CityRenderer->IsUpdate())
		{
			CityRenderer->Off();
			CityFrontRenderer->Off();

			for (size_t i = 0; i < CityActors.size(); i++)
			{
				CityActors[i]->Off();
			}
		}
	}
}