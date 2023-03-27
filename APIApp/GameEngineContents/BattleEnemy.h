#pragma once
#include "BattleTrainerBase.h"

enum class BattleNpcType;
class BattleMonsterEnemy;
class BattleEnemyFSM;
enum class BattleNpcType;
enum class BattleFieldType;
class PokeDataBase;
enum class PokeNumber;
class GameEngineRender;

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

	void CreateMonster(PokeNumber _Number);

	inline BattleMonsterEnemy* GetMonster()
	{
		return Monster;
	}

	PokeDataBase* GetMonsterDB();

	inline GameEngineRender* GetRender()
	{
		return EnemyRender;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	BattleMonsterEnemy* Monster = nullptr;
	BattleEnemyFSM* FsmPtr = nullptr;
	GameEngineRender* EnemyRender = nullptr;


	void CreateGround(BattleFieldType _FieldType);
	void RenderCreate(BattleNpcType _NpcType);
};

