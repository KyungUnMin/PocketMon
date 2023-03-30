#include "SkillActor_Growl.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Growl::SkillActor_Growl() 
{
}

SkillActor_Growl::~SkillActor_Growl() 
{
}

void SkillActor_Growl::GrowlSetting(int _Number)
{
	GrowlSet Num = static_cast<GrowlSet>(_Number - 1);

	switch (Num)
	{
	case GrowlSet::Growl1:
		RenderPtr->ChangeAnimation("Growl_1");
		Num1 = true;
		break;
	case GrowlSet::Growl2:
		RenderPtr->ChangeAnimation("Growl_2");
		Num2 = true;
		break;
	case GrowlSet::Growl3:
		RenderPtr->ChangeAnimation("Growl_3");
		Num3 = true;
		break;
	default:
		break;
	}
}

void SkillActor_Growl::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Growl_1",  .ImageName = "Growl1.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	RenderPtr->CreateAnimation({ .AnimationName = "Growl_2",  .ImageName = "Growl2.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	RenderPtr->CreateAnimation({ .AnimationName = "Growl_3",  .ImageName = "Growl3.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Growl_1");
}

void SkillActor_Growl::Update(float _Deltatime)
{
}
