#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <list>

class GameEngineRender;
class EndingWalkPlayer : public GameEngineActor
{
public:
	EndingWalkPlayer();
	~EndingWalkPlayer();

	EndingWalkPlayer(const EndingWalkPlayer& _Other) = delete;
	EndingWalkPlayer(EndingWalkPlayer&& _Other) noexcept = delete;
	EndingWalkPlayer& operator=(const EndingWalkPlayer& _Other) = delete;
	EndingWalkPlayer& operator=(EndingWalkPlayer&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimRender = nullptr;
	std::list<float4> MovePoint;

	float WaitTime = 1.0f;
	float ProgressTime = 0.0f;
	float Speed = 3.0f;

	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;
};

