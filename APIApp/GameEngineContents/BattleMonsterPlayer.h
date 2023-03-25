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

	inline GameEngineRender* GetRender()
	{
		return RenderPtr;
	}

	inline BattlePlayerMonsterFSM* GetFSM()
	{
		return FsmPtr;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* RenderPtr = nullptr;
	BattlePlayerMonsterFSM* FsmPtr = nullptr;

	void RenderCreate();
};

