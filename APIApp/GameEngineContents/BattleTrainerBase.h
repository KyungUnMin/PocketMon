#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class BattleFieldType;
class GameEngineComponent;

class BattleTrainerBase : public GameEngineActor
{
public:
	//BattlePlayer와 BattleEnemy에서 사용
	static const float MoveDuration;

	BattleTrainerBase();
	~BattleTrainerBase() override;

	BattleTrainerBase(const BattleTrainerBase& _Other) = delete;
	BattleTrainerBase(BattleTrainerBase&& _Other) noexcept = delete;
	BattleTrainerBase& operator=(const BattleTrainerBase& _Other) = delete;
	BattleTrainerBase& operator=(const BattleTrainerBase&& _Other) noexcept = delete;

	virtual void CreateMontser();

protected:
	bool Update_LerpMoveActor(const float4 _StartPos, const float4 _EndPos, float _Duration);
	bool Update_LerpMoveComponent(GameEngineComponent* _Component, const float4 _StartPos, const float4 _EndPos, float _Duration);
	

private:
	bool IsMove = false;
	float MoveStartTime = 0.f;
};

