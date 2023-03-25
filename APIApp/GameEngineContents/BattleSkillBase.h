#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BattleMonsterBase;

class BattleSkillBase : public GameEngineActor
{
public:
	BattleSkillBase();
	virtual ~BattleSkillBase() = 0;

	BattleSkillBase(const BattleSkillBase& _Other) = delete;
	BattleSkillBase(BattleSkillBase&& _Other) noexcept = delete;
	BattleSkillBase& operator=(const BattleSkillBase& _Other) = delete;
	BattleSkillBase& operator=(const BattleSkillBase&& _Other) noexcept = delete;

	virtual void Action() = 0;

	virtual void Init(BattleMonsterBase* _Owner)
	{
		Owner = _Owner;
	}

protected:


private:
	BattleMonsterBase* Owner = nullptr;
};

