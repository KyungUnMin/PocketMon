#include "SkillActor_VineWhip.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_VineWhip::SkillActor_VineWhip() 
{
}

SkillActor_VineWhip::~SkillActor_VineWhip() 
{
}

void SkillActor_VineWhip::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "VineWhip",  .ImageName = "VineWhip.bmp", .Start = 0, .End = 3, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("VineWhip");
}

void SkillActor_VineWhip::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}