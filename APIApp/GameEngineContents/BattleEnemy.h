#pragma once
#include "BattleTrainerBase.h"

enum class BattleNpcType;
class BattleMonsterBase;

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

	inline BattleMonsterBase* GetMonster()
	{
		return Monster;
	}

protected:

private:
	BattleMonsterBase* Monster = nullptr;

	void CreateGround(BattleFieldType _FieldType);

	//�Ƹ� �ܺο��� ȣ��� �� ���� ���Ŀ� ����
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);
	void CreateWildMonster(BattleFieldType _FieldType);
};

