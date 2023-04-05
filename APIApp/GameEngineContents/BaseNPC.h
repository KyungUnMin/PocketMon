#pragma once
#include <string>
#include <list>
#include <map>
#include <functional>
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"
#include "PokeDataBase.h"
#include "TrainerPokemon.h"

enum class LookDir;
enum class BattleNpcType;
class GameEngineRender;
class BaseNPC : public GameEngineActor
{
public:
	enum class InteractionTriggerType
	{
		None,
		Talk,
		Shop,
		Look
	};
protected:
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

	virtual void InitNPC(const std::string_view& _Name, const std::string_view& _ImageName, BattleNpcType _Type);
	void AddNPC(const std::string_view& _CityName, int2 _Index, bool _IsAdd = true);
	void AddScript(const std::string_view& _Script, int _Key = 0);

	// NPC �̵� ���� �߰�
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

	inline void SetInteractionTrigger(InteractionTriggerType _TriggerType)
	{
		TriggerType = _TriggerType;
	}

	inline void SetInteractionIndex(const int2& _Index)
	{
		InteractionIndex = _Index;
	}	
	
	inline void SetInteractionDir(LookDir _CheckDir)
	{
		InteractionDir = _CheckDir;
	}

	inline void SetLookDis(int _Dis)
	{
		LookDistance = _Dis;
	}

	inline void LoopBattle()
	{
		IsLoopBattle = true;
	}

	void SetScriptKey(int _Key);
	
	void AddPokeData(int _Index, int _Level);
	void AddPokeData(PokeDataBase _Data);


	// ��ȣ�ۿ� ����
	void PlayInteraction();
	// ��ȣ�ۿ� �̺�Ʈ �߰�
	void AddInteractionFunc(std::function<void()> _Func, bool _IsLoop = true);

	// Npc ȸ�� �Լ�
	void Look(LookDir _Dir);
	void Look(const float4& _TargetPos);
	void Look(const float4& _NpcPos, const float4& _TargetPos);
	void Look(const int2& _NpcIndex, const int2& _TargetPos);

	static LookDir GetDir(const int2& _ViewIndex, const int2& _TargetIndex);
	static LookDir TurnLeftDir(LookDir _Dir);
	static LookDir TurnRightDir(LookDir _Dir);

protected:
	LookDir Dir;

	// ������ ���� ����
	GameEngineRender* NPCRender = nullptr;
	std::string AnimationName = "Idle";

	// ���� �� ����
	std::string CityName;
	std::string Name;

	// Npc ����
	NPCState State = NPCState::Idle;
	BattleNpcType Type;

	// Npc ���� ����
	std::list<float4> MovePoints;

	int2 MoveStartIndex = int2::Zero;
	float4 MoveStartPos = float4::Zero;

	int2 MoveEndIndex = int2::Zero;
	float4 MoveEndPos = float4::Zero;
	float MoveProgress = 0.0f;
	float MoveSpeed = 5.0f;
	float MoveDistance = 1.0f;

	// ��ȣ�ۿ� ����
	bool IsBattleEnd = false;
	bool IsLoopBattle = false;
	
	int InputHandle = -1;
	InteractionTriggerType TriggerType = InteractionTriggerType::None;

	LookDir InteractionDir;
	int2 InteractionIndex = int2::Zero;
	int LookDistance = 6;


	std::vector<std::function<void()>> InteractionFuncs;
	std::vector<std::function<void()>> LoopInteractionFuncs;

	// ��� ����
	int ScriptKey = 0;
	std::map<int, std::list<std::string>> ScriptDatas;


	// ���ϸ� ������
	TrainerPokemon PokemonDatas;

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


	void PlayAnimation();
	void ChangeState(NPCState _State);

	bool CheckInteractionTrigger() const;

private:


};