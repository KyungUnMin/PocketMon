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

void FieldmapRender::RenderTypeSwitch(TileDebugRender::RenderType _DebugRenderType)
{
	for (size_t y = 0; y < TileDebugRenders.size(); y++)
	{
		for (size_t x = 0; x < TileDebugRenders[y].size(); x++)
		{
			if (TileDebugRenders[y][x]->GetDebugType() == _DebugRenderType)
			{
				TileDebugRenders[y][x]->OnOffSwtich();
			}
			else
			{
				TileDebugRenders[y][x]->On();
			}

			TileDebugRenders[y][x]->SetDebugType(_DebugRenderType);
		}
	}
}

void FieldmapRender::Start()
{
	FieldSize = static_cast<int>(Fieldmap::TileSize);
	FieldSizeHalf = static_cast<int>(Fieldmap::TileSizeHalf);
	FieldSizeHalfFloat4 = float4{Fieldmap::TileSizeHalf, Fieldmap::TileSizeHalf };

	float TileSize = Fieldmap::TileSize;
	
	int RenderLengthX = (RenderSizeX * 2) + 1;
	int RenderLengthY = (RenderSizeY * 2) + 1;

	TileDebugRenders.reserve(static_cast<size_t>(RenderLengthY));

	RendersSizeHalf = float4(static_cast<float>(RenderLengthX) * FieldSizeHalf, static_cast<float>(RenderLengthY) * FieldSizeHalf);

	for (size_t y = 0; y < TileDebugRenders.capacity(); y++)
	{
		std::vector<TileDebugRender*> TempTileRenders;
		TempTileRenders.reserve(RenderLengthX);

		for (size_t x = 0; x < TempTileRenders.capacity(); x++)
		{
			TileDebugRender* TileRender = GetLevel()->CreateActor<TileDebugRender>();

			float4 RenderScale = float4{ TileSize ,TileSize };
			float4 RenderPos = -RendersSizeHalf 
				+ FieldSizeHalfFloat4 
				+ float4(static_cast<float>(x * FieldSize), static_cast<float>(y * FieldSize));

			TileRender->SetPos(RenderPos);
			TileRender->Off();
			TempTileRenders.push_back(TileRender);
		}

		TileDebugRenders.push_back(TempTileRenders);
	}
}

void FieldmapRender::Update(float _DeltaTime)
{
	int2 Index = Fieldmap::GetIndex(CurPos);
	float4 TilePos = Fieldmap::GetPos(Index);
	float4 CameraPos = GetLevel()->GetCameraPos();

	SetPos(TilePos);

	int2 RenderIndex = Index - int2(RenderSizeX, RenderSizeY);

	for (size_t y = 0; y < TileDebugRenders.size(); y++)
	{
		for (size_t x = 0; x < TileDebugRenders[y].size(); x++)
		{
			TileDebugRenders[y][x]->SetIndex(RenderIndex);
			++RenderIndex.x;
		}

		RenderIndex.x = Index.x - RenderSizeX;
		++RenderIndex.y;
	}
}