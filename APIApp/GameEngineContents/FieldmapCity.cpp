#include "FieldmapCity.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "Fieldmap.h"

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
		MsgAssert("아직 필드맵 시티가 생성되지 않았습니다.");
	}

	CityPos = _CityPos - CityRenderer->GetScale().half();
}

void FieldmapCity::InitFieldRender(const std::string_view& _ImageName, const std::string_view& _ColImageName)
{
	if (nullptr != CityRenderer)
	{
		MsgAssert("필드맵 시티를 중복 초기화 했습니다");
	}

	CityRenderer = CreateRender(_ImageName, RenderOrder::Tilemap);
	CityRenderer->SetScaleToImage();

	CityColImage = GameEngineResources::GetInst().ImageFind(_ColImageName);

	float4 ImageScale = CityRenderer->GetImage()->GetImageScale();

	float TileSize = Fieldmap::TileSize;

	int TileSizeX = static_cast<int>(ImageScale.x / TileSize);
	int TileSizeY = static_cast<int>(ImageScale.y / TileSize);

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
}

void FieldmapCity::Update(float _DeltaTime)
{
	// 콜리전 체크해서 켰다 껏다
}