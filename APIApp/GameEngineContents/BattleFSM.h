#pragma once
#include <vector>
#include <memory>

enum class BattleStateType
{
	WildTalk,
	PlayerTurn,
	EnemyTurn,
	ThrowMonsterBall,

	COUNT,
};

class BattleStateBase;
class GameEngineLevel;
enum class BattleFieldType;
enum class BattleNpcType;

class BattleFSM
{
public:
	BattleFSM();
	~BattleFSM();

	BattleFSM(const BattleFSM& _Other) = delete;
	BattleFSM(BattleFSM&& _Other) noexcept = delete;
	BattleFSM& operator=(const BattleFSM& _Other) = delete;
	BattleFSM& operator=(const BattleFSM&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType);
	void ChangeState(BattleStateType _Type);
	void Update(float _DeltaTime);
	
	inline BattleStateType GetNowState()
	{
		return CurStateType;
	}

protected:

private:
	std::vector<BattleStateBase*> AllState;
	BattleStateType CurStateType = BattleStateType::COUNT;

	void CreateState(BattleStateType _Type);
};

