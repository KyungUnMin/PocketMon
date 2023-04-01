#include "SkillActor_Thunder.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Thunder::SkillActor_Thunder() 
{
}

SkillActor_Thunder::~SkillActor_Thunder() 
{
}

void SkillActor_Thunder::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Thunder",  .ImageName = "Thunder.bmp", .Start = 0, .End = 4, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Thunder");
}

void SkillActor_Thunder::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}