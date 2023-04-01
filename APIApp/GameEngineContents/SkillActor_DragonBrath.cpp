#include "SkillActor_DragonBrath.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_DragonBrath::SkillActor_DragonBrath() 
{
}

SkillActor_DragonBrath::~SkillActor_DragonBrath() 
{
}

void SkillActor_DragonBrath::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "DragonBrath",  .ImageName = "DragonBrath.bmp", .Start = 0, .End = 7, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("DragonBrath");
}

void SkillActor_DragonBrath::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}