#include "SkillActor_RazorLeaf.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_RazorLeaf::SkillActor_RazorLeaf() 
{
}

SkillActor_RazorLeaf::~SkillActor_RazorLeaf() 
{
}

void SkillActor_RazorLeaf::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "RazorLeaf",  .ImageName = "RazorLeaf.bmp", .Start = 0, .End = 2, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("RazorLeaf");
}

void SkillActor_RazorLeaf::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}