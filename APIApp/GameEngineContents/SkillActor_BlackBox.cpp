#include "SkillActor_BlackBox.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_BlackBox::SkillActor_BlackBox()
{
}

SkillActor_BlackBox::~SkillActor_BlackBox()
{
}

void SkillActor_BlackBox::Start()
{
	RenderPtr = CreateRender("BlackBox.bmp", BattleRenderOrder::Ground);
	RenderPtr->SetScale(RenderPtr->GetImage()->GetImageScale());
	RenderPtr->SetPosition(GameEngineWindow::GetScreenSize().half());
	RenderPtr->EffectCameraOff();
	RenderPtr->SetAlpha(0);
}

void SkillActor_BlackBox::Update(float _Deltatime)
{
	if (true == IsFadeInStart)
	{
		FadeIn(_Deltatime);
	}

	if (true == IsFadeOutStart)
	{
		FadeOut(_Deltatime);
	}
}

void SkillActor_BlackBox::FadeIn(float _Deltatime)
{
	FadeInTime += _Deltatime;

	if (0.1f <= FadeInTime)
	{
		if (120 >= AlphaValue)
		{
			AlphaValue += 5;
			RenderPtr->SetAlpha(AlphaValue);
		}
	}
}

void SkillActor_BlackBox::FadeOut(float _Deltatime)
{
	FadeOutTime += _Deltatime;

	if (0.1f <= FadeOutTime)
	{
		if (5 <= AlphaValue)
		{
			AlphaValue -= 5;
			RenderPtr->SetAlpha(AlphaValue);
		}
	}
}