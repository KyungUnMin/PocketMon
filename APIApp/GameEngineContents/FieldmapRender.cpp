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

	TileRenders.reserve((RenderSizeY * 2) + 1);

	float TileSize = Fieldmap::TileSize;

	for (size_t y = 0; y < TileRenders.capacity(); y++)
	{
		std::vector<GameEngineRender*> TempTileRenders;
		TempTileRenders.reserve((RenderSizeX * 2) + 1);

		for (size_t x = 0; x < TempTileRenders.capacity(); x++)
		{
			GameEngineRender* TileRender = CreateRender("DebugTilemap.BMP", RenderOrder::Tilemap);
			TileRender->SetFrame(0);
			TileRender->SetScale({ TileSize ,TileSize });
			TileRender->On();
			TempTileRenders.push_back(TileRender);
		}

		TileRenders.push_back(TempTileRenders);
	}

	RendersSize = float4(
		static_cast<float>((TileRenders[0].size() - 1) * FieldSizeHalf),
		static_cast<float>((TileRenders.size() - 1) * FieldSizeHalf));
}

void FieldmapRender::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsUp("MapRenderDebug"))
	{
		IsDebugRender = !IsDebugRender;
	}

	SetRendersPos(TileRenders);
}

void FieldmapRender::TileRenderSwtich()
{
	for (size_t y = 0; y < TileRenders.size(); y++)
	{
		for (size_t x = 0; x < TileRenders[y].size(); x++)
		{
			TileRenders[y][x]->OnOffSwtich();
		}
	}
}

void FieldmapRender::SetRendersPos(std::vector<std::vector<GameEngineRender*>>& _Renders)
{
	for (size_t y = 0; y < _Renders.size(); y++)
	{
		for (size_t x = 0; x < _Renders[y].size(); x++)
		{
			float4 RenderPos = CurPos - RendersSize + float4(
				static_cast<float>(x * FieldSize),
				static_cast<float>(y * FieldSize)) ;

			int2 RenderIndex = Fieldmap::GetIndex(RenderPos);
			RenderPos = Fieldmap::GetPos(RenderIndex);
			RenderPos += FieldSizeHalfFloat4;

			if (true == Fieldmap::Walkable(RenderIndex))
			{
				_Renders[y][x]->SetFrame(1);
			}
			else
			{
				_Renders[y][x]->SetFrame(2);
			}

			_Renders[y][x]->SetPosition(RenderPos);
		}
	}
}