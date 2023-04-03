#include "SkillActor_Ember.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
SkillActor_Ember::SkillActor_Ember() 
{
}

SkillActor_Ember::~SkillActor_Ember() 
{
}

void SkillActor_Ember::SetEmber(const float4& _StartPos, const float4& _EndPos)
{
	StartPos = _StartPos;
	EndPos = _EndPos;
	SetPos(StartPos);

	IsLeft = EndPos.x < StartPos.x;
}

void SkillActor_Ember::Start()
{
	EffectRender = CreateRender("Ember.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->CreateAnimation({ .AnimationName = "Shoot", .ImageName = "Ember.bmp", .Start = 0, .End = 0, .Loop = false, });
	EffectRender->CreateAnimation({ .AnimationName = "Burn", .ImageName = "Ember.bmp", .Start = 1, .End = 6, .InterTime = 0.07f, .Loop = false, });
	EffectRender->ChangeAnimation("Shoot");
}

void SkillActor_Ember::Update(float _DeltaTime)
{
	

	switch (CurState)
	{
	case SkillActor_Ember::EmberState::Shoot:
	{
		SetPos(float4::LerpClamp(StartPos, EndPos, GetLiveTime()));
		if (1 < GetLiveTime())
		{
			CurState = EmberState::Burn;
			EffectRender->ChangeAnimation("Burn");
		}
	}
		break;
	case SkillActor_Ember::EmberState::Burn:
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

