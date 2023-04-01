#include "SkillActor_Bite.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Bite::SkillActor_Bite() 
{
}

SkillActor_Bite::~SkillActor_Bite() 
{
}

void SkillActor_Bite::BiteSetting(int _Number)
{
	BiteSet Num = static_cast<BiteSet>(_Number - 1);

	switch (Num)
	{
	case BiteSet::Bite1:
		RenderPtr->ChangeAnimation("Bite_Up");
		Num1 = true;
		break;
	case BiteSet::Bite2:
		RenderPtr->ChangeAnimation("Bite_Down");
		Num2 = true;
		break;
	default:
		break;
	}
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