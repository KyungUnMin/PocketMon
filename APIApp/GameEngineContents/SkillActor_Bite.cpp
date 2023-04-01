#include "SkillActor_Bite.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Bite::SkillActor_Bite() 
{
}

SkillActor_Bite::~SkillActor_Bite() 
{
}

void SkillActor_Bite::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Bite_Up",  .ImageName = "Bite.bmp", .Start = 0, .End = 0, .InterTime = 0.05f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Bite_Down",  .ImageName = "Bite.bmp", .Start = 1, .End = 1, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Bite_Down");
}

void SkillActor_Bite::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}