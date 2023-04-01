#include "SkillActor_Thunder.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Thunder::SkillActor_Thunder() 
{
}

SkillActor_Thunder::~SkillActor_Thunder() 
{
}

void SkillActor_Thunder::ThunderSetting(ThunderSet _Number)
{
	switch (_Number)
	{
	case ThunderSet::Thunder1:
		RenderPtr->ChangeAnimation("Thunder1");
		Num1 = true;
		break;
	case ThunderSet::Thunder2:
		RenderPtr->ChangeAnimation("Thunder2");
		RenderPtr->SetScale({180, 180});
		Num2 = true;
		break;
	case ThunderSet::Thunder3:
		RenderPtr->ChangeAnimation("Thunder3");
		Num2 = true;
		break;
	default:
		break;
	}
}

void SkillActor_Thunder::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Thunder1",  .ImageName = "Thunder.bmp", .Start = 0, .End = 0, .InterTime = 0.05f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Thunder2",  .ImageName = "Thunder.bmp", .Start = 0, .End = 4, .InterTime = 0.07f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Thunder3",  .ImageName = "Thunder.bmp", .Start = 2, .End = 4, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Thunder1");
}

void SkillActor_Thunder::Update(float _Deltatime)
{
	if (true == Num1)
	{
		
	}

	if (true == Num2)
	{
		if (true == RenderPtr->IsAnimationEnd())
		{
			RenderPtr->Off();
		}
	}

	if (true == Num3)
	{
		if (true == RenderPtr->IsAnimationEnd())
		{
			RenderPtr->Off();
		}
	}
}