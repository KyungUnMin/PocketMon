#pragma once
#include "BattleMonsterBase.h"

class BattleEnemyMonsterFSM;
class Battle_HpUIHandlerBase;

class BattleMonsterEnemy : public BattleMonsterBase
{
public:
	//LockState와 MonsterBall OpenState에서 사용
	static const float LockTime;

	BattleMonsterEnemy();
	~BattleMonsterEnemy() override;

	BattleMonsterEnemy(const BattleMonsterEnemy& _Other) = delete;
	BattleMonsterEnemy(BattleMonsterEnemy&& _Other) noexcept = delete;
	BattleMonsterEnemy& operator=(const BattleMonsterEnemy& _Other) = delete;
	BattleMonsterEnemy& operator=(const BattleMonsterEnemy&& _Other) noexcept = delete;

	void Init(PokeDataBase* _MonsterDB, bool _IsWildMonster = false);

	inline BattleEnemyMonsterFSM* GetFSM()
	{
		return FsmPtr;
	}

	inline GameEngineRender* GetRender() override
	{
		return MonsterRender;
	}

	inline GameEngineRender* GetEffectRender()
	{
		return EffectRender;
	}

	Battle_HpUIHandlerBase* GetHpUI() override
	{
		return UiHandler;
	}

	void CreateHpUI() override;

	void DamageOnIU(int _Value) override;

	void Lock();

	void UnLock();

	void KillMonster();

protected:
	void Update(float _DeltaTime) override;

private:
	bool IsWildMonster = false;
	BattleEnemyMonsterFSM* FsmPtr = nullptr;

	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* EffectRender = nullptr;
	Battle_HpUIHandlerBase* UiHandler = nullptr;

	void RenderCreate();
};