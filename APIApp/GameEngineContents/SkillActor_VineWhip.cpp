#include "SkillActor_VineWhip.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_VineWhip::SkillActor_VineWhip() 
{
}

SkillActor_VineWhip::~SkillActor_VineWhip() 
{
}

void SkillActor_VineWhip::VineSetting(VineSet _Set)
{
	switch (_Set)
	{
	case VineSet::Vine_R:
		RenderPtr->ChangeAnimation("Vine_R");
		IsVine_R = true;
		break;
	case VineSet::Vine_R_Stop:
		RenderPtr->ChangeAnimation("Vine_R_Stop");
		break;
	case VineSet::Vine_L:
		RenderPtr->ChangeAnimation("Vine_L");
		IsVine_L = true;
		break;
	case VineSet::Vine_L_Stop:
		RenderPtr->ChangeAnimation("Vine_L_Stop");
		break;
	case VineSet::VineWhip:
		RenderPtr->ChangeAnimation("VineWhip");
		IsVineWhip = true;
		RenderPtr->SetScale({ 170, 170 });
		RenderPtr->SetAlpha(180);
		break;
	default:
		break;
	}
}

void SkillActor_VineWhip::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Vine_R",  .ImageName = "Vine_R.bmp", .Start = 0, .End = 4, .InterTime = 0.12f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Vine_R_Stop",  .ImageName = "Vine_R.bmp", .Start = 0, .End = 0, .InterTime = 0.12f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Vine_L",  .ImageName = "Vine_L.bmp", .Start = 0, .End = 4, .InterTime = 0.12f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Vine_L_Stop",  .ImageName = "Vine_L.bmp", .Start = 0, .End = 0, .InterTime = 0.12f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "VineWhip",  .ImageName = "VineWhip.bmp", .Start = 0, .End = 3, .InterTime = 0.12f});
	RenderPtr->SetScale({ 350, 350 });
	RenderPtr->SetAlpha(0);

	RenderPtr->ChangeAnimation("Vine_R_Stop");
}

void SkillActor_VineWhip::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd() && true == IsVineWhip)
	{
		RenderPtr->Off();
	}

	if (true == RenderPtr->IsAnimationEnd() && true == IsVine_R)
	{
		RenderPtr->Off();
	}

	if (true == RenderPtr->IsAnimationEnd() && true == IsVine_L)
	{
		RenderPtr->Off();
	}
}

void SkillActor_VineWhip::AlphaControl(int _Value)
{
	RenderPtr->SetAlpha(_Value);
}