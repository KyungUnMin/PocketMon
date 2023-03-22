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

	//아마 외부에서 호출될 것 같다 추후에 수정
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);
};

