#include "SkillActor_Gust.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Gust::SkillActor_Gust() 
{
}

SkillActor_Gust::~SkillActor_Gust() 
{
}

void SkillActor_Gust::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Gust",  .ImageName = "Gust.bmp", .Start = 0, .End = 1, .InterTime = 0.1f});
	RenderPtr->SetScale({ 128, 256 });
	RenderPtr->SetAlpha(0);

	RenderPtr->ChangeAnimation("Gust");
}

void SkillActor_Gust::Update(float _Deltatime)
{
}

void SkillActor_Gust::SetAlphaValue(int _Value)
{
	RenderPtr->SetAlpha(_Value);
}