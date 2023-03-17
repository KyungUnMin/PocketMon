#pragma once
#include <GameEngineCore/GameEngineActor.h>

class HpBackGroundMove : public GameEngineActor
{
public:
	static const float MoveDuration;

	HpBackGroundMove();
	~HpBackGroundMove() override;

	HpBackGroundMove(const HpBackGroundMove& _Other) = delete;
	HpBackGroundMove(HpBackGroundMove&& _Other) noexcept = delete;
	HpBackGroundMove& operator=(const HpBackGroundMove& _Other) = delete;
	HpBackGroundMove& operator=(const HpBackGroundMove&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override {}

	inline void SetMovePositions(const float4 _StartPos, const float4 _EndPos)
	{
		MoveStartPos = _StartPos;
		MoveEndPos = _EndPos;
	}

private:
	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;

	void HpBackGroundMoving();
};

