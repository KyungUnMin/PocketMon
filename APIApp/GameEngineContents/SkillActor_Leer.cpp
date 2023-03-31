#include "SkillActor_Leer.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_Leer::SkillActor_Leer() 
{
}

SkillActor_Leer::~SkillActor_Leer() 
{
}

void SkillActor_Leer::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Leer",  .ImageName = "Leer_or_other.bmp", .Start = 0, .End = 3, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("Leer");
}

void SkillActor_Leer::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}