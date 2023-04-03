#include "SkillActor_DragonBrath.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
SkillActor_DragonBrath::SkillActor_DragonBrath()
{
}

SkillActor_DragonBrath::~SkillActor_DragonBrath()
{
}

void SkillActor_DragonBrath::SetDragonBrath(const float4& _StartPos, const float4& _EndPos, float _WaitTime)
{
	StartPos = _StartPos;
	EndPos = _EndPos;
	WaitTime = _WaitTime;
	SetPos(StartPos);
	EffectRender->Off();
	IsLeft = EndPos.x < StartPos.x;
}

void SkillActor_DragonBrath::Start()
{
	EffectRender = CreateRender("DragonBrath.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->CreateAnimation({ .AnimationName = "Shoot", .ImageName = "DragonBrath.bmp", .Start = 0, .End = 0, .Loop = false, });
	EffectRender->CreateAnimation({ .AnimationName = "Burn", .ImageName = "DragonBrath.bmp", .Start = 1, .End = 6, .InterTime = 0.07f, .Loop = false, });
	EffectRender->ChangeAnimation("Shoot");
}

void SkillActor_DragonBrath::Update(float _DeltaTime)
{
	if (GetLiveTime() < WaitTime)
	{
		return;
	}
	EffectRender->On();

	switch (CurState)
	{
	case SkillActor_DragonBrath::DragonBrathState::Shoot:
	{
		SetPos(float4::LerpClamp(StartPos, EndPos, GetLiveTime() - WaitTime));
		if (1 + WaitTime < GetLiveTime())
		{
			CurState = DragonBrathState::Burn;
			EffectRender->ChangeAnimation("Burn");
		}
	}
	break;
	case SkillActor_DragonBrath::DragonBrathState::Burn:
	{
		if (true == EffectRender->IsAnimationEnd())
		{
			Death();
		}
		SetMove(IsLeft == true ? float4::Left : float4::Right * 132 * _DeltaTime);
	}
	break;
	default:
		break;
	}
}

