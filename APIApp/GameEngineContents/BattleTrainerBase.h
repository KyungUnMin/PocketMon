#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class BattleFieldType;

class BattleTrainerBase : public GameEngineActor
{
public:
	static const float MoveDuration;

	BattleTrainerBase();
	~BattleTrainerBase() override;

	BattleTrainerBase(const BattleTrainerBase& _Other) = delete;
	BattleTrainerBase(BattleTrainerBase&& _Other) noexcept = delete;
	BattleTrainerBase& operator=(const BattleTrainerBase& _Other) = delete;
	BattleTrainerBase& operator=(const BattleTrainerBase&& _Other) noexcept = delete;

	virtual void PocketBallThrow(){}

	virtual void MonsterCreate(){}


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override{}

	inline void SetMovePositions(const float4 _StartPos, const float4 _EndPos)
	{
		MoveStartPos = _StartPos;
		MoveEndPos = _EndPos;
	}

private:
	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;
	
	void BattleStartMove();
};

