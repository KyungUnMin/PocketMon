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
	void CreateWildMonster(BattleFieldType _FieldType);

	inline BattleMonsterEnemy* GetMonster()
	{
		return Monster;
	}


protected:

private:
	BattleMonsterEnemy* Monster = nullptr;

	void CreateGround(BattleFieldType _FieldType);

	//�Ƹ� �ܺο��� ȣ��� �� ���� ���Ŀ� ����
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);
};

