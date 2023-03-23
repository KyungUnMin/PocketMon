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

	//Battle FSM�ʿ��� ȣ���(WildTalk)
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

	//�Ƹ� �ܺο��� ȣ��� �� ���� ���Ŀ� ����
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);

	void Update_Move();
	
};

