#include "EndingFade.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

EndingFade::EndingFade()
{
}

EndingFade::~EndingFade()
{
}

void EndingFade::SetProgress(float _Progress)
{
	Progress = _Progress;
	CalculationAlpha();
}

void EndingFade::Start()
{
	FadeRender = CreateRender("Background.bmp", RenderOrder::Fade);
	FadeRender->SetScaleToImage();
	FadeRender->SetAlpha(0);
}

void EndingFade::Update(float _DeltaTime)
{
	Progress += _DeltaTime * Speed;
	CalculationAlpha();
}

void EndingFade::CalculationAlpha()
{
	int Alpha = static_cast<int>(GameEngineMath::Lerp(0.0f, 255.0f, Progress));
	FadeRender->SetAlpha(Alpha);
}
