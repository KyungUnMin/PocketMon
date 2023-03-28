#pragma once
#include <vector>
#include <GameEngineBase/GameEngineDebug.h>

class BattleStateBase;
enum class BattleFieldType;
enum class BattleNpcType;
class GameEngineActor;

class BattleFSMBase
{
public:
	BattleFSMBase(GameEngineActor* _Owner);
	virtual ~BattleFSMBase() = 0;

	BattleFSMBase(const BattleFSMBase& _Other) = delete;
	BattleFSMBase(BattleFSMBase&& _Other) noexcept = delete;
	BattleFSMBase& operator=(const BattleFSMBase& _Other) = delete;
	BattleFSMBase& operator=(const BattleFSMBase&& _Other) noexcept = delete;


	template <typename EnumType>
	void ChangeState(EnumType _Type)
	{
		ChangeState(static_cast<size_t>(_Type));
	}

	template <typename EnumType>
	EnumType GetNowState()
	{
		return static_cast<EnumType>(CurIndex);
	}

	void Update(float _DeltaTime);

	virtual void Init(BattleFieldType _FieldType, BattleNpcType _NpcType);


	GameEngineActor* GetOwner();

protected:
	template <typename EnumType>
	void ResizeStates(EnumType _Count)
	{
		ResizeStates(static_cast<size_t>(_Count));
	}

	template <typename StateType, typename EnumType>
	void CreateState(EnumType _Index)
	{
		BattleStateBase* NewState = new StateType;
		InitState(NewState, static_cast<size_t>(_Index));
	}

private:
	std::vector<BattleStateBase*> AllState;
	size_t CurIndex = 999999;
	GameEngineActor* Owner = nullptr;

	void ChangeState(size_t _NextIndex);

	inline void ResizeStates(size_t _Size)
	{
		AllState.resize(_Size);
	}

	void InitState(BattleStateBase* _State, size_t _Index);
};

