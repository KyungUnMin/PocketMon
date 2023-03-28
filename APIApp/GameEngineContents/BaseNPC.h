#pragma once
#include <string>
#include <list>
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

class GameEngineRender;
class BaseNPC : public GameEngineActor
{
public:
	enum class NPCDir
	{
		Up,
		Down,
		Left,
		Right
	};
private:
	enum class NPCState
	{
		Idle,
		Move,
		interaction
	};

public:
	BaseNPC();
	~BaseNPC();

	BaseNPC(const BaseNPC& _Other) = delete;
	BaseNPC(BaseNPC&& _Other) noexcept = delete;
	BaseNPC& operator=(const BaseNPC& _Other) = delete;
	BaseNPC& operator=(BaseNPC&& _Other) noexcept = delete;

	void InitNPC(const std::string_view& _Name, const std::string_view& _ImageName);
	void AddNPC(const std::string_view& _CityName, int2 _Index);

	void AddMovePoint(const float4& _Pos)
	{
		MovePoints.push_back(_Pos);
	}

	std::list<float4>& GetMovePointRef()
	{
		return MovePoints;
	}

	inline void SetMoveSpeed(float _MoveSpeed)
	{
		MoveSpeed = _MoveSpeed;
	}

	inline void SetInteractionTime(float _Time)
	{
		InteractionTime = _Time;
	}

protected:
	void Update(float _DeltaTime) override;

	virtual void IdleStart();
	virtual void IdleUpdate(float _DeltaTime);
	virtual void IdleEnd();

	virtual void MoveStart();
	virtual void MoveUpdate(float _DeltaTime);
	virtual void MoveEnd();

	virtual void InteractionStart();
	virtual void InteractionUpdate(float _DeltaTime);
	virtual void InteractionEnd();

	void PlayAnimation(const std::string_view& _AnimationName);
	void ChangeState(NPCState _State);

private:
	GameEngineRender* NPCRender = nullptr;
	std::string Name; 
	std::list<float4> MovePoints;

	NPCState State = NPCState::Idle;
	NPCDir Dir = NPCDir::Up;

	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;
	float MoveProgress = 0.0f;
	float MoveSpeed = 1.0f;

	float InteractionTime = 1.0f;
	float InteractionProgress = 0.0f;
};