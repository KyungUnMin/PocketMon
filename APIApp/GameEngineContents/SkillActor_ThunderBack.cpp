#include "SkillActor_ThunderBack.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_ThunderBack::SkillActor_ThunderBack() 
{
}

SkillActor_ThunderBack::~SkillActor_ThunderBack() 
{
}

void SkillActor_ThunderBack::Start()
{
	float4 BPos = GameEngineWindow::GetScreenSize().half();
	float XPos = BPos.x + 50;
	float YPos = BPos.y - 100;

	RenderPtr = CreateRender("ThunderBack.bmp", BattleRenderOrder::Ground);
	RenderPtr->SetScale({900, 600});
	RenderPtr->SetPosition({ XPos, YPos });
	RenderPtr->EffectCameraOff();
	RenderPtr->SetAlpha(0);
}

void SkillActor_ThunderBack::Update(float _Deltatime)
{
	if (true == IsFadeInStart)
	{
		FadeIn(_Deltatime);
	}

	if (true == FadeInEnd)
	{
		SetMove(float4::Right * 40 * _Deltatime);
	}

	if (true == IsFadeOutStart)
	{
		FadeOut(_Deltatime);
	}
}

void SkillActor_ThunderBack::FadeIn(float _Deltatime)
{
	FadeInTime += _Deltatime;

	if (0.1f <= FadeInTime)
	{
		if (245 >= AlphaValue)
		{
			AlphaValue += 10;
			RenderPtr->SetAlpha(AlphaValue);
		}

		if (255 == AlphaValue)
		{
			FadeInEnd = true;
		}
	}
}

void SkillActor_ThunderBack::FadeOut(float _Deltatime)
{
	FadeOutTime += _Deltatime;

	if (0.1f <= FadeOutTime)
	{
		if (10 <= AlphaValue)
		{
			AlphaValue -= 10;
			RenderPtr->SetAlpha(AlphaValue);
		}
	}
}