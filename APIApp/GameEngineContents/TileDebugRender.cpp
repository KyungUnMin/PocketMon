#include "TileDebugRender.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "Fieldmap.h"

TileDebugRender::TileDebugRender()
{
}

TileDebugRender::~TileDebugRender()
{
}

void TileDebugRender::SetDebugType(RenderType _DebugType)
{
	DebugType = _DebugType;

	switch (DebugType)
	{
	case TileDebugRender::RenderType::Walkable:
		TileRender->On();
		TextRender->Off();
		break;
	case TileDebugRender::RenderType::GroundType:		
		TileRender->On();
		TextRender->Off();
		break;
	case TileDebugRender::RenderType::Event:
		TileRender->On();
		TextRender->On();
		break;
	default:
		MsgAssert("잘못된 필드맵랜더 디버그 타입입니다");
		break;
	}

}

void TileDebugRender::Start()
{
	TileRender = CreateRender("DebugTilemap.BMP", RenderOrder::DebugUI);
	float TileSize = Fieldmap::TileSize;
	float4 RenderScale = float4{ TileSize ,TileSize };

	TileRender->SetFrame(0);
	TileRender->SetScale(RenderScale);
	TileRender->Off();

	TextRender = CreateRender(RenderOrder::DebugText);
	TextRender->SetText("0");
	TextRender->SetTextBoxScale(float4{ 20, 20 });
	TextRender->SetMove(float4{ -30, 10 });
	TextRender->Off();
}

void TileDebugRender::Update(float _DeltaTime) 
{
	SetPos(Fieldmap::GetPos(Index));

	switch (DebugType)
	{
	case RenderType::Walkable:
		if (true == Fieldmap::Walkable(Index))
		{
			TileRender->SetFrame(0);
		}
		else
		{
			TileRender->SetFrame(1);
		}
		break;
	case RenderType::GroundType:
		TileRender->SetFrame(3 + static_cast<int>(Fieldmap::GetGroundType(Index)));
		break;
	case RenderType::Event:
		TileRender->SetFrame(13);
		TextRender->SetText(std::to_string(Fieldmap::GetEventCount(Index)));
		TextRender->SetTextBoxScale(float4{ 20, 20 });
		break;
	default:
		MsgAssert("잘못된 FieldmapRender DebugType 입니다");
		break;
	}
}