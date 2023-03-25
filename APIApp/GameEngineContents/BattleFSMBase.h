#pragma once
#include <vector>

class BattleStateBase;
enum class BattleFieldType;
enum class BattleNpcType;

class BattleFSMBase
{
public:
	BattleFSMBase();
	virtual ~BattleFSMBase() = 0;

	BattleFSMBase(const BattleFSMBase& _Other) = delete;
	BattleFSMBase(BattleFSMBase&& _Other) noexcept = delete;
	BattleFSMBase& operator=(const BattleFSMBase& _Other) = delete;
	BattleFSMBase& operator=(const BattleFSMBase&& _Other) noexcept = delete;

	virtual void Init(BattleFieldType _FieldType, BattleNpcType _NpcType) = 0;

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

protected:
	template <typename EnumType>
	void ResizeStates(EnumType _Count)
	{
		ResizeStates(static_cast<size_t>(_Count));
	}

	void SetState(size_t _Index, BattleStateBase* _State);

private:
	std::vector<BattleStateBase*> AllState;
	size_t CurIndex = 999999;

	void ChangeState(size_t _NextIndex);

	inline void ResizeStates(size_t _Size)
	{
		AllState.resize(_Size);
	}
};

