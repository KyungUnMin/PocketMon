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
	RenderPtr = CreateRender("Gust.bmp", BattleRenderOrder::SkillEffect);
	RenderPtr->SetScale({ 128, 128 });
}

void SkillActor_Gust::Update(float _Deltatime)
{
}