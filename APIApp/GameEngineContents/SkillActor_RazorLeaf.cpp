#include "SkillActor_RazorLeaf.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

SkillActor_RazorLeaf::SkillActor_RazorLeaf() 
{
}

SkillActor_RazorLeaf::~SkillActor_RazorLeaf() 
{
}

void SkillActor_RazorLeaf::LeafSetting(LeafSet _Set)
{
	switch (_Set)
	{
	case LeafSet::Leafs_Stop:
		RenderPtr->ChangeAnimation("Leafs_Stop");
		break;
	case LeafSet::Leafs_Move:
		RenderPtr->ChangeAnimation("Leafs_Move");
		IsMove = true;
		MoveSpeed = 55.0f;
		break;
	case LeafSet::Leafs_Shoot:
		RenderPtr->ChangeAnimation("Leafs_Shoot");
		IsLeafs = true;
		MoveSpeed = 0.0f;
		break;
	case LeafSet::RazorLeaf:
		RenderPtr->ChangeAnimation("RazorLeaf");
		RenderPtr->SetScale({ 128, 128 });
		break;
	case LeafSet::Leafs_Stop_L:
		RenderPtr->ChangeAnimation("Leafs_Stop_L");
		break;
	case LeafSet::Leafs_Move_L:
		RenderPtr->ChangeAnimation("Leafs_Move_L");
		IsMove_L = true;
		MoveSpeed = 55.0f;
		break;
	case LeafSet::Leafs_Shoot_L:
		RenderPtr->ChangeAnimation("Leafs_Shoot_L");
		IsLeafs = true;
		MoveSpeed = 0.0f;
		break;
	default:
		break;
	}
}

void SkillActor_RazorLeaf::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "Leafs_Stop",  .ImageName = "Leafs.bmp", .Start = 0, .End = 0, .InterTime = 0.2f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Leafs_Shoot",  .ImageName = "Leafs.bmp", .Start = 8, .End = 8, .InterTime = 0.3f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Leafs_Move",  .ImageName = "Leafs.bmp", .Start = 0, .End = 8, .InterTime = 0.35f });
	RenderPtr->CreateAnimation({ .AnimationName = "Leafs_Stop_L",  .ImageName = "Leafs_L.bmp", .Start = 0, .End = 0, .InterTime = 0.2f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Leafs_Shoot_L",  .ImageName = "Leafs_L.bmp", .Start = 8, .End = 8, .InterTime = 0.3f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "Leafs_Move_L",  .ImageName = "Leafs_L.bmp", .Start = 0, .End = 8, .InterTime = 0.35f });
	RenderPtr->CreateAnimation({ .AnimationName = "RazorLeaf",  .ImageName = "RazorLeaf.bmp", .Start = 0, .End = 3, .InterTime = 0.1f});
	RenderPtr->SetScale({ 64, 64 });

	RenderPtr->ChangeAnimation("Leafs_Stop");
}

void SkillActor_RazorLeaf::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd() && true == IsMove && 1 == SetCount)
	{
		SetCount = 0;
		LeafSetting(LeafSet::Leafs_Shoot);
	}

	if (true == RenderPtr->IsAnimationEnd() && true == IsMove_L && 1 == SetCount)
	{
		SetCount = 0;
		LeafSetting(LeafSet::Leafs_Shoot_L);
	}

	if (true == IsLeafs)
	{
		AlphaControl(_Deltatime);
	}
}

void SkillActor_RazorLeaf::AlphaControl(float _Deltatime)
{
	Alphatime += _Deltatime;

	if (0.4f <= Alphatime)
	{
		RenderPtr->SetAlpha(0);
	}
	else if (0.35f <= Alphatime)
	{
		RenderPtr->SetAlpha(50);
	}
	else if (0.3f <= Alphatime)
	{
		RenderPtr->SetAlpha(100);
		IsRazor = true;
	}
	else if (0.25f <= Alphatime)
	{
		RenderPtr->SetAlpha(150);
	}
	else if (0.2f <= Alphatime)
	{
		RenderPtr->SetAlpha(200);
	}
}