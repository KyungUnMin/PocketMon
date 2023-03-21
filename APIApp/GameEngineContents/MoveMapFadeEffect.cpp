#include "MoveMapFadeEffect.h"
#include <GameEngineCore/GameEngineRender.h>

MoveMapFadeEffect* MoveMapFadeEffect::MainMoveMapFadeEffect = nullptr;

MoveMapFadeEffect::MoveMapFadeEffect()
{

}

MoveMapFadeEffect::~MoveMapFadeEffect()
{

}

void MoveMapFadeEffect::On()
{
	GameEngineObject::On();
	UpdateStart();
}

void MoveMapFadeEffect::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void MoveMapFadeEffect::OnOffSwtich()
{
	if (IsUpdate())
	{
		Off();
	}
	else
	{
		On();
	}
}

void MoveMapFadeEffect::Start()
{
	SetPos(ActorPos);
	FadeAlphaRender = CreateRender("MoveMapFade1.bmp", RenderOrder::Fade);
	FadeAlphaRender->EffectCameraOff();
	FadeAlphaRender->SetScaleToImage();

	FadeDoorRender1 = CreateRender("MoveMapFade2.bmp", static_cast<int>(RenderOrder::Fade) - 1);
	FadeDoorRender1->EffectCameraOff();
	FadeDoorRender1->SetScaleToImage();
	FadeDoorRender2 = CreateRender("MoveMapFade2.bmp", static_cast<int>(RenderOrder::Fade) - 1);
	FadeDoorRender2->EffectCameraOff();
	FadeDoorRender2->SetScaleToImage();
	
	Off();
}

void MoveMapFadeEffect::Update(float _DeltaTime)
{
	Time += _DeltaTime;
	if (Time >= FadeSpeed)
	{
		Time = 0;
		float4 SaveValue = AlphaStartValue;
		AlphaStartValue = AlphaEndValue;
		AlphaEndValue = SaveValue;

		LoopCount++;
		if (LoopCount == 2)
		{
			Off();
		}
	}

	FadeAlphaRender->SetAlpha(float4::LerpClamp(AlphaStartValue, AlphaEndValue, Time / FadeSpeed).ix());

	if (LoopCount == 1)
	{
		FadeDoorRender1->On();
		FadeDoorRender2->On();

		FadeDoorRender1->SetPosition(float4::LerpClamp(FadeDoorRender1StartPos, FadeDoorRender1EndPos, Time / FadeSpeed));
		FadeDoorRender2->SetPosition(float4::LerpClamp(FadeDoorRender2StartPos, FadeDoorRender2EndPos, Time / FadeSpeed));
	}

}

void MoveMapFadeEffect::UpdateStart()
{
	FadeDoorRender1->Off();
	FadeDoorRender2->Off();
}

void MoveMapFadeEffect::UpdateEnd()
{
	AlphaStartValue = {};
	AlphaEndValue = { 255 };

	Time = 0.0f;
	LoopCount = 0;
}
	