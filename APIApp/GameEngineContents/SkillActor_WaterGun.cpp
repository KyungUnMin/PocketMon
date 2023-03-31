#include "SkillActor_WaterGun.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_WaterGun::SkillActor_WaterGun() 
{
}

SkillActor_WaterGun::~SkillActor_WaterGun() 
{
}

void SkillActor_WaterGun::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "WaterGun",  .ImageName = "WaterGun.bmp", .Start = 0, .End = 4, .InterTime = 0.05f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("WaterGun");
}

void SkillActor_WaterGun::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd())
	{
		RenderPtr->Off();
	}
}