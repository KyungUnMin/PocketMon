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

	float TileSize = Fieldmap::TileSize;

	for (size_t y = 0; y < TileRenders.capacity(); y++)
	{
		std::vector<GameEngineRender*> TempTileRenders;
		TempTileRenders.reserve((RenderSizeX * 2 + 1));

		for (size_t x = 0; x < TempTileRenders.capacity(); x++)
		{
			GameEngineRender* TileRender = CreateRender("CenterActor.BMP", 0);
			TileRender->SetScale({ TileSize ,TileSize });
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
			DebugRender->SetScale({ TileSize ,TileSize });
			DebugRender->Off();
			TempDeugRenders.push_back(DebugRender);
		}

		DebugRenders.push_back(TempDeugRenders);
	}

	TileRenders[0][0]->OnOffSwtich();
	RendersSize = float4(TileRenders[0].size() * FieldSizeHalf, TileRenders.size() * FieldSizeHalf);
}

void FieldmapRender::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsUp("MapRenderDebug"))
	{
		IsDebugRender = !IsDebugRender;

		TileRenderSwtich();
		DebugRenderSwtich();
	}

	if (true == IsDebugRender)
	{
		SetRendersPos(DebugRenders);
	}
	else
	{
		SetRendersPos(TileRenders);
	}
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

void FieldmapRender::DebugRenderSwtich()
{
	for (size_t y = 0; y < DebugRenders.size(); y++)
	{
		for (size_t x = 0; x < DebugRenders[y].size(); x++)
		{
			DebugRenders[y][x]->OnOffSwtich();
		}
	}
}

void FieldmapRender::SetRendersPos(std::vector<std::vector<GameEngineRender*>>& _Renders)
{
	for (size_t y = 0; y < _Renders.size(); y++)
	{
		for (size_t x = 0; x < _Renders[y].size(); x++)
		{
			float4 RenderPos = CurPos - RendersSize + float4(x * FieldSize, y * FieldSize);
			Fieldmap::CalRenderStartPos(RenderPos);
			_Renders[y][x]->SetPosition(RenderPos);
		}
	}
}