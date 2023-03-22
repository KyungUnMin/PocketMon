#pragma once
#include "BattleMonsterBase.h"

enum class PokeNumber;
class GameEngineRender;

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

protected:
	void Update(float _DeltaTime) override;

private:
	enum class State
	{
		Appear,
		Ready,
	};

	State CurState = State::Appear;

	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* AppearRender = nullptr;


	void RenderCreate();
	void Update_Appear();
	

};

