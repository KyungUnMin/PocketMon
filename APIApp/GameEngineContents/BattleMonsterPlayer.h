#pragma once
#include "BattleMonsterBase.h"

class GameEngineRender;
class BattlePlayerMonsterFSM;

class BattleMonsterPlayer : public BattleMonsterBase
{
public:
	BattleMonsterPlayer();
	~BattleMonsterPlayer() override;

	BattleMonsterPlayer(const BattleMonsterPlayer& _Other) = delete;
	BattleMonsterPlayer(BattleMonsterPlayer&& _Other) noexcept = delete;
	BattleMonsterPlayer& operator=(const BattleMonsterPlayer& _Other) = delete;
	BattleMonsterPlayer& operator=(const BattleMonsterPlayer&& _Other) noexcept = delete;

	void Init(PokeNumber _MonsterType);

	inline GameEngineRender* GetRender() override
	{
		return RenderPtr;
	}

	inline BattlePlayerMonsterFSM* GetFSM()
	{
		return FsmPtr;
	}

	void KillMonster();

	Battle_HpUIHandlerBase* GetHpUI() override
	{
		return UiHandler;
	}

	void CreateHpUI() override;

	void DamageOnIU(int _Value) override;

protected:
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* RenderPtr = nullptr;
	BattlePlayerMonsterFSM* FsmPtr = nullptr;
	Battle_HpUIHandlerBase* UiHandler = nullptr;

	void RenderCreate();
};

