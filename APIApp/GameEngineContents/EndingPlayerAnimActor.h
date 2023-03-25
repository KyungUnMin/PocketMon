#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class EndingPlayerAnimActor : public GameEngineActor
{
public:
	EndingPlayerAnimActor();
	~EndingPlayerAnimActor();

	EndingPlayerAnimActor(const EndingPlayerAnimActor& _Other) = delete;
	EndingPlayerAnimActor(EndingPlayerAnimActor&& _Other) noexcept = delete;
	EndingPlayerAnimActor& operator=(const EndingPlayerAnimActor& _Other) = delete;
	EndingPlayerAnimActor& operator=(EndingPlayerAnimActor&& _Other) noexcept = delete;

	void MovePos(const float4& _Start, const float4& _Dest, float _Speed);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimRender = nullptr;
	GameEngineRender* GroundRender = nullptr;

	bool IsMove = false;
	float Speed = 0.0f;
	float Progress = 0.0f;

	float4 StartPos = float4::Zero;
	float4 DestPos = float4::Zero;
};