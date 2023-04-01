#include "SkillActor_Thunderbolt.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Thunderbolt::SkillActor_Thunderbolt() 
{
}

SkillActor_Thunderbolt::~SkillActor_Thunderbolt() 
{
}

void SkillActor_Thunderbolt::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Thunderbolt",  .ImageName = "Thunderbolt.bmp", .Start = 0, .End = 6, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Thunderbolt");
}

void SkillActor_Thunderbolt::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}