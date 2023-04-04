#include "SkillActor_RockThrow.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
SkillActor_RockThrow::SkillActor_RockThrow() 
{
}

SkillActor_RockThrow::~SkillActor_RockThrow() 
{
}

void SkillActor_RockThrow::SetRock(const float4& _Pos, const float4& _Scale, float _Delay, bool _IsLeft)
{
	SetPos(_Pos);
	EffectRender->SetScale(_Scale);
	Delay = _Delay;
	IsLeft = _IsLeft;
}

void SkillActor_RockThrow::Start()
{
	EffectRender = CreateRender("Rock.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetPosition({ 0, -512 });
}

void SkillActor_RockThrow::Update(float _DeltaTime)
{
	if (GetLiveTime() < Delay)
	{
		return;
	}
	switch (CurState)
	{
	case SkillActor_RockThrow::SkillState::Fall:
		FallUpdate(_DeltaTime);
		break;
	case SkillActor_RockThrow::SkillState::Jump:
		JumpUpdate(_DeltaTime);
		break;
	default:
		break;
	}
}

void SkillActor_RockThrow::FallUpdate(float _DeltaTime)
{
	CurrentGravity += GravityForce * _DeltaTime;
	CurrentGravity = std::min<float>(CurrentGravity, MaxGravity);
	EffectRender->SetMove(float4::Down * CurrentGravity * _DeltaTime);

	if (0 < EffectRender->GetPosition().y)
	{
		CurState = SkillState::Jump;
		CurrentGravity = -500;
		EffectRender->SetPosition({ 0, -0.01f });
	}
}

void SkillActor_RockThrow::JumpUpdate(float _DeltaTime)
{
	CurrentGravity += GravityForce * _DeltaTime;
	CurrentGravity = std::min<float>(CurrentGravity, MaxGravity);
	EffectRender->SetMove(float4::Down * CurrentGravity * _DeltaTime);

	EffectRender->SetMove(true == IsLeft ? float4::Left : float4::Right * MoveSpeed * _DeltaTime);

	if (64 < EffectRender->GetPosition().y)
	{
		Death();
	}
}

