#include "BattleTrainerBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include "Battle_MonsterAppearEffect.h"
#include "ContentsEnum.h"

const float BattleTrainerBase::MoveDuration = 1.5f;

BattleTrainerBase::BattleTrainerBase()
{

}

BattleTrainerBase::~BattleTrainerBase()
{

}

bool BattleTrainerBase::Update_LerpMoveActor(const float4 _StartPos, const float4 _EndPos, float _Duration)
{
	if (false == IsMove)
	{
		MoveStartTime = GetLiveTime();
		IsMove = true;
	}

	float NowTime = GetLiveTime() - MoveStartTime;
	if (_Duration < NowTime)
	{
		IsMove = false;
		return IsMove;
	}

	float Ratio = (NowTime / _Duration);
	float4 NowPos = float4::LerpClamp(_StartPos, _EndPos, Ratio);
	SetPos(NowPos);
	return IsMove;
}

bool BattleTrainerBase::Update_LerpMoveComponent(GameEngineComponent* _Component, const float4 _StartPos, const float4 _EndPos, float _Duration)
{
	if (false == IsMove)
	{
		MoveStartTime = GetLiveTime();
		IsMove = true;
	}

	float NowTime = GetLiveTime() - MoveStartTime;
	if (_Duration < NowTime)
	{
		IsMove = false;
		return IsMove;
	}

	float Ratio = (NowTime / _Duration);
	float4 NowPos = float4::LerpClamp(_StartPos, _EndPos, Ratio);
	_Component->SetPosition(NowPos);
	return IsMove;
}





