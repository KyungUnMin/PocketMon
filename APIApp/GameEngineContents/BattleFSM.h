#pragma once
#include <map>
#include <memory>

enum class BattleStateType
{
	WildTalk,
	PlayerTurn,
	EnemyTurn,
	ThrowMonsterBall,

	UNKNOWN,
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
	
	BattleStateType GetNowState();

protected:

private:
	std::map<BattleStateType, std::shared_ptr<BattleStateBase>> AllState;
	std::shared_ptr<BattleStateBase> CurState = nullptr;

	void CreateState(BattleStateType _Type);
	void WildBattleInit(BattleFieldType _FieldType);
};

