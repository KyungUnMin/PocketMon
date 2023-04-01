#include "SkillActor_Thunderbolt.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Thunderbolt::SkillActor_Thunderbolt() 
{
}

SkillActor_Thunderbolt::~SkillActor_Thunderbolt() 
{
}

void SkillActor_Thunderbolt::ThunderboltAfterSet()
{
	RenderPtr->ChangeAnimation("Thunderbolt_After");
	IsAfter = true;
}

void SkillActor_Thunderbolt::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Thunder",  .ImageName = "Thunder.bmp", .Start = 0, .End = 0, .InterTime = 0.1f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Thunderbolt_After",  .ImageName = "Thunderbolt_After.bmp", .Start = 0, .End = 5, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Thunder");
}

void SkillActor_Thunderbolt::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd() && true == IsAfter)
	{
		RenderPtr->Off();
	}
}