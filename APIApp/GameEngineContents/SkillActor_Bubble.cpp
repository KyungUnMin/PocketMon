#include "SkillActor_Bubble.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

void SkillActor_Bubble::BubbleSetting(BubbleSet _enum)
{
	switch (_enum)
	{
	case BubbleSet::Bubble_Stop:
		RenderPtr->ChangeAnimation("Bubble_Stop");
		break;
	case BubbleSet::Bubble_Pop:
		RenderPtr->ChangeAnimation("Bubble_Pop");
		IsPop = true;
		break;
	default:
		break;
	}
}

SkillActor_Bubble::SkillActor_Bubble() 
{
}

SkillActor_Bubble::~SkillActor_Bubble() 
{
}

void SkillActor_Bubble::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Bubble_Stop",  .ImageName = "Bubble.bmp", .Start = 0, .End = 0, .InterTime = 0.05f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Bubble_Pop",  .ImageName = "Bubble.bmp", .Start = 0, .End = 2, .InterTime = 0.1f, .Loop = false });
	RenderPtr->SetScale({ 85, 64 });
	RenderPtr->SetAlpha(200);

	RenderPtr->ChangeAnimation("Bubble_Stop");
}

void SkillActor_Bubble::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd() && true == IsPop)
	{
		RenderPtr->Off();
	}
}