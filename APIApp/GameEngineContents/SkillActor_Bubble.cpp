#include "SkillActor_Bubble.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Bubble::SkillActor_Bubble() 
{
}

SkillActor_Bubble::~SkillActor_Bubble() 
{
}

void SkillActor_Bubble::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Bubble",  .ImageName = "Bubble.bmp", .Start = 0, .End = 0, .InterTime = 0.05f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Bubble_After",  .ImageName = "Bubble_After.bmp", .Start = 0, .End = 4, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Bubble");
}

void SkillActor_Bubble::Update(float _Deltatime)
{
	//if (true == RenderPtr->IsAnimationEnd())
	//{
	//	RenderPtr->Off();
	//}
}