#include "EndingPokeballBackground.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

EndingPokeballBackground::EndingPokeballBackground()
{
}

EndingPokeballBackground::~EndingPokeballBackground()
{
}

void EndingPokeballBackground::PlayPokeballAnim(PokeColor _Color)
{
	SetColor(_Color);
	EndingRing->On();
	PokeballRender->Off();
	Progress = 0.0f;
	Alpha = 255;
}

void EndingPokeballBackground::SetColor(PokeColor _Color)
{
	switch (_Color)
	{
	case EndingPokeballBackground::PokeColor::Red:
		PokeballRender->SetImage("EndPokeballRed.bmp");
		break;
	case EndingPokeballBackground::PokeColor::Blue:
		PokeballRender->SetImage("EndPokeballBlue.bmp");
		break;
	case EndingPokeballBackground::PokeColor::Green:
		PokeballRender->SetImage("EndPokeballGreen.bmp");
		break;
	case EndingPokeballBackground::PokeColor::Yellow:
		PokeballRender->SetImage("EndPokeballYellow.bmp");
		break;
	default:
		MsgAssert("잘못된 컬러 enum 값이 매개변수로 설정되었습니다");
		break;
	}
}

void EndingPokeballBackground::Start()
{
	PokeballRender = CreateRender("EndPokeballBlue.bmp", RenderOrder::EndingBack);
	PokeballRender->SetScale(float4(640, 640));
	PokeballRender->EffectCameraOff();	

	EndingRing = CreateRender("EndingRing.bmp", RenderOrder::EndingMiddle);
	EndingRing->SetScale(float4(640, 640));
	EndingRing->EffectCameraOff();
}

void EndingPokeballBackground::Update(float _DeltaTime)
{
	Progress += _DeltaTime * Speed;
	EndingRing->SetScale(float4::LerpClamp(StartSize, DestSize, Progress));


	if (255 != Alpha)
	{
		PokeballRender->SetAlpha(Alpha);
	}
	else
	{
		PokeballRender->SetAlpha(255);
	}

	if (2.0f <= Progress)
	{
		EndingRing->Off();
		PokeballRender->On();
	}
}
