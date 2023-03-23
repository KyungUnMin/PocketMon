#pragma once
#include "BattleTrainerBase.h"

enum class BattleNpcType;
class BattleMonsterEnemy;

class BattleEnemy : public BattleTrainerBase
{
public:
	static BattleEnemy* EnemyPtr;

	BattleEnemy();
	~BattleEnemy() override;

	BattleEnemy(const BattleEnemy& _Other) = delete;
	BattleEnemy(BattleEnemy&& _Other) noexcept = delete;
	BattleEnemy& operator=(const BattleEnemy& _Other) = delete;
	BattleEnemy& operator=(const BattleEnemy&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType);

	//Battle FSM쪽에서 호출됨(WildTalk)
	void CreateWildMonster(BattleFieldType _FieldType);

	inline BattleMonsterEnemy* GetMonster()
	{
		return Monster;
	}


protected:
	void Update(float _DeltaTime) override;

private:
	enum class State
	{
		Move,
		Idle,

	};

	BattleMonsterEnemy* Monster = nullptr;

	State CurState = State::Move;
	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;


	void CreateGround(BattleFieldType _FieldType);

	//아마 외부에서 호출될 것 같다 추후에 수정
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);

	void Update_Move();
	
};

