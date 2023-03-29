#pragma once
#include <string>
#include <list>
#include <map>
#include <functional>
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

enum class LookDir;
class GameEngineRender;
class BaseNPC : public GameEngineActor
{
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
	void AddScript(const std::string_view& _Script);

	// NPC 이동 지점 추가
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

	void Look(LookDir _Dir);
	void Look(const float4& _TargetPos);
	void Look(const float4& _NpcPos, const float4& _TargetPos);
	void Look(const int2& _NpcIndex, const int2& _TargetPos);

	static LookDir GetDir(const int2& _ViewIndex, const int2& _TargetIndex);
	static LookDir TurnLeftDir(LookDir _Dir);
	static LookDir TurnRightDir(LookDir _Dir);

protected:
	LookDir Dir;

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

	void AddInteractionFunc(std::function<void()> _Func, bool _IsLoop = true);

	void PlayAnimation();
	void ChangeState(NPCState _State);

private:
	GameEngineRender* NPCRender = nullptr;
	std::string CityName; 
	std::string Name; 
	std::list<float4> MovePoints;

	std::vector<std::function<void()>> InteractionFuncs;
	std::vector<std::function<void()>> LoopInteractionFuncs;

	std::list<std::string> ScriptDatas;

	NPCState State = NPCState::Idle;

	std::string AnimationName = "Idle";

	int2 MoveStartIndex = int2::Zero;
	float4 MoveStartPos = float4::Zero;

	int2 MoveEndIndex = int2::Zero;
	float4 MoveEndPos = float4::Zero;
	float MoveProgress = 0.0f;
	float MoveSpeed = 1.0f;

	int InputHandle = -1;
};