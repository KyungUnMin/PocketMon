#include "SkillActor_WaterGun.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnum.h"

void SkillActor_WaterGun::WaterGunSetting(WaterGunSet _Set)
{
	switch (_Set)
	{
	case WaterGunSet::WaterGun_Shoot_R:
		RenderPtr->ChangeAnimation("WaterGun_Shoot_R");
		IsShoot = true;
		break;
	case WaterGunSet::WaterGun_Shoot_L:
		RenderPtr->ChangeAnimation("WaterGun_Shoot_L");
		IsShoot = true;
		break;
	case WaterGunSet::WaterGun_Stop:
		RenderPtr->ChangeAnimation("WaterGun_Stop");
		RenderPtr->SetAlpha(180);
		RenderPtr->SetScale({ 64, 64 });
		break;
	default:
		break;
	}
}

SkillActor_WaterGun::SkillActor_WaterGun() 
{
}

SkillActor_WaterGun::~SkillActor_WaterGun() 
{
}

void SkillActor_WaterGun::Start()
{
	RenderPtr = CreateRender(BattleRenderOrder::SkillEffect);
	RenderPtr->CreateAnimation({ .AnimationName = "WaterGun_Shoot_R",  .ImageName = "WaterGun_R.bmp", .Start = 0, .End = 4, .InterTime = 0.1f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "WaterGun_Shoot_L",  .ImageName = "WaterGun_L.bmp", .Start = 0, .End = 4, .InterTime = 0.1f, .Loop = false });
	RenderPtr->CreateAnimation({ .AnimationName = "WaterGun_Stop",  .ImageName = "WaterGun_After.bmp", .Start = 1, .End = 1, .InterTime = 0.06f, .Loop = false });
	RenderPtr->SetScale({ 128, 128 });

	RenderPtr->ChangeAnimation("WaterGun_Shoot_R");
}

void SkillActor_WaterGun::Update(float _Deltatime)
{
	if (true == RenderPtr->IsAnimationEnd() && true == IsShoot)
	{
		AlphaControl(_Deltatime);
	}
}

void SkillActor_WaterGun::AlphaControl(float _Deltatime)
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