#include "FieldmapRender.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "Fieldmap.h"
#include "ContentsEnum.h"

FieldmapRender::FieldmapRender()
{
}

FieldmapRender::~FieldmapRender()
{
}

void FieldmapRender::RenderPosUpdate(const float4& _Pos)
{
	CurPos = _Pos;
}

void FieldmapRender::Start()
{
	FieldSize = static_cast<int>(Fieldmap::TileSize);
	FieldSizeHalf = static_cast<int>(Fieldmap::TileSizeHalf);
	FieldSizeHalfFloat4 = float4{Fieldmap::TileSizeHalf, Fieldmap::TileSizeHalf };

	float TileSize = Fieldmap::TileSize;
	
	int RenderLengthX = (RenderSizeX * 2) + 1;
	int RenderLengthY = (RenderSizeY * 2) + 1;

	TileRenders.reserve(static_cast<size_t>(RenderLengthY));

	RendersSizeHalf = float4(static_cast<float>(RenderLengthX) * FieldSizeHalf, static_cast<float>(RenderLengthY) * FieldSizeHalf);

	for (size_t y = 0; y < TileRenders.capacity(); y++)
	{
		std::vector<GameEngineRender*> TempTileRenders;
		TempTileRenders.reserve(RenderLengthX);

		for (size_t x = 0; x < TempTileRenders.capacity(); x++)
		{
			GameEngineRender* TileRender = CreateRender("DebugTilemap.BMP", RenderOrder::DebugUI);

			float4 RenderScale = float4{ TileSize ,TileSize };
			float4 RenderPos = -RendersSizeHalf 
				+ FieldSizeHalfFloat4 
				+ float4(static_cast<float>(x * FieldSize), static_cast<float>(y * FieldSize));

			TileRender->SetFrame(1); 
			TileRender->SetScale(RenderScale);
			TileRender->SetPosition(RenderPos);
			TileRender->On();
			TempTileRenders.push_back(TileRender);
		}

		TileRenders.push_back(TempTileRenders);
	}
}

void FieldmapRender::Update(float _DeltaTime)
{
	int2 Index = Fieldmap::GetIndex(CurPos);
	float4 TilePos = Fieldmap::GetPos(Index);

	SetPos(TilePos);

	int2 RenderIndex = Index - int2(RenderSizeX, RenderSizeY);

	for (size_t y = 0; y < TileRenders.size(); y++)
	{
		for (size_t x = 0; x < TileRenders[y].size(); x++)
		{
			switch (DebugType)
			{
			case FieldmapRender::RenderType::Walkable:
				if (true == Fieldmap::Walkable(RenderIndex))
				{
					TileRenders[y][x]->SetFrame(0);
				}
				else
				{
					TileRenders[y][x]->SetFrame(1);
				}
				break;
			case FieldmapRender::RenderType::GroundType:
				TileRenders[y][x]->SetFrame(3 + static_cast<int>(Fieldmap::GetGroundType(RenderIndex)));
				break;
			default:
				MsgAssert("잘못된 FieldmapRender DebugType 입니다");
				break;
			}

			++RenderIndex.x;
		}

		RenderIndex.x = Index.x - RenderSizeX;
		++RenderIndex.y;
	}
}