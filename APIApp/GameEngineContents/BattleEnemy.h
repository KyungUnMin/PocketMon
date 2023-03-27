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

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType, const std::vector<PokeDataBase>& _EnemyMonsters);

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

	inline void PushMonsterDatas(const std::vector<PokeDataBase>& _Monsters)
	{
		MonsterDatas = _Monsters;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	BattleMonsterEnemy* Monster = nullptr;
	BattleEnemyFSM* FsmPtr = nullptr;
	GameEngineRender* EnemyRender = nullptr;

	size_t CurIndex = 0;
	std::vector<PokeDataBase> MonsterDatas;

	


	void CreateGround(BattleFieldType _FieldType);
	void RenderCreate(BattleNpcType _NpcType);
};

