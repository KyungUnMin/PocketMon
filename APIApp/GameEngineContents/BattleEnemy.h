#pragma once
#include "BattleTrainerBase.h"

enum class BattleNpcType;
class BattleMonsterEnemy;
class BattleEnemyFSM;
enum class BattleNpcType;
enum class BattleFieldType;
class PokeDataBase;

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

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType);

	//Enemy FSM�ʿ��� ȣ���
	void CreateWildMonster(BattleFieldType _FieldType);

	inline BattleMonsterEnemy* GetMonster()
	{
		return Monster;
	}

	PokeDataBase* GetMonsterDB();

protected:
	void Update(float _DeltaTime) override;

private:
	BattleMonsterEnemy* Monster = nullptr;
	BattleEnemyFSM* FsmPtr = nullptr;


	void CreateGround(BattleFieldType _FieldType);

	//�Ƹ� �ܺο��� ȣ��� �� ���� ���Ŀ� ����
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);

};

