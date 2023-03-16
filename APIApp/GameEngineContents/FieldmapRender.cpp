#include "FieldmapRender.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "Fieldmap.h"

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

	TileRenders.reserve((RenderSizeY * 2 + 1));

	for (size_t y = 0; y < TileRenders.capacity(); y++)
	{
		std::vector<GameEngineRender*> TempTileRenders;
		TempTileRenders.reserve((RenderSizeX * 2 + 1));

		for (size_t x = 0; x < TempTileRenders.capacity(); x++)
		{
			GameEngineRender* TileRender = CreateRender("CenterActor.BMP", 0);
			TileRender->On();
			TempTileRenders.push_back(TileRender);
		}

		TileRenders.push_back(TempTileRenders);
	}

	DebugRenders.reserve((RenderSizeY * 2 + 1));

	for (size_t y = 0; y < DebugRenders.capacity(); y++)
	{
		std::vector<GameEngineRender*> TempDeugRenders;
		TempDeugRenders.reserve((RenderSizeX * 2 + 1));

		for (size_t x = 0; x < TempDeugRenders.capacity(); x++)
		{
			GameEngineRender* DebugRender = CreateRender("CenterActor.BMP", 0);
			DebugRender->Off();
			TempDeugRenders.push_back(DebugRender);
		}

		TileRenders.push_back(TempDeugRenders);
	}
}

void FieldmapRender::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsUp("MapRenderDebug"))
	{
		IsDebugRender = !IsDebugRender;
	}


}