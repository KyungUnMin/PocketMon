#pragma once
#include "BattleTrainerBase.h"

enum class BattleNpcType;
class BattleMonsterEnemy;
class BattleEnemyFSM;
enum class BattleNpcType;
enum class BattleFieldType;

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

	//Enemy FSM쪽에서 호출됨
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

	//아마 외부에서 호출될 것 같다 추후에 수정
	void CreateNpc(BattleFieldType _FieldType, BattleNpcType _NpcType);

};

