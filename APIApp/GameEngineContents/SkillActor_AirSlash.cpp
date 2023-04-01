#include "SkillActor_AirSlash.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_AirSlash::SkillActor_AirSlash() 
{
}

SkillActor_AirSlash::~SkillActor_AirSlash() 
{
}

void SkillActor_AirSlash::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "AirSlash",  .ImageName = "AirSlash.bmp", .Start = 0, .End = 4, .InterTime = 0.1f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("AirSlash");
}

void SkillActor_AirSlash::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		OffTime += _Deltatime;

		if (0.4f <= OffTime)
		{
			RenderPtr->Off();
		}
	}
}