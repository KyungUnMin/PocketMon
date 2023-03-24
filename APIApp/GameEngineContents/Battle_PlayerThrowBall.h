#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Battle_PlayerThrowBall : public GameEngineActor
{
public:
	Battle_PlayerThrowBall();
	~Battle_PlayerThrowBall() override;

	Battle_PlayerThrowBall(const Battle_PlayerThrowBall& _Other) = delete;
	Battle_PlayerThrowBall(Battle_PlayerThrowBall&& _Other) noexcept = delete;
	Battle_PlayerThrowBall& operator=(const Battle_PlayerThrowBall& _Other) = delete;
	Battle_PlayerThrowBall& operator=(const Battle_PlayerThrowBall&& _Other) noexcept = delete;

	void Init(const float4& _DestPos, float _Duration, float _OffsetX = -100.f);

	inline void SetGravityAcc(float _Acc)
	{
		GravityAcc = _Acc;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	const float4 RenderScale = float4{ 64.f, 64.f };

	float Duration = 0.f;

	float4 StartPosX = float4::Zero;
	float4 DestPosX = float4::Zero;

	float VerticalSpeed = -100.f;
	float GravityAcc = 2000.f;
};

